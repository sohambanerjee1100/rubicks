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


void twoBytwo :: move(char C, bool prime) {
	int f = indoff[C - 'A'];
	if (!prime) {
		int temp = cube[f][3];
		for (int i = 3; i >= 1; i--) {
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

	if (prime) {
		reverse(boundary[f].begin(), boundary[f].end());
	}
	int temp1 = *boundary[f][7];
	int temp2 = *boundary[f][6];
	for (int i = 7; i > 1; i--) {
		*boundary[f][i] = *boundary[f][i - 2];
	}
	*boundary[f][1] = temp1;
	*boundary[f][0] = temp2;

	if (prime) {
		reverse(boundary[f].begin(), boundary[f].end());
	}
}



void twoBytwo :: move(string s) {
	int i = 0;
	while (i < s.size()) {
		if (i + 1 < s.size() && s[i + 1] == 'p') {
			this->move(s[i], 1);
			i++;
		}
		else if (i + 1 < s.size() && s[i + 1] == '2') {
			move(s[i], 0);
			move(s[i], 0);
			i++;
		}
		else this->move(s[i], 0);

		i++;
	}
}