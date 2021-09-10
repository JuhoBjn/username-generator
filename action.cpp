#include "action.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cctype>

// Pick a random word from each file and concatenate.
std::string generate_username() {
	std::string filename_adverbs = "/home/juhobjn/projektit/username-generator/6K_adverbs.txt";
	std::string filename_nouns = "/home/juhobjn/projektit/username-generator/91K_nouns.txt";
	std::fstream infile_adverbs = open_files(filename_adverbs);
	std::fstream infile_nouns = open_files(filename_nouns);
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> adverb_int(1, 6276);
	std::uniform_int_distribution<> noun_int(1, 90963);

	unsigned adverb_number = adverb_int(gen);
	unsigned noun_number = noun_int(gen);
	GotoLine(infile_adverbs, adverb_number);
	GotoLine(infile_nouns, noun_number);
	
	std::string adverb;
	std::string noun;
	getline(infile_adverbs, adverb);
	getline(infile_nouns, noun);
	adverb[0] = toupper(adverb[0]);
	noun[0] = toupper(noun[0]);

	std::cout << "Adverb: " << adverb << std::endl;
	std::cout << "Noun: " << noun << std::endl;

	// Remove '/r' from the end of the words.
	adverb = adverb.substr(0, adverb.size() - 1);
	noun = noun.substr(0, noun.size() - 1);
	
	return adverb + noun;
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
