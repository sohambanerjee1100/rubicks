#include <vector>
#include <iostream>
#include <algorithm>

#include "twoBytwo.h"

using namespace std;

int main() {
	string s = "    ";
	string line = " " + s + "  " + s + " ";
	string red = "\033[41m";
	string yellow = "\033[43m";
	string white = "\033[47m";
	string reset = "\033[0m";

	

	
	twoBytwo c;
	c.displayColor();
	while (true) {
		string s;
		cout << "Move : ";
		cin >> s;
		if (s == "0")break;
		c.move(s);
		c.displayColor();
	}
	
}