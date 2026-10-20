#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;




class twoBytwo {
public : 
	vector<vector<int>> cube;
	vector<vector<int* >> boundary;


	vector<int> indofc;
	vector<int> indoff;
	vector<char> colorof;
	vector<int> faceof;

	//Constructors
	twoBytwo();

	//Simuls
	void move(char C, bool prime);
	void move(string s);

	//UI Related
	void display();
	void displayColor();

};

