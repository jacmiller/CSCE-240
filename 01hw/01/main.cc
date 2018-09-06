// main.cc: CSCE 240 Assignment 1: This is the main file for the bit-to-binary converter
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::to_string;


int main()
{
	int num_bits = 0;

	cin >> num_bits;
	if (num_bits < 1 || 32 < num_bits)
		return 1;

	int decimal = 0;

	cin >> decimal;
	if (decimal < 0)
		return 2;
	
	string bits = "";
	for (int i = 0; i < num_bits; ++i) {
		int remainder = decimal % 2;
		decimal = decimal / 2;
		bits = to_string(remainder) + bits;
	}
	cout << bits << endl;
    return 0;
}

