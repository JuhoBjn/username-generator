#include "action.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cctype>

/*	PROBLEM IN CODE
*	seekg goes to the wrong places in files.
*/

// Pick a random word from each file and concatenate.
std::string generate_username() {
	std::string filename_adverbs = "6K_adverbs.txt";
	std::string filename_nouns = "91K_nouns.txt";
	std::ifstream infile_adverbs = open_files(filename_adverbs);
	std::ifstream infile_nouns = open_files(filename_nouns);
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> adverb_int(1, 6276);
	std::uniform_int_distribution<> noun_int(1, 90963);

	unsigned adverb_number = adverb_int(gen);
	unsigned noun_number = noun_int(gen);
	unsigned line_length_adverbs = 19;
	unsigned line_length_nouns = 45;
	unsigned adverb_pos = adverb_number * line_length_adverbs + 1;
	unsigned noun_pos = noun_number * line_length_nouns + 1;
	
	infile_adverbs.seekg(adverb_pos);
	infile_nouns.seekg(noun_pos);

	std::string adverb;
	std::string noun;
	getline(infile_adverbs, adverb);
	getline(infile_nouns, noun);
	adverb[0] = toupper(adverb[0]);
	noun[0] = toupper(noun[0]);

	std::cout << "Adverb: " << adverb << std::endl;
	std::cout << "Noun: " << noun << std::endl;

	return adverb + noun;
}

std::ifstream open_files(std::string filename) {
	std::ifstream infile;
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
