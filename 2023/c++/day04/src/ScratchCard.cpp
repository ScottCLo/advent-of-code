#include"ScratchCard.h"

#include<regex>
#include<string>
#include<cmath>


ScratchCard::ScratchCard(std::string t_text){
	m_text = t_text;
	calcNumOfMatches();
	calcScore();
}

int ScratchCard::getNumOfMatches(){
	return m_num_of_matches;
}

int ScratchCard::getScore(){
	return m_score;
}

std::vector<int> ScratchCard::collectNumbers(std::string t_s){
	using namespace std;
	
	vector<int> mv;
	regex num_rx ("\\d+");
	smatch m;

	while(regex_search(t_s, m, num_rx)){
		mv.push_back(stoi(m[0]));
		t_s = m.suffix();
	}

	return mv;
}

void ScratchCard::calcNumOfMatches(){
	using namespace std;

	regex card_rx (": (.*) \\| (.*)");
	smatch match;
	vector<int> winning_numbers, your_numbers;
	int matches = 0;
	regex_search(m_text, match, card_rx);
	winning_numbers = collectNumbers( match[1]);
	your_numbers = collectNumbers( match[2]);

	for(int your_number:your_numbers){
		for(int winning_number:winning_numbers){
			if(your_number == winning_number){
				matches++;
			}
		}
	}
	
	m_num_of_matches = matches;
}
void ScratchCard::calcScore(){
	if(m_num_of_matches == 1){
		m_score = 1;
	}else if(m_num_of_matches > 1){
		m_score =  pow(2, m_num_of_matches - 1);
	}else{
		m_score = 0;
	}
}
