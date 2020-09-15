#include <iostream>
#include <vector>
#include <sstream>
#include "calculator.h"

std::vector<std::string> splitString(std::string line, char delimeter)
{
    std::stringstream linestream(line);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(linestream, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

void calc_logic()
{
    Calculator calc;
    while(true) {
        std::string line;
        std::cout << "total: " << calc.total() << std::endl;
        std::cout << "$ " << std::flush;
        std::getline (std::cin, line);
        std::vector<std::string> args = splitString(line, ' ');
        std::string action;
        if(args.size() >= 1) {
            action = args[0];
        }
        int num = 0;
        if(args.size() == 2) {
            num = std::stoi(args[1]);
        }
        if (std::cin.eof() || action == "exit") {
            break;
        } else if (action == "add") {
            calc.add(num);
        } else if (action == "mul") {
            calc.multiply(num);
        } else if (action == "sub") {
            calc.substract(num);
        } else if (action == "div") {
            calc.divide(num);
        } else if (action == "clear") {
            calc.clear();
        }
    }
}

int main()
{
    calc_logic();
    return 0;
}
