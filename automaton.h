#ifndef __AUTOMATON_H__
#define __AUTOMATON_H__

#include <vector>
#include <string>
#include <fstream>

class Automaton {
private:
	std::vector<std::string> vStates;
	std::vector<std::string> vSymbols;

	void addState(std::string state);
	void addSymbol(std::string symbol); 

public:
	Automaton(std::ifstream & readFile);
};

#endif //__AUTOMATON_H__
