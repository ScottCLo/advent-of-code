#ifndef PART1_H
#define PART1_H

#include <fstream>
#include <vector>
#include <fstream>

bool is_number(char c);
bool is_symbol(char c);
std::vector<std::vector<char>> read_file_to_buffer(std::ifstream& input);
int part1(std::ifstream&);

#endif
