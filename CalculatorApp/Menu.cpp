#include "Menu.h"
#include <string>
#include <iostream>

void Menu::drawMenu() {
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