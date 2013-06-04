#include <iostream>
#include <fstream>
#include <string>

#include "automaton.h"


int main() {
	std::string automatonFilename;
	std::ifstream automatonFile;

	std::cout << "Digite o nome do arquivo que contem o automato." << std::endl << ">> ";
	std::cin >> automatonFilename;

	automatonFile.open(automatonFilename.c_str(), std::ifstream::in);
	Automaton * automaton = new Automaton(automatonFile);

	return 0;
}
