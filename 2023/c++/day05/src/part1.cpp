#include "part1.h"

#include<iostream>
#include<sstream>
#include<vector>
#include<regex>

std::vector<unsigned int> collect_numbers_uint(std::string s){
	using namespace std;

	regex num_rx("\\d+");
	smatch match;
	vector<unsigned int> nums;

	while(regex_search(s, match, num_rx)){
		nums.push_back(stoul(match[0]));	
		s = match.suffix();
	}

	return nums;
}

struct Value{
	
};

class PuzzleMap{
	public:
		PuzzleMap(unsigned int t_destination, unsigned int t_source, unsigned int t_range);
		bool map(unsigned int& t_value);
	private:
		unsigned int m_destination, m_source, m_range;
};

PuzzleMap::PuzzleMap(unsigned int t_destination, unsigned int t_source, unsigned int t_range){
	using namespace std; 

	m_destination = t_destination;
	m_source = t_source;
	m_range = t_range;
}

bool PuzzleMap::map(unsigned int& t_value){
	if(t_value >= m_source && m_source + m_range >= t_value){
		t_value = m_source - t_value + m_destination;
		return true;
	}else{
		return false;
	}
}

int part1(std::ifstream& input){
	using namespace std;

	stringstream str_stream;
	str_stream << input.rdbuf();
	string input_str = str_stream.str();
	int total = 0;
	vector<unsigned int> seeds;
	smatch match;

	regex seed_rx("seeds: ((.|\\n)*?)\\n\\n");
	regex_search(input_str, match, seed_rx);
	seeds = collect_numbers_uint(match[1]);
	input_str = match.suffix().str();

	regex map_rx("(.*)-to-(.*) map:\\n((.|\\n)*?)\\n\\n");
	regex_search(input_str, match, map_rx);
	string map_str1 = match[3];
	
	regex m_rx("^(\\d+) (\\d+) (\\d+)");
	regex_search(map_str1, match, m_rx);
	PuzzleMap map1(stoul(match[1]), stoul(match[2]), stoul(match[3]));
	unsigned int test = 98;
	cout << test << endl;
	map1.map(test);
	cout << test << endl;

	return total;
}
