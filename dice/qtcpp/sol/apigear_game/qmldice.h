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

#include "dice.h"

class QmlDice : public AbstractDice
{
    Q_OBJECT
    Q_PROPERTY(int value READ value NOTIFY valueChanged)
public:
    explicit QmlDice(QObject *parent = nullptr);
    virtual ~QmlDice() override;
    int value() const override;
    void setValue(int value) override;
    Q_INVOKABLE void toss() override;

Q_SIGNALS:
    void valueChanged(int value);
private:
	AbstractDice *m_obj;
};
