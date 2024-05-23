#ifndef SCRATCHCARD_H
#define SCRATCHCARD_H

#include<string>
#include<vector>

class ScratchCard{
	public:
		ScratchCard(std::string t_text);
		int getScore();
		int getNumOfMatches();
	private:
		std::string m_text;
		int m_num_of_matches;
		int m_score;
		std::vector<int> collectNumbers(std::string t_s);
		void calcNumOfMatches();
		void calcScore();
};

#endif
