// Tiny Cave
// A text-based role-playing game developed by a team of three first-year students of computer science.
// Last Modified: 9/23/2019
// Chad Sutherland, Felipe Oliveira, Daniyar Aubekerov

#include "Map.h"
#include "Password.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

int getClass();
void printLoadScreen();

int main() {
	bool passValid = false;
	int myClass;
	unsigned seed = time(0);
	srand(seed);
	string input, actionInput, objectInput;
	string password;
	Map* gameMap = nullptr;
	Map* tempMap = nullptr;
	fstream saveFileHandler;

	printLoadScreen();

	cout << "To start a new game type start." << endl;
	cout << "To load a saved game type load and the name of the save file and extension." << endl;
	while (true) {
		cout << "What would you like to do: ";
		getline(cin, input);
		stringstream ss(input);
		ss >> actionInput;
		ss >> objectInput;

		if (actionInput == "restart" || actionInput == "start") {
			cout << "New game starting." << endl;
			myClass = getClass();
			delete gameMap;
			gameMap = new Map("map.txt", myClass);
			cout << gameMap->takeTurn("stats", "");
			cout << "Here your journey begins. Be careful. Some enemies will attack unprovoked. Type help for list of commands." << endl;
		}
		else if (actionInput == "save") {
			passValid = false;
			while (!passValid) {
				cout << "Enter a password to protect the file: ";
				getline(cin, password);
				try {
					Password myPassword(password);
					passValid = true;
				}
				catch (string exceptions) {
					cout << exceptions;
				}
			}
			if (gameMap->save(objectInput, password))
				cout << "Game saved to " << objectInput << "." << endl;
		}
		else if (actionInput == "load") {
			cout << "Enter the file password: ";
			getline(cin, password);
			try {
				tempMap = new Map("map.txt", objectInput, password);
				delete gameMap;
				gameMap = nullptr;
				gameMap = tempMap;
				cout << "Game loaded." << endl;
			}
			catch (Map::FNFexception) {
				cout << "Error: Save file not found." << endl;
			}
			catch (Map::incorrectPasswordexception) {
				cout << "Error: Password is incorrect." << endl;
			}
		}
		else if (actionInput == "exit") {
			cout << "Game closing..." << endl;
			delete gameMap;
			system("pause");
			exit(1);
		}
		else if (actionInput == "help") {
			cout << "Help Menu:\n"
				<< "Save - Saves current game.\n"
				<< "Load - loads the last saved game.\n"
				<< "Exit - Exits the game. Careful, this does not save the game!\n"
				<< "Restart - Starts a new game.\n"
				<< "N, S, E, W, NE, SE, SW, SE - Moves character.\n"
				<< "Pickup _____ - Picks up item.\n"
				<< "Drop _____ - Drops item.\n"
				<< "Inventory(or inv) - Shows current inventory.\n"
				<< "Equip _____ - Equips item if it is a weapon.\n"
				<< "Unequip - Unequips currently equipped item.\n"
				<< "Stats - Shows the heros health and damage\n";
		}
		else if (gameMap != nullptr) {
			if (gameMap->isGameOver())
				cout << "You are dead. Load a save file or begin a new game.\n";
			else
				cout << gameMap->takeTurn(actionInput, objectInput) << endl;
		}
		else
			cout << "You can't do that yet. Type help for list of commands." << endl;

		actionInput.clear();
		objectInput.clear();
	}

	delete gameMap;
	system("pause");
	return 0;
}

void printLoadScreen() {
	cout
		<< "\n\n"
		<< "  *********************************************************************************\n"
		<< "  *  _______   _____   _   _  __     __     _____            __      __  ______   *\n"
		<< "  * |__   __| |_   _| | \\ | | \\ \\   / /    / ____|     /\\    \\ \\    / / |  ____|  *\n"
		<< "  *    | |      | |   |  \\| |  \\ \\_/ /    | |         /  \\    \\ \\  / /  | |__     *\n"
		<< "  *    | |      | |   | . ` |   \\   /     | |        / /\\ \\    \\ \\/ /   |  __|    *\n"
		<< "  *    | |     _| |_  | |\\  |    | |      | |____   / ____ \\    \\  /    | |____   *\n"
		<< "  *    |_|    |_____| |_| \\_|    |_|       \\_____| /_/    \\_\\    \\/     |______|  *\n"
		<< "  *                                                                               *\n"
		<< "  *********************************************************************************\n";
}

//void printLoadScreen() {
//	cout
//		<< "\n\n"
//		<< "     *****************************************************************        \n"
//		<< "_______   _____   _   _  __     __     _____             __      __  ______   \n"
//		<< "|_   __| |_   _| | \ | | \ \   / /    / ____|     /\     \ \    / / |  ____|  \n"
//		<< "  | |      | |   |  \| |  \ \_/ /    | |         /  \     \ \  / /  | |__     \n"
//		<< "  | |      | |   | . ` |   \   /     | |        / /\ \     \ \/ /   |  __|    \n"
//		<< "  | |     _| |_  | |\  |    | |      | |____   / ____ \     \  /    | |____   \n"
//		<< "  |_|    |_____| |_| \_|    |_|       \_____| /_/    \_\     \/     |______ | \n"
//		<< "\n"
//}




int getClass() {
	int classChoice;
	cout << "Choose your path:" << endl;
	cout << "1. I am a Warrior." << endl;
	cout << "2. I am a Leader." << endl;
	cout << "3. I am a Mage." << endl;
	cin >> classChoice;
	cin.ignore();
	while (classChoice < 1 || classChoice > 3) {
		cout << "That is not a valid option. Try again." << endl;
		cout << "Choose your path:" << endl;
		cout << "1. I am a Warrior." << endl;
		cout << "2. I am a Leader." << endl;
		cout << "3. I am a Mage." << endl;
		cin >> classChoice;
		cin.ignore();
	}
	return classChoice;
}