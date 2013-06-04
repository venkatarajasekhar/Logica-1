#include "automaton.h"

Automaton::Automaton() {
	/* Nothing to do */
}

Automaton::Automaton(const std::fstream & readFile) {
	/* TODO */
}

void Automaton::addState(std::string state) {
	vStates.push_back(state);
}

void Automaton::addSymbol(std::string symbol) {
	vSymbols.push_back(symbol);
}
