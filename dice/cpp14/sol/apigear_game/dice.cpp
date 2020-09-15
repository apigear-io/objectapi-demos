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
#include "dice.h"
#include "apig/apigear_game.trace.h"
#include "random.h"
/**
   \brief 
*/
Dice::Dice()
    : DiceBase()
{
    m_value = 0;
}
Dice::~Dice()
{
}
void Dice::setValue(int value)
{
    if (m_value != value) {
        m_value = value;
        // DiceTracer::capture_state(this);
    }
}

int Dice::value() const
{
    return m_value;
}
/**
   \brief 
*/
void Dice::toss()
{
    Random randGenerator;
    setValue(randGenerator.generate(1, 6));
    // DiceTracer::trace_toss();
    return ;
}
