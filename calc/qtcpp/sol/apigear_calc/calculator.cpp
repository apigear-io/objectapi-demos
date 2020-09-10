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


#include "calculator.h"

#include "tracer.h"
#include <QtQml>

Calculator::Calculator(QObject *parent)
    : AbstractCalculator(parent)
    , m_total(0)
{
}

Calculator::~Calculator()
{
}

void Calculator::setTotal(int total)
{
    if (m_total != total) {
        m_total = total;
        emit totalChanged(total);
        CalculatorTracer::capture_state(this);
    }
}

int Calculator::total() const
{
    return m_total;
}

void Calculator::add(int a)
{
    qDebug() << Q_FUNC_INFO;
    CalculatorTracer::trace_add(a);
    setTotal(total() + a);
}

void Calculator::substract(int a)
{
    qDebug() << Q_FUNC_INFO;
    CalculatorTracer::trace_substract(a);
    setTotal(total() - a);
}

void Calculator::multiply(int a)
{
    qDebug() << Q_FUNC_INFO;
    CalculatorTracer::trace_multiply(a);
    setTotal(total() * a);
}

void Calculator::divide(int a)
{
    qDebug() << Q_FUNC_INFO;
    CalculatorTracer::trace_divide(a);
    setTotal(total() / a);
}

void Calculator::clear()
{
    qDebug() << Q_FUNC_INFO;
    CalculatorTracer::trace_clear();
    setTotal(0);
}
