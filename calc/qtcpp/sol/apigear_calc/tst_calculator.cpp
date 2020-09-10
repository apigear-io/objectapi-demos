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
#include "tst_calculator.h"
#include "calculator.h"

/**
 *  will be called before the first test function is executed.
*/
void TestCalculator::initTestCase(){

}

/**
 *  will be called to create a global test data table.
*/
void TestCalculator::initTestCase_data(){

}

/**
 *  will be called after the last test function was executed.
*/
void TestCalculator::cleanupTestCase(){

}

/**
 *  will be called before each test function is executed.
*/
void TestCalculator::init(){

}

/**
 *  will be called after every test function.
*/
void TestCalculator::cleanup(){

}
/**
 *  Test operation add
*/
void TestCalculator::add(){
    Calculator calc;
    QCOMPARE(calc.total(), 0);
    calc.add(2);
    QCOMPARE(calc.total(), 2);
}
/**
 *  Test operation substract
*/
void TestCalculator::substract(){
    Calculator calc;
    QCOMPARE(calc.total(), 0);
    calc.substract(2);
    QCOMPARE(calc.total(), -2);
}
/**
 *  Test operation multiply
*/
void TestCalculator::multiply(){
    Calculator calc;
    QCOMPARE(calc.total(), 0);
    calc.add(2);
    calc.multiply(2);
    QCOMPARE(calc.total(), 4);
}
/**
 *  Test operation divide
*/
void TestCalculator::divide(){
    Calculator calc;
    QCOMPARE(calc.total(), 0);
    calc.add(4);
    calc.divide(2);
    QCOMPARE(calc.total(), 2);
}
/**
 *  Test operation clear
*/
void TestCalculator::clear(){
    Calculator calc;
    QCOMPARE(calc.total(), 0);
    calc.add(4);
    calc.clear();
    QCOMPARE(calc.total(), 0);
}
/**
 *  Test proptery total
*/
void TestCalculator::total(){
    Calculator testCalculator;
    // Do implement test here
}

QTEST_MAIN(TestCalculator);


