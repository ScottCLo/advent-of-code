#include "part1.h"

#include<vector>
#include<regex>

std::vector<std::string> split_str (std::string s, std::string d, std::vector<std::string> last = {}){
	using namespace std;
	if(s.find(d) != string::npos){
		int pos = s.find(d);
		last.push_back(s.substr(0,pos));
		return split_str(s.substr(pos + 1, s.npos), d, last);
	}else{
		last.push_back(s);
		return last;
	}
}

int part1(std::ifstream& input){
	using namespace std;
	const int RED = 12, GREEN = 13, BLUE = 14; 

	string line;
	int total = 0;
	int i = 1;
	while(getline(input, line)){
		bool valid = true;
		for(string round : split_str(split_str(line, ":")[1],";")){
			for(string marbles : split_str(round, ",")){
				smatch m;
				regex_search(marbles, m, std::regex("[A-Za-z]+"));
				string color = m[0];
				regex_search(marbles, m, std::regex("[0-9]+"));
				int count = stoi(m[0]);
				if(color == "red" && count > RED ||
				   color == "green" && count > GREEN || 
			           color == "blue" && count > BLUE){
					valid = false;
					break;
				}
			}
		}
		if(valid){
			total += i;
		}
		i ++;
	}
	return total;
}
