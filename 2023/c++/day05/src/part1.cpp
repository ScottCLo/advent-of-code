#include "part1.h"

#include<iostream>
#include<sstream>
#include<vector>
#include<regex>

std::vector<int> collect_numbers(std::string s){
	using namespace std;

	regex num_rx("\\n+");
	smatch match;
	vector<int> nums;

	while(regex_search(s, match, num_rx)){
		nums.push_back(stoi(match[0]));	
	}

	return nums;
}

class PuzzleMap{
	public:
		PuzzleMap(int t_in, int t_out, int t_range);
		bool map(int& t_value);
	private:
		int m_in, m_out, m_range;
};

PuzzleMap::PuzzleMap(int t_in, int t_out, int t_range){
	using namespace std; 
	m_in = t_in;
	m_out = t_out;
	m_range = t_range;
}

bool PuzzleMap::map(int& t_value){
	if(t_value >= m_in && m_in + m_range >= t_value){
		t_value = m_in - t_value + m_out;
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
	vector<int> seeds;
	regex seed_rx("seeds: ((.|\\n)*?)\\n\\n");

	smatch match;
	regex_search(input_str, match, seed_rx);
	seeds = collect_numbers(match[1]);
	input_str = match.suffix().str();

	regex map_rx("(.*)-to-(.*) map:\\n((.|\\n)*?)\\n\\n");
	regex_search(input_str, match, map_rx);
	string map_str1 = match[3];
	
	regex m_rx("^(\\d+) (\\d+) (\\d+)");
	regex_search(map_str1, match, m_rx);
	cout << match[1] << endl << match[2] << endl << match[3] << endl;
	PuzzleMap map1(stoi(match[1].str()), stoi(match[2].str()), stoi(match[3].str()));

	int test = 2056129210;

	//map1.map(test);

	cout << test;


	return total;
}
