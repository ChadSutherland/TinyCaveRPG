// Chad Sutherland
// 5/12/2019
#include "Map.h"
#include <ctime>
#include <exception>

Map::Map(string mapFile, int myClass) {
	switch (myClass) {
	case 1: myHero = new Warrior(); break;
	case 2: myHero = new Leader(); break;
	case 3: myHero = new Mage(); break;
	}
	unsigned seed = time(0);
	srand(seed);
	tileArray = new Tile*[ROWS];
	for (int i = 0; i < ROWS; i++)
		tileArray[i] = new Tile[COLS];
	initMapArray();
	spawnItems();
	spawnEnemies();
}

Map::Map(string mapFile, string saveFile, string password) {
	tileArray = new Tile*[ROWS];
	for (int i = 0; i < ROWS; i++)
		tileArray[i] = new Tile[COLS];
	initMapArray();
	
	try {
		load(saveFile, password);
	}
	catch (FNFexception) {
		throw FNFexception();
	}
	catch (incorrectPasswordexception) {
		throw incorrectPasswordexception();
	}
}

Map::~Map() {
	for (int i = 0; i < ROWS; i++) {
		delete[] tileArray[i];
		tileArray[i] = nullptr;
	}
	delete[] tileArray;
	tileArray = nullptr;

	delete myHero;

	for (int i = 0; i < enemyArray.size(); i++) {
		delete enemyArray[i];
	}

	itemList.deleteList();
}

bool Map::save(string fileName, string password) {
	bool success = false;
	int numEnemies = Enemy::getNumEnemies();
	saveFileHandler.open(fileName, ios::out | ios::binary);
	if (!saveFileHandler.fail()) {
		success = true;
		saveFileHandler.write(password.c_str(), 15);
		saveFileHandler.write(reinterpret_cast<char*>(&myHero), sizeof(Hero));
		saveFileHandler.write(reinterpret_cast<char*>(&numEnemies), sizeof(int));
		for (int i = 0; i < numEnemies; i++)
			enemyArray[i]->serialize(saveFileHandler);
		itemList.writeList(saveFileHandler);
	}
	saveFileHandler.close();
	return success;
}

void Map::load(string fileName, string password) {
	const int passwordSize = 15;
	string readPasswordString;
	char readPassword[passwordSize];
	bool success = false;
	int numEnemies;
	Item* myItem = nullptr;
	string saveFileInfo;
	saveFileHandler.open(fileName, ios::in | ios::binary);
	if (saveFileHandler.fail()) 
		throw FNFexception();
	saveFileHandler.read(readPassword, passwordSize+1);
	readPasswordString = readPassword;
	if (password != readPasswordString)
	throw incorrectPasswordexception();		
	saveFileHandler.read(reinterpret_cast<char*>(&myHero), sizeof(Hero));
	saveFileHandler.read(reinterpret_cast<char*>(&numEnemies), sizeof(int));
	for (int i = 0; i < numEnemies; i++)
		enemyArray.push_back(Enemy::deserialize(saveFileHandler));
	while (!saveFileHandler.eof()) {
		myItem = Item::deserialize(saveFileHandler);
		if (myItem)
			itemList.appendNode(myItem);
	}
	saveFileHandler.close();
}

void Map::initMapArray(string mapFileName) {
	int input;
	mapFileHandler.open(mapFileName, ios::in);
	if (mapFileHandler.fail())
		throw "EXCEPTION: Could not open map file.";
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mapFileHandler >> input;
			tileArray[i][j] = Tile(input);
		}
	}
}

void Map::spawnItems() {
	numItems = randBetween(10, 20);
	for (int i = 0; i < numItems; i++) {
		switch (randBetween(1, 6)) {
		case 1: itemList.appendNode(new Water()); break;
		case 2: itemList.appendNode(new Potion()); break;
		case 3: itemList.appendNode(new Bread()); break;
		case 4: itemList.appendNode(new Steak()); break;
		case 5: itemList.appendNode(new Sword()); break;
		case 6: itemList.appendNode(new Axe()); break;
		}
	}
}

void Map::spawnEnemies(){
	int enemies = randBetween(30, 40);
	for (int i = 0; i < enemies; i++) {
		switch (randBetween(1, 4)) {
		case 1: enemyArray.push_back(new Thief(Position(randBetween(1, 19), randBetween(1, 9)))); break;
		case 2: enemyArray.push_back(new Bear(Position(randBetween(1, 19), randBetween(1, 9)))); break;
		case 3: enemyArray.push_back(new Zombie(Position(randBetween(1, 19), randBetween(1, 9)))); break;
		case 4: enemyArray.push_back(new Orc(Position(randBetween(1, 19), randBetween(1, 9)))); break;
		}
	}
}

string Map::getPositionDescription(Position pos) {
	string description = "";
	description += getTile(pos).getDescription() + "\n";
	for (int i = 0; i < Enemy::getNumEnemies(); i++) {
		if (enemyArray[i]->getPosition() == pos) {
			description += "A wild " + enemyArray[i]->getName() + " appears!\n";
		}
	}
	description += itemList.getPositionDescriptions(pos);
	return description;
}

bool Map::moveItem(Position originalPos, Position newPos, string name) {
	bool itemFound = false;
	Item* searchResult = findItem(originalPos, name);
	if (searchResult) {
		searchResult->setPosition(newPos);
		itemFound = true;
	}
	return itemFound;
}

Item* Map::findItem(Position pos, string input) {
	return itemList.findNode(pos, input);
}

void Map::learnSpell(Spell &spell) {
	spellQueue.push(spell);
}

Spell Map::castSpell() {
	if (spellQueue.size() < 1)
		throw OOBexception();
	Spell mySpell = spellQueue.front();
	spellQueue.pop();
	return mySpell;
}

Enemy* Map::findEnemy(Position pos, string input) {
	Enemy* enemyPtr = nullptr;
	for (int i = 0; i < Enemy::getNumEnemies(); i++) 
		if (pos == enemyArray[i]->getPosition() && input == enemyArray[i]->getName()) 
			enemyPtr = enemyArray[i];
	return enemyPtr;
}

void Map::deleteEnemy(Enemy* enemy) {
	for (int i = 0; i < Enemy::getNumEnemies(); i++) {
		if (enemy->getPosition() == enemyArray[i]->getPosition() && enemy->getName() == enemyArray[i]->getName()) {
			delete enemyArray[i];
			enemyArray.erase(enemyArray.begin() + i);
		}
	}
}

string Map::takeTurn(string action, string object) {
	string description;
	if (action == "N" || action == "n" || action == "NE" || action == "ne" || action == "E" || action == "e" || action == "SE" || action == "se" || action == "S" || action == "s" || action == "SW" || action == "sw" || action == "W" || action == "w" || action == "NW" || action == "nw") {
		/*if (myHero->move(*this, convertDirection(action))) {
			description += getPositionDescription(myHero->getPosition());
			for (int i = 0; i < Enemy::getNumEnemies(); i++)
				if (enemyArray[i]->checkAggressive() && enemyArray[i]->getPosition() == myHero->getPosition())
					description += enemyArray[i]->attack(*myHero);
		}
		else
			description += "You cannot move there!";*/

		try {
			myHero->move(*this, convertDirection(action));
			description += getPositionDescription(myHero->getPosition());
			for (int i = 0; i < Enemy::getNumEnemies(); i++)
				if (enemyArray[i]->checkAggressive() && enemyArray[i]->getPosition() == myHero->getPosition())
					description += enemyArray[i]->attack(*myHero);
		}
		catch (Position::InvalidPositionexception) {
			description += "You cannot move there.";
		}
	}
	else if (action == "stats" || action == "Stats")
		description += myHero->toString();
	else if (action == "pickup" || action == "get")
		if (myHero->pickup(*this, object))
			description += object + " added to inventory.";
		else
			description += "That item doesn't exist here.";
	else if (action == "drop")
		if (myHero->drop(*this, object))
			description += object + " dropped.";
		else
			description += "You don't have that item.";
	else if (action == "inv" || action == "inventory")
		description += myHero->showInventory(*this);
	else if (action == "equip")
		if (myHero->equip(*this, object))
			description += object + " equipped.";
		else
			description += "You can't equip this item.";
	else if (action == "unequip")
		if (myHero->unequip())
			description += "Items unequipped.";
		else
			description += "There is nothing to unequip.";
	else if (action == "eat")
		description += myHero->eat(*this, object);
	else if (action == "drink")
		description += myHero->drink(*this, object);
	else if (action == "attack")
		description += myHero->attack(*this, object);
	else if (action == "cast")
		description += myHero->cast(*this, object);
	else
		description += "I don't know what that means. Type help for list of commands";
	return description;
}

int Map::randBetween(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

Direction Map::convertDirection(string input) {
	Direction dir;

	if (input == "N" || input == "n")
		dir = N;
	else if (input == "NE" || input == "ne")
		dir = NE;
	else if (input == "E" || input == "e")
		dir = E;
	else if (input == "SE" || input == "se")
		dir = SE;
	else if (input == "S" || input == "s")
		dir = S;
	else if (input == "SW" || input == "sw")
		dir = SW;
	else if (input == "W" || input == "w")
		dir = W;
	else if (input == "NW" || input == "nw")
		dir = NW;

	return dir;
}