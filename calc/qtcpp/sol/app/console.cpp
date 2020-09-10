#include "console.h"
#include "calculator.h"

Console::Console(QObject *parent)
    : QObject(parent)
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    m_calc = new Calculator(this);
}


void Console::run()
{
    qDebug() << Q_FUNC_INFO;
    std::cout << "total: " << m_calc->total() << std::endl;
    std::cout << "$ " << std::flush;
    connect(m_notifier, &QSocketNotifier::activated, this, &Console::process);
}

void Console::process()
{
    qDebug() << Q_FUNC_INFO;
    QTextStream qin(stdin);
    while(true) {
        std::cout << "total: " << m_calc->total() << std::endl;
        std::cout << "$ " << std::flush;
        QString line = qin.readLine();
        QStringList args = line.simplified().split(" ");
        QString action;
        if(args.count() >= 1) {
            action = args[0];
        }
        int num = 0;
        bool numOk = false;
        if(args.count() == 2) {
            num = args[1].toInt(&numOk);
        }
        if (std::cin.eof() || action == "exit") {
            emit quit();
            break;
        } else if (action == "add" && numOk) {
            m_calc->add(num);
        } else if (action == "mul" && numOk) {
            m_calc->multiply(num);
        } else if (action == "sub" && numOk) {
            m_calc->substract(num);
        } else if (action == "div" && numOk) {
            m_calc->divide(num);
        } else if (action == "clear" && numOk) {
            m_calc->clear();
        }
    }
}
