#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "twoBytwo.h"

void twoBytwo :: display() {
	string message = "   Displaying the Cube....";
	cout << string(message.size(), '-') << endl;
	cout << message << endl;
	cout << string(message.size(), '-') << endl;
	string s = "    ";
	//first face
	cout << s << "______" << endl;
	cout << s << "|" << cube[3][2] << "  " << cube[3][3] << "|" << endl;
	cout << s << "|" << s << "|" << endl;
	cout << s << "|" << cube[3][1] << "  " << cube[3][0] << "|" << endl;
	cout << s << "______" << endl;
	//second face

	cout << s << "|" << cube[0][0] << "  " << cube[0][1] << "|" << endl;
	cout << s << "|" << s << "|" << endl;
	cout << s << "|" << cube[0][3] << "  " << cube[0][2] << "|" << endl;
	cout << "____" << "______" << "_____" << endl;
	// third fourth and fifth face
	cout << cube[5][0] << "  " << cube[5][1] << "|" << cube[1][0] << "  " << cube[1][1] << "|" << cube[4][0] << "  " << cube[4][1] << "|" << endl;
	cout << s << "|" << s << "|" << s << "|" << endl;
	cout << cube[5][3] << "  " << cube[5][2] << "|" << cube[1][3] << "  " << cube[1][2] << "|" << cube[4][3] << "  " << cube[4][2] << "|" << endl;
	cout << "____" << "______" << "____" << endl;
	//sixth face
	cout << s << "|" << cube[2][0] << "  " << cube[2][1] << "|" << endl;
	cout << s << "|" << s << "|" << endl;
	cout << s << "|" << cube[2][3] << "  " << cube[2][2] << "|" << endl;
	cout << s << "______" << endl<<endl;

	
	cout << string(message.size(), '-') << endl << endl;
}

void twoBytwo :: displayColor() {
	string temp = "  Cube has been created succesfully....";

	vector<string> color = { "\033[47m", "\033[42m" , "\033[43m" , "\033[44m" , "\033[41m" , "\033[48;5;202m" };
	string reset = "\033[0m";
	string wBbT = "\033[30;47m";

	string message = "   Displaying the Cube....";
	cout << string(temp.size(), '-') << endl;
	cout << message << endl;
	cout << string(temp.size(), '-') << endl<<endl;
	
	string spb = string(4, ' ');
	string d = " ";
	string of = string(1 + 2 * spb.size(), ' ');

	//top face 

	cout << of;
	cout << d << color[cube[0][0]] << spb << color[cube[0][1]] << spb << reset << endl;
	cout << of;
	cout << d << color[cube[0][0]] << spb << color[cube[0][1]] << spb << reset << endl;

	//second row
	cout << of;
	cout << d << color[cube[0][3]] << spb << color[cube[0][2]] << spb << reset << endl;
	cout << of;
	cout << d << color[cube[0][3]] << spb << color[cube[0][2]] << spb << reset << endl;

	//divider between faces
	cout << endl;

	//faces 5 1 4 and 3
	//fist row
	cout << d << color[cube[5][0]] << spb << color[cube[5][1]] << spb << reset;
	cout << d << color[cube[1][0]] << spb << color[cube[1][1]] << spb << reset;
	cout << d << color[cube[4][0]] << spb << color[cube[4][1]] << spb << reset;
	cout << d << color[cube[3][0]] << spb << color[cube[3][1]] << spb << reset<<endl;
	cout << d << color[cube[5][0]] << spb << color[cube[5][1]] << spb << reset;
	cout << d << color[cube[1][0]] << spb << color[cube[1][1]] << spb << reset;
	cout << d << color[cube[4][0]] << spb << color[cube[4][1]] << spb << reset;
	cout << d << color[cube[3][0]] << spb << color[cube[3][1]] << spb << reset << endl;

	//second row
	cout << d << color[cube[5][3]] << spb << color[cube[5][2]] << spb << reset;
	cout << d << color[cube[1][3]] << spb << color[cube[1][2]] << spb << reset;
	cout << d << color[cube[4][3]] << spb << color[cube[4][2]] << spb << reset;
	cout << d << color[cube[3][3]] << spb << color[cube[3][2]] << spb << reset << endl;
	cout << d << color[cube[5][3]] << spb << color[cube[5][2]] << spb << reset;
	cout << d << color[cube[1][3]] << spb << color[cube[1][2]] << spb << reset;
	cout << d << color[cube[4][3]] << spb << color[cube[4][2]] << spb << reset;
	cout << d << color[cube[3][3]] << spb << color[cube[3][2]] << spb << reset << endl;

	cout << endl;

	//bottom face 2
	//first row
	cout << of;
	cout << d << color[cube[2][0]] << spb << color[cube[2][1]] << spb << reset << endl;
	cout << of;
	cout << d << color[cube[2][0]] << spb << color[cube[2][1]] << spb << reset<<endl;

	//second row
	cout << of;
	cout << d << color[cube[2][3]] << spb << color[cube[2][2]] << spb << reset << endl;
	cout << of;
	cout << d << color[cube[2][3]] << spb << color[cube[2][2]] << spb << reset<<endl;
	cout << endl;
	cout << string(temp.size(), '-') << endl << endl;


}