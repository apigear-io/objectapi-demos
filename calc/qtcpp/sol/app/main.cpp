#include <QtCore>
#include "console.h"


int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
    Console console;
    console.run();
    QObject::connect(&console, &Console::quit, &app, &QCoreApplication::quit);
    return app.exec();
}
