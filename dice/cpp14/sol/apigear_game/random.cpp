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
#include "random.h"
#include "apig/apigear_game.trace.h"
#include <random>

/**
   \brief 
*/
Random::Random()
    : RandomBase()
{
}
Random::~Random()
{
}
/**
   \brief 
*/
int Random::generate(int min, int max)
{
    // Seed with a real random value, if available
    std::random_device randomDevice;
 
    // Choose a random mean between min and max
    std::default_random_engine e1(randomDevice());
    std::uniform_int_distribution<int> uniform_dist(min, max);
    int rand = uniform_dist(e1);
    // RandomTracer::trace_generate(min,max);
    return rand;
}
