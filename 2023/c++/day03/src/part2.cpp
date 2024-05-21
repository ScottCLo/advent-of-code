#include "part2.h"
#include "part1.h"

#include <string>
#include <vector>
#include <iostream>

bool iterate_buffer(int& x, int& y, std::vector<std::vector<char>> b){
	if(x < b[y].size()){
		x++;
		return true;
	}else if(y < b.size()){
		y++;
		x=0;
		std::cout << std::endl;
		return true;
	}else{
		return false;
	}
}

bool iterate_range(int& x, int& y, int h, int w, std::vector<std::vector<char>> b){
	if(x < 0){
		x++;
	}
	if(y < 0){
		y++;
		x -= w;
	}
	if(x > b[y].size()){
		y ++;
		x -= w;
	}
	if(y > b.size()){
		return false;	
	}
	if(x < x + w){
		x++;
		return true;
	}else if(y < y + h){
		y++;
		x -= w;
		return true;
	}else{
		return false;
	}
}

int collect_number( int &x, int &y, std::vector<std::vector<char>> b){
	using namespace std;

	string number = "";

	while(is_number(b[y][x-1])){
		x--;
	}
	while(is_number(b[y][x])){
		number += b[y][x];
		x++;
	}
	return stoi(number);
}

std::vector<int> collect_adjacent_numbers(int x, int y, std::vector<std::vector<char>> b){
	using namespace std;

	vector<int> n = {};

	y -= 1;
	x -= 1;

	while(iterate_range(x, y, 3, 3, b)){
		if(is_number(b[y][x])){
			n.push_back(collect_number(x, y, b));
		}
	}

	return n;
}

int calculate_ratio(std::vector<int> v, int i = 0, int t = 1){
	if(i < v.size()){
		std::cout << i << "[" << v[i] << "]" << t << std::endl;
		i ++;
		return calculate_ratio(v, i, t * v[i]);
	} else{
		std::cout << "ratio: " << t << std::endl;
		return t;
	}
}


int part2(std::ifstream& input){
	using namespace std;
	string line;
	int total = 0, x = 0, y = 0;
	//vector<vector<char>> buffer = read_file_to_buffer(input);
	
	vector<int> test = {3, 3, 3, 3};
	return calculate_ratio(test);
/*
	while(iterate_buffer(x, y, buffer)){
		if(buffer[y][x] == '*'){
			vector<int> adjacent = collect_adjacent_numbers(x, y, buffer);
			if(adjacent.size() == 2){
				total += calculate_ratio(adjacent);
			}
		}
	}
*/
	return total;
}
