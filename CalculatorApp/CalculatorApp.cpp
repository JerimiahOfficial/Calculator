#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <valarray>
#include <algorithm>

int iresult;
float fresult;

enum Operators {
    addition,
    division,
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
    if (inString == "a") 
        return addition;

    if (inString == "s") 
        return subtraction;

    if (inString == "m") 
        return multiplication;

    if (inString == "d") 
        return division;

    if (inString == "mod")
        return modulo;
}

void drawMenu() {
    std::string Menu[] = { 
        "Calculator",   // 0
        "\ta - addition",   // 1
        "\ts - subtraction",   // 2
        "\td - division",   // 3
        "\tm - multiplication",   // 4
        "\tmod - modulo"            // 5
    };

    for (int i = 0; i < 6; i++)
        std::cout << Menu[i] << std::endl;
}

int main()
{
    drawMenu();

    std::string Command;
    std::getline(std::cin, Command);

    std::istringstream iss(Command);
    std::vector<std::string> arguments {std::istream_iterator<std::string>(iss), {}};

    switch (hashit(arguments[0]))
    {
    case addition:
        std::cout << "----- addition -----" << std::endl;
        arguments.erase(arguments.begin());

        for (auto i : arguments)
            fresult += std::stof(i);

        std::cout << fresult << std::endl;
        break;

    case subtraction:
        std::cout << "----- subtraction -----" << std::endl;
        arguments.erase(arguments.begin());

        fresult = std::stof(arguments[0]);
        for (int i = 1; i < (int)arguments.size(); i++)
            fresult -= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;

    case multiplication:
        std::cout << "----- multiplication -----" << std::endl;
        arguments.erase(arguments.begin());

        fresult = std::stof(arguments[0]);
        for (int i = 1; i < (int)arguments.size(); i++)
            fresult *= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;

    case division:
        std::cout << "----- division -----" << std::endl;
        arguments.erase(arguments.begin());

        fresult = std::stof(arguments[0]);
        for (int i = 1; i < (int)arguments.size(); i++)
            fresult /= std::stof(arguments[i]);

        std::cout << fresult << std::endl;
        break;

    case modulo:
        std::cout << "----- modulo -----" << std::endl;
        arguments.erase(arguments.begin());

        iresult = std::stoi(arguments[0]);
        for (int i = 1; i < (int)arguments.size(); i++)
            iresult %= std::stoi(arguments[i]);

        std::cout << iresult << std::endl;
        break;

    default:
        break;
    }

    system("pause");
}                                                                                                                                                             
