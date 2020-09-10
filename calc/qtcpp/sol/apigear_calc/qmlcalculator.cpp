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


#include "qmlcalculator.h"
#include "factory.h"

#include <QtQml>

QmlCalculator::QmlCalculator(QObject *parent)
    : AbstractCalculator(parent)
{
    m_obj = Factory::get()->createCalculator(this);
    connect(m_obj, &AbstractCalculator::totalChanged, this, &QmlCalculator::totalChanged);
}

QmlCalculator::~QmlCalculator()
{
}

int QmlCalculator::total() const
{
    return m_obj->total();
}

void QmlCalculator::setTotal(int total)
{
    return m_obj->setTotal(total);
}

void QmlCalculator::add(int a)
{
	return m_obj->add(a);
}

void QmlCalculator::substract(int a)
{
	return m_obj->substract(a);
}

void QmlCalculator::multiply(int a)
{
	return m_obj->multiply(a);
}

void QmlCalculator::divide(int a)
{
	return m_obj->divide(a);
}

void QmlCalculator::clear()
{
	return m_obj->clear();
}
