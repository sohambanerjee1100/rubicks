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

enum Face{
	U = 0,
	F, D, B, R, L
};

enum Color {
	W=0,G,Y,B,R,O
};


class twoBytwo {
public : 
	vector<vector<int>> cube;
	vector<vector<vector<int* >>> rows;
	vector<vector<vector<int* >>> columns;


	vector<int> indofc;
	vector<int> indoff;
	vector<char> colorof;
	vector<int> faceof;
	twoBytwo() {
		cube.resize(6, vector<int>(4));
		rows.resize(6, vector<vector<int*>>(2, vector<int*>(2)));
		columns.resize(6, vector<vector<int*>>(2, vector<int*>(2)));
		for (int f = 0; f < 6; f++) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					cube[f][i * 2 + j] = f;
					rows[f][i][j] = &cube[f][i * 2 + j];
					columns[f][j][i]= &cube[f][i * 2 + j];
				}
			}
		}
		indofc.resize(26);
		indoff.resize(26);
		indofc['W' - 'A'] = 0;
		indofc['G' - 'A'] = 1;
		indofc['Y' - 'A'] = 2;
		indofc['B' - 'A'] = 3;
		indofc['R' - 'A'] = 4;
		indofc['O' - 'A'] = 5;

		indoff['U' - 'A'] = 0;
		indoff['F' - 'A'] = 1;
		indoff['D' - 'A'] = 2;
		indoff['B' - 'A'] = 3;
		indoff['R' - 'A'] = 4;
		indoff['L' - 'A'] = 5;

		colorof.resize(6);
		colorof[0] = 'W';
		colorof[0] = 'G';
		colorof[0] = 'Y';
		colorof[0] = 'B';
		colorof[0] = 'R';
		colorof[0] = 'O';

		faceof.resize(6);
		faceof[0] = 'U';
		faceof[0] = 'F';
		faceof[0] = 'D';
		faceof[0] = 'B';
		faceof[0] = 'R';
		faceof[0] = 'L';

	}

	//PreReqs for moves
	

	void rotate(char F,bool counter){
		int f = indoff[F - 'A'];
		if (!counter) {
			int temp = cube[f][3];
			for (int i = 3; i > 1; i--) {
				cube[f][i] = cube[f][i - 1];
			}
			cube[f][0] = temp;
		}
		else {
			int temp = cube[f][0];
			for (int i = 0; i < 3; i++) {
				cube[f][i] = cube[f][i + 1];
			}
			cube[f][3] = temp;
		}
	}

	void cycle(char axis, int ind, bool counter) {
		vector<int> faces = { 0,1,2,3 };
		vector<pair<int, int>> poss= { {0,3},{0,3}, {0,3}, {0,3} };
		if (counter) {
			reverse(faces.begin(), faces.end());
			reverse(poss.begin(), poss.end());
		}

		pair<int, int> temp = { cube[faces[3]][poss[3].first], cube[faces[3]][poss[3].second] };
		for (int i = 3; i >= 1; i++) {
			cube[faces[i]][poss[i].first] = cube[faces[i - 1]][poss[i - 1].first];
			cube[faces[i]][poss[i].second] = cube[faces[i - 1]][poss[i - 1].second];
		}
		cube[faces[0]][poss[0].first] = temp.first;
		cube[faces[0]][poss[0].second] = temp.second;
	}
	

	//Moves
	void move(char C, bool prime) {
		int c = indoff[C - 'A'];

	}

};

