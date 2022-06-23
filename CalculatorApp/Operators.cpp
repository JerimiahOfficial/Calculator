#include "Operators.h"
#include <iostream>

void Operations::add(std::vector<std::string> args) {
	int result = 0;

	for (int i = 0; i < args.size(); i++)
		result += std::stoi(args[i]);

	std::cout << "The sum of the numbers is: " << result << std::endl;
}

void Operations::div(std::vector<std::string> args) {
	// Divide all the numbers in the vector
	float result = std::stof(args[0]);

	for (int i = 1; i < args.size(); i++)
		result /= std::stof(args[i]);

	std::cout << "The result of the division is: " << result << std::endl;
}

void Operations::exp(std::vector<std::string> args) {
	// Raise the first number to the power of the second number
	float result = std::stof(args[0]);

	for (int i = 1; i < args.size(); i++)
		result = std::pow(result, std::stof(args[i]));

	std::cout << "The result of the exponentiation is: " << result << std::endl;
}

void Operations::mul(std::vector<std::string> args) {
	// Multiply all the numbers in the vector
	int result = 1;

	for (int i = 0; i < args.size(); i++)
		result *= std::stoi(args[i]);

	std::cout << "The result of the multiplication is: " << result << std::endl;
}

void Operations::mod(std::vector<std::string> args) {
	// Modulo all the numbers in the vector
	int result = std::stoi(args[0]);

	for (int i = 1; i < args.size(); i++)
		result %= std::stoi(args[i]);

	std::cout << "The result of the modulo is: " << result << std::endl;
}

void Operations::sub(std::vector<std::string> args) {
	// Subtract all the numbers in the vector
	int result = std::stoi(args[0]);

	for (int i = 1; i < args.size(); i++)
		result -= std::stoi(args[i]);

	std::cout << "The result of the subtraction is: " << result << std::endl;
}