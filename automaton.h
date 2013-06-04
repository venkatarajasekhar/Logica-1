#ifndef __AUTOMATON_H__
#define __AUTOMATON_H__

#include <vector>
#include <string>

class Automaton {
private:
	std::vector<std::string> vStates;
	std::vector<std::string> vSymbols;

public:
	void addState(std::string state);
	void addSymbol(std::string symbol); 
};

#endif //__AUTOMATON_H__
