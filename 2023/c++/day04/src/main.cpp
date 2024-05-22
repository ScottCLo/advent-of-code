#include "part1.h"
#include "part2.h"

#include <cstdio>
#include <fstream>

int main(){
	std::ifstream input;
	input.open("input");
	if(!input.is_open()){
		std::printf("Unable to open input file.\n");
		return 0;
	}

	std::printf("Part 1: %d\n", part1(input));

	input.clear();
	input.seekg(0);

	std::printf("Part 2: %d\n", part2(input));

	return 0;
}
