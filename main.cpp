#include <iostream>
#include <fstream>
#include <string>

#include "automaton.h"


int main() {
	std::string automatonFilename;
	std::fstream automatonFile;

	std::cout << "Digite o nome do arquivo que contem o automato." << std::endl << ">> ";
	std::cin >> automatonFilename;
	Automaton * a = new Automaton(automatonFile);

	return 0;
}
