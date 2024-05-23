#include "part2.h"
#include "ScratchCard.h"

#include <string>

struct Card{
	int num_of_cards;
	ScratchCard card;
};

int part2(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0;
	vector<Card> cards;

	ScratchCard card(line);

	while(getline(input, line)){
		cards.push_back(
			Card{1, ScratchCard(line)}
		);
	}
	
	for(int i = 0; i <= cards.size(); i++){
		if(i < cards.size() - 1){
			for( int c = 1; c <= cards[i].card.getNumOfMatches(); c++){
				if(i + c < cards.size()) {
					cards[i+c].num_of_cards += cards[i].num_of_cards;
				}
			}
		}
		if(i > 0) {
			total += cards[i-1].num_of_cards;
		}
	}
	

	return total;
}
