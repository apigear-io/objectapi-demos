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
#include "tst_dice.h"
#include "dice.h"
#include "api.h"

class MockRandom : public AbstractRandom {
public:
    MockRandom(QObject *parent = nullptr)
        : AbstractRandom(parent)
        , count(0)
    {}
    int generate(int min, int max) override {
        count++;
        return min;
    }
    int count;
};

/**
 *  will be called before the first test function is executed.
*/
void TestDice::initTestCase(){

}

/**
 *  will be called to create a global test data table.
*/
void TestDice::initTestCase_data(){

}

/**
 *  will be called after the last test function was executed.
*/
void TestDice::cleanupTestCase(){

}

/**
 *  will be called before each test function is executed.
*/
void TestDice::init(){

}

/**
 *  will be called after every test function.
*/
void TestDice::cleanup(){

}
/**
 *  Test operation toss
*/
void TestDice::toss(){
    MockRandom r;
    Dice dice(&r);
    QCOMPARE(r.count, 0);
    dice.toss();
    QCOMPARE(r.count, 1);
}
/**
 *  Test proptery value
*/
void TestDice::value(){
}

QTEST_MAIN(TestDice);


