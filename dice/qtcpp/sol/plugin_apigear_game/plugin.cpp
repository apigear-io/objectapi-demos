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

#include "plugin.h"

#include <QtQml>

#include "api.h"
#include "qmldice.h"
#include "qmlrandom.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri apigear.game
    // register enum

    // register structs

    // register interfaces
    qmlRegisterType<QmlDice>(uri, 1, 0, "Dice");
    qmlRegisterType<QmlRandom>(uri, 1, 0, "Random");



}
