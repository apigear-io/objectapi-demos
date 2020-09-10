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

#include "calculator.h"

class QmlCalculator : public AbstractCalculator
{
    Q_OBJECT
    Q_PROPERTY(int total READ total NOTIFY totalChanged)
public:
    explicit QmlCalculator(QObject *parent = nullptr);
    virtual ~QmlCalculator() override;
    int total() const override;
    void setTotal(int total) override;
    Q_INVOKABLE void add(int a) override;
    Q_INVOKABLE void substract(int a) override;
    Q_INVOKABLE void multiply(int a) override;
    Q_INVOKABLE void divide(int a) override;
    Q_INVOKABLE void clear() override;

Q_SIGNALS:
    void totalChanged(int total);
private:
	AbstractCalculator *m_obj;
};
