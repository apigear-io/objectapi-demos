#pragma once

#include <QtCore>

#include "api.h"

class Factory : public AbstractFactory
{
private:
    Factory(QObject *parent = nullptr);
public:
    static void set(AbstractFactory *instance);
    static AbstractFactory *get();
    AbstractDice* createDice(QObject *parent) override;
    AbstractRandom* createRandom(QObject *parent) override;
private:
    static AbstractFactory *s_instance;
};
