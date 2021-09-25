#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <valarray>
#include <algorithm>
#include <math.h>

int iresult;
float fresult;

enum class Operators {
    addition,
    division,
    exponent,
    multiplication,
    subtraction,
    modulo,
};

constexpr uint32_t hash(const char* data, size_t const size) noexcept {
    uint32_t hash = 5381;

    for (const char* c = data; c < data + size; ++c)
        hash = ((hash << 5) + hash) + (unsigned char)*c;

    return hash;
}

Operators hashit(std::string const& inString) {
    if (inString == "add") 
        return Operators::addition;

    if (inString == "div")
        return Operators::division;

    if (inString == "exp")
        return Operators::exponent;

    if (inString == "mul")
        return Operators::multiplication;

    if (inString == "mod")
        return Operators::modulo;

    if (inString == "sub") 
        return Operators::subtraction;
}

void drawMenu() {
    std::string Menu[] = { 
        "Calculator",               // 0
        "\tadd - addition",         // 1
        "\tdiv - division",         // 2
        "\texp - exponent",         // 3
        "\tmul - multiplication",   // 4
        "\tmod - modulo",           // 5
        "\tsub - subtraction",      // 6
    };

    for (int i = 0; i < 6; i++)
        std::cout << Menu[i] << std::endl;
}

int main() {
    drawMenu();

    std::string Command;
    std::getline(std::cin, Command);

    std::istringstream iss(Command);
    std::vector<std::string> arguments {std::istream_iterator<std::string>(iss), {}};

    switch (hashit(arguments[0]))
    {
    case Operators::addition:
        std::cout << "----- addition -----" << std::endl;
        arguments.erase(arguments.begin());
        
        for (auto i : arguments)
            fresult += std::stof(i);

        std::cout << fresult << std::endl;
        break;

    case Operators::division:
        std::cout << "----- division -----" << std::endl;
        arguments.erase(arguments.begin());
        fresult = std::stof(arguments[0]);

        for (int i = 1; i < (int)arguments.size(); i++)
            fresult /= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;

    case Operators::exponent:
        std::cout << "----- exponent -----" << std::endl;
        arguments.erase(arguments.begin());
        fresult = std::stof(arguments[0]);

        for (int i = 1; i < (int)arguments.size(); i++)
            fresult = std::pow(fresult, std::stof(arguments[i]));

        std::cout << fresult << std::endl;
        break;

    case Operators::multiplication:
        std::cout << "----- multiplication -----" << std::endl;
        arguments.erase(arguments.begin());
        fresult = std::stof(arguments[0]);

        for (int i = 1; i < (int)arguments.size(); i++)
            fresult *= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;

    case Operators::modulo:
        std::cout << "----- modulo -----" << std::endl;
        arguments.erase(arguments.begin());
        iresult = std::stoi(arguments[0]);

        for (int i = 1; i < (int)arguments.size(); i++)
            iresult %= std::stoi(arguments[i]);

        std::cout << iresult << std::endl;
        break;

    case Operators::subtraction:
        std::cout << "----- subtraction -----" << std::endl;
        arguments.erase(arguments.begin());

        fresult = std::stof(arguments[0]);
        for (int i = 1; i < (int)arguments.size(); i++)
            fresult -= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;    

    default:
        break;
    }

    fresult, iresult = 0;

    for (int i = 0; i < 5; i++)
        std::cout << std::endl;
    
    main();
}                                                                                                                                                             
