#pragma once

#include <QtCore>

#include "api/api.h"

class Factory : public AbstractFactory
{
private:
    Factory(QObject *parent = nullptr);
public:
    static void set(AbstractFactory *instance);
    static AbstractFactory *get();
    AbstractCalculator* createCalculator(QObject *parent) override;
private:
    static AbstractFactory *s_instance;
};
