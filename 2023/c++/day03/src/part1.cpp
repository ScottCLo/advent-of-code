#include "part1.h"
#include <vector>
#include <string>

bool is_number(char c){
	return c >= '0' && '9' >= c;
}

bool is_symbol(char c){
	return c != '.' && !is_number(c);
}

std::vector<std::vector<char>> read_file_to_buffer(std::ifstream& input){
	using namespace std;

	string line;
	vector<vector<char>> buffer;

	while(getline(input, line)){
		vector<char> line_buffer = {};
		for(char c : line){
			line_buffer.push_back(c);
		}
		buffer.push_back(line_buffer);
	}
	return buffer;
}


int part1(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0;
	auto buffer = read_file_to_buffer(input);	
	
	for(int y = 0; y < buffer.size(); y++){
		for(int x = 0; x < buffer[y].size(); x++){
			if(is_number(buffer[y][x])){
				int start = x;
				string number;
				bool is_part = false;

				while(is_number(buffer[y][x])){
					number += buffer[y][x];
					x++;
				}

				for(int yi = y + -1; yi <= y + 1 ; yi++){
					if(0 <= yi && yi < buffer.size()){
						for(int xi = start - 1; xi < x + 1; xi++){
							if( 0 <= xi && xi < buffer.size()){
								if(is_symbol(buffer[yi][xi])){
									is_part = true;
									break;
								}
							}
						}
					}
					if(is_part){
						break;
					}
				}

				if(is_part){
					total += stoi(number);
				}
			}
		}
	}
	return total;
}
