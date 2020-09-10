#include "factory.h"
#include "dice.h"
#include "random.h"

AbstractFactory *Factory::s_instance = nullptr;

Factory::Factory(QObject *parent)
    : AbstractFactory(parent)
{
}

void Factory::set(AbstractFactory *instance)
{
    if(s_instance) {
        qFatal("Can not set factory when factory already set");
    }
    s_instance = instance;
}

AbstractFactory * Factory::get()
{
    if(s_instance) {
        return s_instance;
    }
    s_instance = new Factory(QCoreApplication::instance());
    return s_instance;
}

AbstractDice* Factory::createDice(QObject *parent)
{
    return new Dice(parent);
}

AbstractRandom* Factory::createRandom(QObject *parent)
{
    return new Random(parent);
}
