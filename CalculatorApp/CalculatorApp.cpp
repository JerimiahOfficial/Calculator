#include "Operators.h"
#include "Menu.h"
#include <iostream>
#include <sstream>

namespace calculator {
	enum class Operators {
		add,
		div,
		exp,
		mul,
		sub,
		mod,
	};

	constexpr uint32_t hash(const char* data, size_t const size) noexcept {
		uint32_t hash = 5381;

		for (const char* c = data; c < data + size; ++c)
			hash = ((hash << 5) + hash) + (unsigned char)*c;

		return hash;
	}

	Operators hashit(std::string const& inString) {
		if (inString == "add") return Operators::add;
		if (inString == "div") return Operators::div;
		if (inString == "exp") return Operators::exp;
		if (inString == "mul") return Operators::mul;
		if (inString == "mod") return Operators::mod;
		if (inString == "sub") return Operators::sub;
	}

	void calculator() {
		Menu::drawMenu();

		std::string Command;
		std::getline(std::cin, Command);

		std::istringstream iss(Command);
		std::vector<std::string> arguments{ std::istream_iterator<std::string>(iss), {} };
		std::vector<std::string> args = { arguments.begin() + 1, arguments.end() };

		switch (hashit(arguments[0])) {
		case Operators::add: Operations::add(args); break;
		case Operators::div: Operations::div(args); break;
		case Operators::exp: Operations::exp(args); break;
		case Operators::mul: Operations::mul(args); break;
		case Operators::mod: Operations::mod(args); break;
		case Operators::sub: Operations::sub(args); break;
		default: break;
		}

		for (int i = 0; i < 5; i++)
			std::cout << std::endl;

		calculator();
	}
}

int main() {
	calculator::calculator();
}