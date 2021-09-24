#include "action.h"
#include <iostream>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc > 1){
		if(strchr(argv[1], 'h')){
			help();
			return 0;
		}
	}
	std::cout << "Welcome to the username generator!\n";
	std::string username = generate_username();
	std::cout << "Your new username is: " << username << std::endl;

	return 0;
}
