/**
Tracer
Copyright (C) 2020 ApiGear UG
*/
#include "tracer.h"
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Stringifier.h>
#include <Poco/Dynamic/Var.h>
#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <iostream>

Tracer* Tracer::s_instance(nullptr);

Tracer::Tracer()
{
    if(s_instance) {
        std::cerr << "Tracer can only be instantiated once";
    }
    std::string gatewayUrl = "ws://localhost:8152/ws";
    m_traceUrl = Poco::URI(gatewayUrl);
    m_socket = nullptr;
    m_task = new Poco::Util::TimerTaskAdapter<Tracer>(*this, &Tracer::doProcess);
    m_retryTimer.schedule(m_task, 10, 5000);
}

Tracer *Tracer::instance()
{
    if(!s_instance) {
        s_instance = new Tracer();
    }
    return s_instance;
}

void Tracer::connect()
{
    Poco::Net::HTTPClientSession session(m_traceUrl.getHost(), m_traceUrl.getPort());
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
    request.setKeepAlive(true);
    request.setContentType("application/json");
    Poco::Net::HTTPResponse response;

    if(!m_socket) {
        try {
            m_socket = new Poco::Net::WebSocket(session, request, response);
        } catch (std::exception &e) {
            m_socket = nullptr;
            std::cerr << "Exception " << e.what() << std::endl;
        }
    }
}

void Tracer::trace(const std::string &eventType, const std::string &symbol, const Poco::JSON::Object &fields)
{
    Poco::JSON::Object obj(true);
    obj.set("type", eventType);
    obj.set("symbol", symbol);
    obj.set("fields", fields);

    m_queueMutex.lock(100);
    m_queue.push(obj);
    m_queueMutex.unlock();
    process();
}

void Tracer::call(const std::string &symbol,const Poco::JSON::Object &fields)
{
    trace("call", symbol, fields);
}

void Tracer::signal(const std::string &symbol,const Poco::JSON::Object &fields)
{
    trace("signal", symbol, fields);
}

void Tracer::state(const std::string &symbol,const Poco::JSON::Object &fields)
{
    trace("state", symbol, fields);
}

void Tracer::process()
{
    m_task->cancel();
    m_task = new Poco::Util::TimerTaskAdapter<Tracer>(*this, &Tracer::doProcess);
    m_retryTimer.schedule(m_task, 10, 5000);
}

void Tracer::doProcess(Poco::Util::TimerTask& task)
{
    if (!m_socket) {
        m_task->cancel();
        connect();
        m_task = new Poco::Util::TimerTaskAdapter<Tracer>(*this, &Tracer::doProcess);
        m_retryTimer.schedule(m_task, 5000, 5000);
        return;
    }

    m_queueMutex.lock(100);
    while (!m_queue.empty()) {
        const Poco::JSON::Object obj(m_queue.front());

        std::ostringstream os;
        obj.stringify(os, 2);
        os << "\n\0";
        std::clog << "send trace: " << os.str();

        const char* testStr = os.str().c_str();
        try {
            if(m_socket) {
                m_socket->sendFrame(testStr,strlen(testStr));
            }
            else
            {
                return;
            }
        } catch (std::exception &e) {
            std::cerr << "Exception " << e.what() << std::endl;
            return;
        }
        m_queue.pop();
    }
    m_queueMutex.unlock();
}
