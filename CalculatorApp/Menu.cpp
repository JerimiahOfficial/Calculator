#include "Menu.h"
#include <string>
#include <iostream>

void Menu::drawMenu() {
	std::string Menu[] = {
		"Calculator",                // 0
		"\tadd  - addition",         // 1
		"\tdiv  - division",         // 2
		"\texp  - exponent",         // 3
		"\tmul  - multiplication",   // 4
		"\tmod  - modulo",           // 5
		"\tsub  - subtraction",      // 6
		"\tquit - quit",             // 7
	};

	// print menu with for loop and size of array
	for (int i = 0; i < sizeof(Menu) / sizeof(Menu[0]); i++) {
		std::cout << Menu[i] << std::endl;
	}
}