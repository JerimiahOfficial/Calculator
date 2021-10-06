#pragma once
#include <vector>
#include <string>

namespace Operations {
	extern void add(std::vector<std::string> args);
	extern void div(std::vector<std::string> args);
	extern void exp(std::vector<std::string> args);
	extern void mul(std::vector<std::string> args);
	extern void mod(std::vector<std::string> args);
	extern void sub(std::vector<std::string> args);

	extern void reset();
}