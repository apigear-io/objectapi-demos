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
        // Do implement test here
        testCalculator.add(0);
    }
    SECTION("Test operation substract") {
        // Do implement test here
        testCalculator.substract(0);
    }
    SECTION("Test operation multiply") {
        // Do implement test here
        testCalculator.multiply(0);
    }
    SECTION("Test operation divide") {
        // Do implement test here
        testCalculator.divide(0);
    }
    SECTION("Test operation clear") {
        // Do implement test here
        testCalculator.clear();
    }
    SECTION("Test property total") {
        // Do implement test here
        testCalculator.setTotal(0);
    }
}
