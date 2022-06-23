#include "Operators.h"
#include "Menu.h"
#include <iostream>
#include <sstream>

namespace calculator {
	enum class Commands {
		add,
		div,
		exp,
		mul,
		sub,
		mod,
		quit,
		none,
	};

	Commands hashit(std::string const& inString) {
		if (inString == "add")
			return Commands::add;

		if (inString == "div")
			return Commands::div;

		if (inString == "exp")
			return Commands::exp;

		if (inString == "mul")
			return Commands::mul;

		if (inString == "mod")
			return Commands::mod;

		if (inString == "sub")
			return Commands::sub;

		if (inString == "quit")
			return Commands::quit;

		return Commands::none;
	}

	void calculator() {
		Menu::drawMenu();

		// Get user input.
		std::string input;
		std::getline(std::cin, input);

		// Split string by spaces, separate arguments from input.
		std::istringstream iss(input);
		std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
		std::vector<std::string> arguments{ tokens.begin() + 1, tokens.end() };

		// Get command.
		Commands command = hashit(tokens[0]);

		// Execute command.
		switch (command) {
		case Commands::add:
			Operations::add(arguments);
			break;

		case Commands::div:
			Operations::div(arguments);
			break;

		case Commands::exp:
			Operations::exp(arguments);
			break;

		case Commands::mul:
			Operations::mul(arguments);
			break;

		case Commands::mod:
			Operations::mod(arguments);
			break;

		case Commands::sub:
			Operations::sub(arguments);
			break;

		case Commands::quit:
			exit(0);
			break;

		default:
			std::cout << "Invalid operator" << std::endl;
			break;
		}

		for (int i = 0; i < 5; i++)
			std::cout << std::endl;
	}
}

int main() {
	while (true) {
		calculator::calculator();
	}
}