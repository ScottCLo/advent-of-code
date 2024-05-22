#include "part2.h"
#include "part1.h"

#include <string>
#include <vector>

bool iterate_buffer(int& x, int& y, std::vector<std::vector<char>> b);

bool in_range(int x, int y, std::vector<std::vector<char>> b);

bool iterate_range(int& x, int& y, int sx, int sy, int h, int w,
		std::vector<std::vector<char>> b);

int collect_number( int &x, int &y, std::vector<std::vector<char>> b);

std::vector<int> collect_adjacent_numbers(int x, int y,
		std::vector<std::vector<char>> b);

int calculate_ratio(std::vector<int> v);

int part2(std::ifstream& input){
	using namespace std;

	string line;
	int total = 0, x = -1, y = 0;
	vector<vector<char>> buffer = read_file_to_buffer(input);
	
	while(iterate_buffer(x, y, buffer)){
		if(buffer[y][x] == '*'){
			vector<int> adjacent = collect_adjacent_numbers(x, y, buffer);
			if(adjacent.size() == 2){
				total += calculate_ratio(adjacent);
			}
		}
	}

	return total;
}

bool iterate_buffer(int& x, int& y, std::vector<std::vector<char>> b){
	if(x < b[y].size() - 1){
		x++;
		return true;
	}else if(y < b.size() - 1){
		y++;
		x=0;
		return true;
	}else{
		return false;
	}
}

bool in_range(int x, int y, std::vector<std::vector<char>> b){
	return (y >= 0 && b.size() > y && x >= 0 && x < b[y].size());
}

bool iterate_range(int& x, int& y, int sx, int sy, int h, int w,
		std::vector<std::vector<char>> b){

	if(y < 0 || x < 0){
		while(y < 0 && y < sy + h - 1){
			y++;	
		}
		while(x < 0 && x < sx + w - 1){
			x++;
		}

		if(in_range(x, y, b)){
			return true;
		}else{
			return false;
		}
	}

	if(x < sx + w - 1 && x < b[y].size() - 1){
		x++;
		return true;
	}else if(y < sy + h - 1 && y < b.size() - 1){
		y++;
		x = sx;
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

std::vector<int> collect_adjacent_numbers(int x, int y,
		std::vector<std::vector<char>> b){
	using namespace std;

	vector<int> n = {};

	y -= 1;
	x -= 2;
	int sx = x + 1;
	int sy = y;
	while(iterate_range(x, y, sx, sy, 3, 3, b)){
		if(is_number(b[y][x])){
			n.push_back(collect_number(x, y, b));
		}
	}

	return n;
}

int calculate_ratio(std::vector<int> v){
	int r = 1;
	
	for(int n:v){
		r *= n;
	}

	return r;
}
