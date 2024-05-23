#include "part1.h"
#include "ScratchCard.h"

#include<string>

int part1(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0;

	while(getline(input, line)){
		total += ScratchCard(line).getScore();
	}

	return total;
}
