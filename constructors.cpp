#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <unordered_map>
#include <unordered_set>

#include "twoBytwo.h"

twoBytwo :: twoBytwo() {
	cube.resize(6, vector<int>(4));
	boundary.resize(6);

	for (int f = 0; f < 6; f++) {
		for (int i = 0; i < 4; i++) {
			cube[f][i] = f;
		}
	}
	

	// up boundary

	boundary[0].push_back(&cube[1][1]);
	boundary[0].push_back(&cube[1][0]);
	boundary[0].push_back(&cube[5][1]);
	boundary[0].push_back(&cube[5][0]);
	boundary[0].push_back(&cube[3][1]);
	boundary[0].push_back(&cube[3][0]);
	boundary[0].push_back(&cube[4][1]);
	boundary[0].push_back(&cube[4][0]);
	

	//forward boundary

	boundary[1].push_back(&cube[0][3]);
	boundary[1].push_back(&cube[0][2]);
	boundary[1].push_back(&cube[4][0]);
	boundary[1].push_back(&cube[4][3]);
	boundary[1].push_back(&cube[2][1]);
	boundary[1].push_back(&cube[2][0]);
	boundary[1].push_back(&cube[5][2]);
	boundary[1].push_back(&cube[5][1]);

	// down boundary
	boundary[2].push_back(&cube[1][3]);
	boundary[2].push_back(&cube[1][2]);
	boundary[2].push_back(&cube[4][3]);
	boundary[2].push_back(&cube[4][2]);
	boundary[2].push_back(&cube[3][3]);
	boundary[2].push_back(&cube[3][2]);
	boundary[2].push_back(&cube[5][3]);
	boundary[2].push_back(&cube[5][2]);
	

	//back boundary
	boundary[3].push_back(&cube[0][1]);
	boundary[3].push_back(&cube[0][0]);
	boundary[3].push_back(&cube[5][0]);
	boundary[3].push_back(&cube[5][3]);
	boundary[3].push_back(&cube[2][3]);
	boundary[3].push_back(&cube[2][2]);
	boundary[3].push_back(&cube[4][2]);
	boundary[3].push_back(&cube[4][1]);
	

	// right boundary

	boundary[4].push_back(&cube[0][2]);
	boundary[4].push_back(&cube[0][1]);
	boundary[4].push_back(&cube[3][0]);
	boundary[4].push_back(&cube[3][3]);
	boundary[4].push_back(&cube[2][2]);
	boundary[4].push_back(&cube[2][1]);
	boundary[4].push_back(&cube[1][2]);
	boundary[4].push_back(&cube[1][1]);
	

	// left boundary

	boundary[5].push_back(&cube[0][0]);
	boundary[5].push_back(&cube[0][3]);
	boundary[5].push_back(&cube[1][0]);
	boundary[5].push_back(&cube[1][3]);
	boundary[5].push_back(&cube[2][0]);
	boundary[5].push_back(&cube[2][3]);
	boundary[5].push_back(&cube[3][2]);
	boundary[5].push_back(&cube[3][1]);

	


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

	string disp = "  Cube has been created succesfully....";
	cout << endl<<string(disp.size(), '-') << endl;
	cout << disp << endl;
	cout << string(disp.size(), '-') << endl;

}