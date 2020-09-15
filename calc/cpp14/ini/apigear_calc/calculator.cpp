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
#include "apig/apigear_calc.trace.h"
/**
   \brief 
*/
Calculator::Calculator()
    : CalculatorBase()
{
    m_total = 0;
}
Calculator::~Calculator()
{
}
void Calculator::setTotal(int total)
{
    if (m_total != total) {
        m_total = total;
        // CalculatorTracer::capture_state(this);
    }
}

int Calculator::total() const
{
    return m_total;
}
/**
   \brief 
*/
void Calculator::add(int a)
{
    (void) a;
    // do business logic here
    // CalculatorTracer::trace_add(a);
    return ;
}
/**
   \brief 
*/
void Calculator::substract(int a)
{
    (void) a;
    // do business logic here
    // CalculatorTracer::trace_substract(a);
    return ;
}
/**
   \brief 
*/
void Calculator::multiply(int a)
{
    (void) a;
    // do business logic here
    // CalculatorTracer::trace_multiply(a);
    return ;
}
/**
   \brief 
*/
void Calculator::divide(int a)
{
    (void) a;
    // do business logic here
    // CalculatorTracer::trace_divide(a);
    return ;
}
/**
   \brief 
*/
void Calculator::clear()
{
    // do business logic here
    // CalculatorTracer::trace_clear();
    return ;
}
