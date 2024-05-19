#include "part2.h"

#include <string>

int get_num(std::string s){
	using namespace std;
	
	if(s.find("1") != string::npos || s.find("one") != string::npos){
		return 1;
	}else if(s.find("2") != string::npos || s.find("two") != string::npos){
		return 2;
	}else if(s.find("3") != string::npos || s.find("three") != string::npos){
		return 3;
	}else if(s.find("4") != string::npos || s.find("four") != string::npos){
		return 4;
	}else if(s.find("5") != string::npos || s.find("five") != string::npos){
		return 5;
	}else if(s.find("6") != string::npos || s.find("six") != string::npos){
		return 6;
	}else if(s.find("7") != string::npos || s.find("seven") != string::npos){
		return 7;
	}else if(s.find("8") != string::npos || s.find("eight") != string::npos){
		return 8;
	}else if(s.find("9") != string::npos || s.find("nine") != string::npos){
		return 9;
	}else{
		return 0;
	}
}

int part2(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0;

	while(getline(input, line)){
		int first = 0;
		int last = 0;
		for(int i = 1; i <= line.length(); i++){
			if(first == 0) {
				first = get_num(line.substr(0,i));
			}

			int ri = line.length() - i;
			if(last == 0) {
				last = get_num(line.substr(ri, string::npos));
			}
		}
		total += first * 10 + last;
	}
	return total;
}
