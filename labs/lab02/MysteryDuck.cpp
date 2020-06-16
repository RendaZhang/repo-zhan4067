//Renda Zhang

#include <iostream>
#include <string>
#include "MysteryDuck.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

MysteryDuck::MysteryDuck(string a, string b) {
	description = a;
	sound = b;
}

string MysteryDuck::getDescription() {
	return description;
}

void MysteryDuck::performQuack() {
	cout << sound << endl;
}
