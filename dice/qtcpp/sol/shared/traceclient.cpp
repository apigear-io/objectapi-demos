#include "traceclient.h"

TraceClient* TraceClient::s_instance(nullptr);

TraceClient::TraceClient(QObject *parent)
    : QObject(parent)
    , m_socket(nullptr)
{
    if(s_instance) {
        qFatal("TraceClient can only be instantiated once");
    }
    QString gatewayUrl = qEnvironmentVariable("APIGEAR_GATEWAY", "ws://localhost:8152/ws");
    m_traceUrl = QUrl(gatewayUrl);
    m_socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    connect(m_socket, &QWebSocket::connected, this, &TraceClient::process);
    m_retryTimer = new QTimer(this);
    m_retryTimer->setInterval(5000);
    process();
}

TraceClient *TraceClient::instance()
{
    if(!s_instance) {
        s_instance = new TraceClient(QCoreApplication::instance());
    }
    return s_instance;
}

void TraceClient::trace(const QString &eventType, const QString &symbol, const QVariantMap &fields)
{
    QJsonObject obj{
        {"type", eventType},
        {"symbol", symbol},
        {"fields", QJsonObject::fromVariantMap(fields)},
    };
    m_queue.enqueue(obj);
    process();
}

void TraceClient::call(const QString &symbol,const QVariantMap &fields)
{
    trace("call", symbol, fields);
}

void TraceClient::signal(const QString &symbol, const QVariantMap &fields)
{
    trace("signal", symbol, fields);
}

void TraceClient::state(const QString &symbol, const QVariantMap &fields)
{
    trace("state", symbol, fields);
}

void TraceClient::process()
{
    QTimer::singleShot(10, this, &TraceClient::doProcess);
}

void TraceClient::doProcess()
{
    if (m_retryTimer->isActive()) {
        return;
    }
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->open(m_traceUrl);
        m_retryTimer->start();
    }
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        m_retryTimer->stop();
        return;
    }
    while (!m_queue.isEmpty()) {
        const QJsonObject obj = m_queue.dequeue();
        const QByteArray data = QJsonDocument(obj).toJson();
        qDebug() << "send trace: " << obj;
        m_socket->sendBinaryMessage(data);
    }
}
