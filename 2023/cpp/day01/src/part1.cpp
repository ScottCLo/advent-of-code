#include "part1.h"

#include <string>

int part1(std::ifstream& input){
	using namespace std;
	string line;
	int total = 0;

	while(getline(input, line)){
		int first = 0;
		int last = 0;
		for(int i = 0; i < line.length(); i++){
			if(line[i] >= '1' && '9' >= line[i] && first == 0){	
				first = int(line[i] - '0');
			}

			int ri = line.length() - i - 1;
			if(line[ri] >= '1' && '9' >= line[ri] && last == 0){	
				last = int(line[ri] - '0');	
			}
		}
		total += first * 10 + last;
	}
	return total;
}
