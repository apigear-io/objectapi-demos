#include <iostream>
#include <vector>
#include <sstream>
#include "dice.h"

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

void dice_logic()
{
    Dice dice;
    while(true) {
        std::string line;
        std::cout << "total: " << dice.value() << std::endl;
        std::cout << "$ " << std::flush;
        std::getline (std::cin, line);
        std::vector<std::string> args = splitString(line, ' ');
        std::string action;
        if(args.size() >= 1) {
            action = args[0];
        }
        if (std::cin.eof() || action == "exit") {
            break;
        } else if (action == "toss") {
            dice.toss();
        }
    }
}

int main()
{
    dice_logic();
    return 0;
}
