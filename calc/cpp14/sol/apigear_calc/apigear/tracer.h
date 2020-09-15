/**
Tracer
Copyright (C) 2020 ApiGear UG
*/
#include <string>
#include <map>
#include <queue>
#include <Poco/URI.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/JSON/Object.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Mutex.h>

class Tracer
{
public:
    static Tracer* instance();
    Tracer(Tracer const&) = delete;
    void operator=(Tracer const&) = delete;

    void call(const std::string &symbol, const Poco::JSON::Object &fields);
    void signal(const std::string &symbol, const Poco::JSON::Object &fields);
    void state(const std::string &symbol, const Poco::JSON::Object &fields);

private:
    explicit Tracer();

    void connect();
    void doProcess(Poco::Util::TimerTask& task);
    void trace(const std::string &eventKind, const std::string &symbol, const Poco::JSON::Object &fields);
    void process();

private:
    static Tracer* s_instance;
    std::queue<Poco::JSON::Object> m_queue;
    Poco::Mutex m_queueMutex;
    Poco::URI m_traceUrl;
    Poco::Net::WebSocket *m_socket;
    Poco::Util::Timer m_retryTimer;
    Poco::Util::TimerTask::Ptr m_task;
};
