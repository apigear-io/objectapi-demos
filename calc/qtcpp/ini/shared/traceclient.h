#pragma once

#include <QtCore>
#include <QtWebSockets>

class TraceClient : public QObject
{
    Q_OBJECT
public:
    explicit TraceClient(QObject *parent = nullptr);
    static TraceClient* instance();
    void trace(const QString &eventKind, const QString &symbol, const QVariantMap& fields);
    void call(const QString &symbol, const QVariantMap &fields);
    void signal(const QString &symbol, const QVariantMap &fields);
    void state(const QString &symbol, const QVariantMap &fields);

private:
    void process();
    void doProcess();

private:
    static TraceClient* s_instance;
    QQueue<QJsonObject> m_queue;
    QUrl m_traceUrl;
    QWebSocket *m_socket;
    QTimer *m_retryTimer;
};
