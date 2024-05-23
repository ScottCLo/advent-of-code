#include "part1.h"

#include <regex>
#include <cmath>

std::vector<std::string> collect_matches(std::string s, std::regex r);

int part1(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0;
	regex win_num_rx (": (.*) \\|");
	regex your_num_rx ("\\| (.*)$");
	regex number_rx ("\\d+");
	
	while(getline(input, line)){
		smatch match;
		vector<string> winning_numbers, your_numbers;
		int matches = 0, score = 0;

		regex_search(line, match, win_num_rx);
		winning_numbers = collect_matches( match[1], number_rx);

		regex_search(line, match, your_num_rx);
		your_numbers = collect_matches( match[1], number_rx);
		
		for(string your_number:your_numbers){
			for(string winning_number:winning_numbers){
				if(your_number == winning_number){
					matches++;
				}
			}
		}

		if(matches == 1){
			total += 1;
		}else if(matches > 1){
			total += pow(2, matches - 1);
		}
	}

	return total;
}

std::vector<std::string> collect_matches(std::string s, std::regex r){
	using namespace std;
	
	vector<string> mv;
	smatch m;

	while(regex_search(s, m, r)){
		mv.push_back(m[0]);
		s = m.suffix();
	}

	return mv;
}
