#include "part2.h"

#include <string>
#include <regex>
#include <cstdio>

int part2(std::ifstream& input){
	using namespace std;
	string line;
	int total = 0;

	while(getline(input, line)){
		bool valid = true;
		int red = 0, green = 0, blue = 0;
		smatch marbles;
		while(regex_search(line, marbles, std::regex("[0-9]+ [A-Za-z]+"))){
			string marble = marbles.str(0);
			smatch m;
			regex_search(marble, m, std::regex("[A-Za-z]+"));
			string color = m[0];
			regex_search(marble, m, std::regex("[0-9]+"));
			int count = stoi(m[0]);

			if(color == "red" && count > red){
				red = count;
			}else if(color == "green" && count > green){
				green = count;
			}else if(color == "blue" && count > blue){
				blue = count;
			}

			line = marbles.suffix().str();
		}
		int power = red * green * blue;
		total += power;
	}
	return total;
}
