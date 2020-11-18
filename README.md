# ObjectAPI Demos

A set of demos in different languages

# Basic Setup

Each demo contains an `apis` folder which contains the ObjectAPI definition. From this API definition solution for the different target languages are created.

Each language contains a `ini` (initial code) and a `sol` (solution code). It is easy to compare these folders.


## Calculator Demo

The calculator demo shows a simple calculator defined in a single ObjectAPI module. 
The calculator has a `total` state which is automatically updated and propagated using the calculator operations.

* [API](calc/apis/calculator.oapi.yaml)
* [Initial C++ 14](calc/cpp14/ini/)
* [Solution C++ 14](calc/cpp14/sol)
* [Service implementation for calculator API](calc/cpp14/sol/apigear_calc/calculator.cpp)

For other languages see the respective sub-folders.

## Dice Demo

The dice demo show how one interface (`Dice`) can depend on another interface (`Random`).

The story is a device manufacturer develops an electronic dice for the gaming industry. 
The dice contains a HW random component, to make it secure. How can we now develop the dice effectively without depending on the HW?

* [API](dice/apis/calculator.oapi.yaml)
* [Initial C++ 14 Code](dice/cpp14/ini/)
* [Solution C++ 14 Code](dice/cpp14/sol)
* [Service implementation for dice API](dice/cpp14/sol/apigear_game/dice.cpp)
* [Service implementation for random API](dice/cpp14/sol/apigear_game/random.cpp)

For other languages see the respective sub-folders.

## Future

* Demonstrate adapters for transports
* Demonstrate dynamic simulations


