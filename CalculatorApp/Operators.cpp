#include "Operators.h"
#include <iostream>

int iresult;
float fresult;

void Operations::add(std::vector<std::string> args) {
    std::cout << "----- addition -----" << std::endl;

    for (auto i : args)
        fresult += std::stof(i);

    std::cout << fresult << std::endl;
    reset();
}

void Operations::div(std::vector<std::string> args) {
    std::cout << "----- division -----" << std::endl;
    fresult = std::stof(args[0]);

    for (int i = 1; i < (int)args.size(); i++)
        fresult /= std::stof(args[i]);

    std::cout << fresult << std::endl;
    reset();
}

void Operations::exp(std::vector<std::string> args) {
    std::cout << "----- exponent -----" << std::endl;
    fresult = std::stof(args[0]);

    for (int i = 1; i < (int)args.size(); i++)
        fresult = std::pow(fresult, std::stof(args[i]));

    std::cout << fresult << std::endl;
    reset();
}

void Operations::mul(std::vector<std::string> args) {
    std::cout << "----- multiplication -----" << std::endl;
    fresult = std::stof(args[0]);

    for (int i = 1; i < (int)args.size(); i++)
        fresult *= std::stof(args[i]);

    std::cout << fresult << std::endl;
    reset();
}

void Operations::mod(std::vector<std::string> args) {
    std::cout << "----- modulo -----" << std::endl;
    iresult = std::stoi(args[0]);

    for (int i = 1; i < (int)args.size(); i++)
        iresult %= std::stoi(args[i]);

    std::cout << iresult << std::endl;
    reset();
}

void Operations::sub(std::vector<std::string> args) {
    std::cout << "----- subtraction -----" << std::endl;

    fresult = std::stof(args[0]);
    for (int i = 1; i < (int)args.size(); i++)
        fresult -= std::stof(args[i]);

    std::cout << fresult << std::endl;
    reset();
}

void Operations::reset() {
    iresult = 0;
    fresult = 0;
}