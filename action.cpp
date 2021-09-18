#include "action.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cctype>

// Pick a random word from each file and concatenate.
std::string generate_username() {
	std::string filename_adjectives = "english-adjectives.txt";
	std::string filename_nouns = "english-nouns.txt";
	std::fstream infile_adjectives = open_files(filename_adjectives);
	std::fstream infile_nouns = open_files(filename_nouns);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> adjective_int(1, 1347);
	std::uniform_int_distribution<> noun_int(1, 1525);

	unsigned adjective_number = adjective_int(gen);
	unsigned noun_number = noun_int(gen);
	GotoLine(infile_adjectives, adjective_number);
	GotoLine(infile_nouns, noun_number);
	
	std::string adjective;
	std::string noun;
	getline(infile_adjectives, adjective);
	getline(infile_nouns, noun);
	adjective[0] = toupper(adjective[0]);
	noun[0] = toupper(noun[0]);

	return adjective + noun;
}

std::fstream open_files(std::string filename) {
	std::fstream infile;
	try {
		infile.open(filename);
		if (infile.fail())
			throw 10;
	}
	catch (int errNo) {
		infile.clear();
		std::cerr << "Failed to open file.\n";
	}
	return infile;
}

std::fstream& GotoLine(std::fstream& file, int num){
	file.seekg(std::ios::beg);
	for(int i = 0; i < num - 1; i++)
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return file;
}

void help(){
	std::cout << "Usage: username-generator [arguments]\n";
	std::cout << "Options:\n";
	std::cout << "	-h		Display this information.\n";
}
