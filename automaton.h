#ifndef __AUTOMATON_H__
#define __AUTOMATON_H__

#include <vector>
#include <string>
#include <fstream>
#include <list>

class Automaton {
private:
	std::vector<std::string> vStates;
	std::vector<std::string> vSymbols;
	std::vector< std::vector< std::list < int > > > mTransitions;

	void addState(std::string state);
	void addSymbol(std::string symbol); 

	int findStateId(std::string state);
	int findSymbolId(std::string symbol);

	void readStatesFromFile(std::istream & readFile);
	void readSymbolsFromFile(std::istream & readFile);
	void readTransitionsFromFile(std::istream & readFile);

public:
	Automaton(std::istream & readFile);
	void printTransitionsTable(std::ostream & output);
};

#endif //__AUTOMATON_H__
