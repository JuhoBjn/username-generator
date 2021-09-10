#include "action.h"
#include <iostream>

int main() {
	std::cout << "Welcome to the username generator!\n";
	std::string username = generate_username();
	std::cout << "Your new username is: " << username << std::endl;

	return 0;
}
