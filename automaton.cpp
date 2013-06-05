#include "automaton.h"

#include <string>
#include <iostream>

Automaton::Automaton(std::istream & readFile) {
	readStatesFromFile(readFile);
	readSymbolsFromFile(readFile);
	readTransitionsFromFile(readFile);
}

void Automaton::readStatesFromFile(std::istream & readFile) {
	int n;
	bool insideQuotes, isFinal;
	std::string line;
	std::string stateName;


	readFile >> n;
	readFile >> line;

	insideQuotes = false;
	isFinal = false;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '\"') {

			if(insideQuotes) {
				addState(stateName);
				stateName.clear();
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
				stateName += line[i];
			}
		}

	}
}

void Automaton::readSymbolsFromFile(std::istream & readFile) {
	int n;
	bool insideQuotes;
	std::string line;
	std::string symbolName;


	readFile >> n;
	readFile >> line;

	insideQuotes = false;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '\"') {
			if(insideQuotes) {
				addSymbol(symbolName);
				symbolName.clear();
			}	//closing quote

			insideQuotes = !insideQuotes;
		}

		else {
			if(insideQuotes) {
				symbolName += line[i];
			}
		}

	}
}

void Automaton::readTransitionsFromFile(std::istream & readFile) {
	int k, transition[3];
	bool insideQuotes;
	std::string tmp;
	std::string line;
	


	while(readFile.good()) {
		readFile >> line;

		k = 0;
		insideQuotes = false;
		for(int i = 0; i < line.size(); i++) {
			if(line[i] == '\"') {
				if(insideQuotes) {
					if(k == 0)
						transition[k++] = findStateId(tmp);
					else if(k == 1)
						transition[k++] = findSymbolId(tmp);
					else {
						transition[k] = findStateId(tmp);
						mTransitions[transition[0]][transition[1]].push_back(transition[2]);
						k = 0;
					}
					
					tmp.clear();
				}	//closing quote

				insideQuotes = !insideQuotes;
			}

			else {
				if(insideQuotes) {
					tmp += line[i];
				}
			}

		}
	}
}

void Automaton::addState(std::string state) {
	vStates.push_back(state);
	mTransitions.resize(vStates.size());
}

void Automaton::addSymbol(std::string symbol) {
	vSymbols.push_back(symbol);
	
	for(int i = 0; i < mTransitions.size(); i++)
		mTransitions[i].resize(vSymbols.size());
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