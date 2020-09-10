/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <QtCore>

class Dice;

class Random;

// ********************************************************************
// AbstractDice pure interface
// ********************************************************************


class AbstractDice : public QObject {
    Q_OBJECT
public:
    AbstractDice(QObject * parent=nullptr);
    virtual void setValue(int value) = 0;
    virtual int value() const = 0;
    virtual void toss() = 0;
Q_SIGNALS:
    void valueChanged(int value);
};

// ********************************************************************
// AbstractRandom pure interface
// ********************************************************************


class AbstractRandom : public QObject {
    Q_OBJECT
public:
    AbstractRandom(QObject * parent=nullptr);
    virtual int generate(int min, int max) = 0;
Q_SIGNALS:
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class AbstractFactory : public QObject
{
    Q_OBJECT
public:
    AbstractFactory(QObject *parent=nullptr);
    virtual AbstractDice* createDice(QObject *parent) = 0;
    virtual AbstractRandom* createRandom(QObject *parent) = 0;
};
