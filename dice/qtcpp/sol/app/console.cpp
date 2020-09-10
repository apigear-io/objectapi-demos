#include "console.h"
#include "dice.h"
#include "random.h"

Console::Console(QObject *parent)
    : QObject(parent)
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);

    m_rand = new Random(this);
    m_dice = new Dice(m_rand, this);
}


void Console::run()
{
    qDebug() << Q_FUNC_INFO;
    std::cout << "value: " << m_dice->value() << std::endl;
    std::cout << "$ " << std::flush;
    connect(m_notifier, &QSocketNotifier::activated, this, &Console::process);
}

void Console::process()
{
    qDebug() << Q_FUNC_INFO;
    QTextStream qin(stdin);
    while(true) {
        std::cout << "total: " << m_dice->value() << std::endl;
        std::cout << "$ " << std::flush;
        QString line = qin.readLine();
        QStringList args = line.simplified().split(" ");
        QString action;
        if(args.count() >= 1) {
            action = args[0];
        }
        if (std::cin.eof() || action == "exit") {
            emit quit();
            break;
        } else if (action == "toss") {
            m_dice->toss();
        }
    }
}
