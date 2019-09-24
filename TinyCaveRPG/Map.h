// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef MAP_H
#define MAP_H
#include "Tile.h"
#include "Hero.h"
#include "Item.h"
#include "Consumable.h"
#include "Food.h"
#include "Drink.h"
#include "Axe.h"
#include "Bread.h"
#include "Steak.h"
#include "Water.h"
#include "Potion.h"
#include "Sword.h"
#include "Weapon.h"
#include "Spell.h"
#include "Enemy.h"
#include "Benign.h"
#include "Vicious.h"
#include "Thief.h"
#include "Bear.h"
#include "Orc.h"
#include "Zombie.h"
#include "Position.h"
#include "ItemLinkedList.h"
#include "Leader.h"
#include "Mage.h"
#include "Warrior.h"
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
class Map {
private:
	const int ROWS = 20;
	const int COLS = 10;
	unsigned seed;
	int numItems;
	Tile** tileArray;
	Hero* myHero;
	queue<Spell> spellQueue;
	ItemLinkedList itemList;
	vector<Enemy*> enemyArray;
	fstream mapFileHandler;
	fstream saveFileHandler;

public:
	class FNFexception {};
	class incorrectPasswordexception {};
	class OOBexception {};

	Map(string mapFile, int myClass);
	Map(string mapFile, string saveFile, string password);
	~Map();

	int getRows() { return ROWS; }
	int getCols() { return COLS; }
	int getNumItems() { return numItems; }
	Tile& getTile(Position pos) { return tileArray[pos.getRow()][pos.getCol()]; }
	string getPositionDescription(Position pos);

	bool save(string fileName, string password);
	void load(string fileName, string password);
	string takeTurn(string action, string object);
	void initMapArray(string mapFileName = "map.txt");
	void spawnItems();
	void spawnEnemies();
	bool moveItem(Position originalPos, Position newPos, string name);
	Item* findItem(Position pos, string input);
	Enemy* findEnemy(Position pos, string input);

	template<class T> 
	void addItem(T item) {
		itemList.appendNode(item);
	}
	
	template<class T>
	void deleteItem(T item) {
		itemList.deleteNode(item);
	}

	void learnSpell(Spell &spell);
	Spell castSpell();

	void deleteEnemy(Enemy* enemy);
	bool isGameOver() { return myHero->getIsDead(); }

	int randBetween(int min, int max);
	Direction convertDirection(string input);

	friend string showInventory(Map &map); // from hero
	friend bool move(Map &map, Direction dir); // from hero
	friend bool pickup(Map &map, string input); // from hero
	friend bool drop(Map &map, string input); // from hero
	friend bool equip(Map &map, string input); // from hero
	friend string eat(Map &map, string input); // from hero
	friend string drink(Map &map, string input); // from hero
	friend bool attack(Map &map, string input); // from hero
	friend void dropItem(Map &map); // from enemy
	friend string cast(Map &map, string input); // from hero
};
#endif