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

#include "api.h"

class Dice : public AbstractDice
{
    Q_OBJECT
public:
    explicit Dice(AbstractRandom* rand, QObject *parent = nullptr);
    virtual ~Dice() override;
    int value() const override;
    void setValue(int value) override;
    void toss() override;

private:
    int m_value;
    AbstractRandom *m_rand;
};
