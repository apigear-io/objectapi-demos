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
#include <cinttypes>
#include <string>
#include <list>

#pragma once
class DiceBase;
class RandomBase;

// ********************************************************************
// interface DiceBase
// ********************************************************************
class DiceBase
{
public:
    DiceBase(){};
    virtual ~DiceBase(){};
// methods
    virtual void toss() = 0;

// property methods
    virtual void setValue(int value) = 0;
    virtual int value() const = 0;
};

// ********************************************************************
// interface RandomBase
// ********************************************************************
class RandomBase
{
public:
    RandomBase(){};
    virtual ~RandomBase(){};
// methods
    virtual int generate(int min, int max) = 0;

// property methods
};
