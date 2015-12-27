#include "HumanInterface.h"

Position2D* HumanInterface::introduceBoardPosition(){
	string stringRow, stringColumn;
	int integerRow, integerColumn;
	bool castStringToIntegerError;

	do {
		castStringToIntegerError = false;

		cout << "Introduce una posicion: " << endl;
		cout << "\tFila: ";	getline(std::cin, stringRow);
		
		cout << "\tColumna: ";	getline(std::cin, stringColumn);
		cout << endl;

		try {
			integerRow = stoi(stringRow);
			integerColumn = stoi(stringColumn);
		}
		catch (exception e) {
			cout << "Los caracteres introducidos no son numeros." << endl;
			castStringToIntegerError = true;
		}

	} while (castStringToIntegerError);
	return new Position2D(integerRow, integerColumn);
	
}

Position2D* HumanInterface::wrongPositionReintroduce(){
	cout << "Posicion fuera de limites, reintroduce con valores aceptables." << endl << endl;
	return introduceBoardPosition();
}

Position2D* HumanInterface::usedPositionReintroduce(){
	cout << "Posicion ya usada, reintroduce con valores aceptables." << endl << endl;
	return introduceBoardPosition();
}

void HumanInterface::endGame(TicTacToeBoard * board, short idPlayer){
}

HumanInterface::HumanInterface(){
}
