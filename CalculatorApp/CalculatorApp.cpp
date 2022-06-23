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
	};

	Commands hashit(std::string const& inString) {
		if (inString == "add") return Commands::add;
		if (inString == "div") return Commands::div;
		if (inString == "exp") return Commands::exp;
		if (inString == "mul") return Commands::mul;
		if (inString == "mod") return Commands::mod;
		if (inString == "sub") return Commands::sub;
		if (inString == "quit") return Commands::quit;
	}

	void calculator() {
		Menu::drawMenu();

		std::string Command;
		std::getline(std::cin, Command);

		std::istringstream iss(Command);
		std::vector<std::string> arguments{ std::istream_iterator<std::string>(iss), {} };
		std::vector<std::string> args = { arguments.begin() + 1, arguments.end() };

		Commands op = hashit(arguments[0]);
		switch (op) {
		case Commands::add:
			Operations::add(args);
			break;

		case Commands::div:
			Operations::div(args);
			break;

		case Commands::exp:
			Operations::exp(args);
			break;

		case Commands::mul:
			Operations::mul(args);
			break;

		case Commands::mod:
			Operations::mod(args);
			break;

		case Commands::sub:
			Operations::sub(args);
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

		calculator();
	}
}

int main() {
	calculator::calculator();
}