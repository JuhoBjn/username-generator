#pragma once
#include <iostream>
#include <fstream>

std::string generate_username();
std::fstream open_files(std::string filename);
std::fstream& GotoLine(std::fstream& file, unsigned num);
