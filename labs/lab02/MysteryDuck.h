// Renda Zhang

#ifndef LAB02_MYSTERYDUCK_H_
#define LAB02_MYSTERYDUCK_H_

#include <string>
#include "Duck.h"
#include <string>

using std::string;

class MysteryDuck : public Duck {
	private:
		string description;
		string sound;
	
	public:
		MysteryDuck(string a, string b);
		std::string getDescription();
		void performQuack();
};

#endif
