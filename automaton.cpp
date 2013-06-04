#include "automaton.h"

void Automaton::addState(std::string state) {
	vStates.push_back(state);
}

void Automaton::addSymbol(std::string symbol) {
	vSymbols.push_back(symbol);
}
