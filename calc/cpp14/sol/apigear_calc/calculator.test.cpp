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
#include "catch2/catch.hpp"
#include "calculator.h"

TEST_CASE("Testing Calculator", "[Calculator]"){
    Calculator testCalculator;
    // setup your test
    SECTION("Test operation add") {
        testCalculator.add(11);
        REQUIRE( testCalculator.total() == 11 );
    }
    SECTION("Test operation substract") {
        testCalculator.add(11);
        testCalculator.substract(12);
        REQUIRE( testCalculator.total() == -1 );
    }
    SECTION("Test operation multiply") {
        testCalculator.setTotal(-1);
        testCalculator.multiply(20);
        REQUIRE( testCalculator.total() == -20 );
    }
    SECTION("Test operation divide") {
        testCalculator.setTotal(-20);
        testCalculator.divide(-10);
        REQUIRE( testCalculator.total() == 2 );
    }
    SECTION("Test operation clear") {
        testCalculator.setTotal(23);
        testCalculator.clear();
        REQUIRE( testCalculator.total() == 0 );
    }
    SECTION("Test property total") {
        testCalculator.setTotal(23);
        REQUIRE( testCalculator.total() == 23 );
    }
}
