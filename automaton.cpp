#include "automaton.h"

#include <string>
#include <iostream>

Automaton::Automaton(std::ifstream & readFile) {
	int n;
	std::string word;
	std::string line;

	bool insideQuotes;
	bool isFinal;



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

}

void Automaton::addState(std::string state) {
	vStates.push_back(state);
}

void Automaton::addSymbol(std::string symbol) {
	vSymbols.push_back(symbol);
}
