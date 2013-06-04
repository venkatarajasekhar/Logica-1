#include "automaton.h"

#include <string>
#include <iostream>

Automaton::Automaton(std::istream & readFile) {
	int n;
	std::string word;
	std::string line;

	bool insideQuotes;
	bool isFinal;

	int transition[3];	//stateFrom, symbol, stateTo
	int k;				//counter for the vector above



	//read states

	readFile >> n;
	readFile >> line;

	insideQuotes = false;
	isFinal = false;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '\"') {

			if(insideQuotes) {
				addState(word);
				word.clear();
			}	//closing quote

			else {
				if(line[i + 1] == '*'){
					i++;
					isFinal = true;
				}
				else
					isFinal = false;
			}	//opening quote

			insideQuotes = !insideQuotes;
		}

		else {

			if(insideQuotes) {
				word += line[i];
			}
		}

	}

	//read symbols

	readFile >> n;
	readFile >> line;

	insideQuotes = false;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '\"') {
			if(insideQuotes) {
				addSymbol(word);
				word.clear();
			}	//closing quote

			insideQuotes = !insideQuotes;
		}

		else {
			if(insideQuotes) {
				word += line[i];
			}
		}

	}

	//resize transitions matrix
	mTransitions.resize(vStates.size());
	for(int i = 0; i < mTransitions.size(); i++) {
		mTransitions[i].resize(vSymbols.size());
	}

	//read transitions
	while(readFile.good()) {
		readFile >> line;

		k = 0;
		insideQuotes = false;
		for(int i = 0; i < line.size(); i++) {
			if(line[i] == '\"') {
				if(insideQuotes) {
					if(k == 0)
						transition[k++] = findStateId(word);
					else if(k == 1)
						transition[k++] = findSymbolId(word);
					else {
						transition[k] = findStateId(word);
						mTransitions[transition[0]][transition[1]].push_back(transition[2]);
						k = 0;
					}
					
					word.clear();
				}	//closing quote

				insideQuotes = !insideQuotes;
			}

			else {
				if(insideQuotes) {
					word += line[i];
				}
			}

		}
	}
}

void Automaton::addState(std::string state) {
	vStates.push_back(state);
}

void Automaton::addSymbol(std::string symbol) {
	vSymbols.push_back(symbol);
}

int Automaton::findStateId(std::string state) {
	for(int i = 0; i < vStates.size(); i++) {
		if(vStates[i] == state)
			return i;
	}
	return -1;
}

int Automaton::findSymbolId(std::string symbol) {
	for(int i = 0; i < vSymbols.size(); i++) {
		if(vSymbols[i] == symbol)
			return i;
	}
	return -1;
}

void Automaton::printTransitionsTable(std::ostream & output) {
	for(int j = 0; j < vSymbols.size(); j++) {
		output << "\t" << vSymbols[j];
	}
	output << std::endl;

	for(int i = 0; i < vStates.size(); i++) {
		output << vStates[i];

		for(int j = 0; j < vSymbols.size(); j++) {
			output << "\t";

			for(std::list<int>::iterator it = mTransitions[i][j].begin(); it != mTransitions[i][j].end(); it++) {
				output << vStates[*it];
			}
		}
		output << std::endl;
	}
}