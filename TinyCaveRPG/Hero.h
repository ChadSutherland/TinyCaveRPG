// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef HERO_H
#define HERO_H
#include "Direction.h"
#include "Position.h"
#include "Item.h"
#include <string>
using namespace std;
class Map;
class Hero {
private:

	bool isDead;
	int maxHealth;
	int currentHealth;
	int level;
	int currentEXP;
	int maxEXP;
	int baseDamage;
	int damage;
	bool isEquipped;
	Position currentPosition;
	Position inventoryPosition;

public:
	Hero();
	Hero(int maxHP, int currentHP, Position currentPos);

	int getCurrentLevel() { return level; }
	int getMaxHealth() { return maxHealth; }
	int getCurrentHealth() { return currentHealth; }
	int getCurrentEXP() { return currentEXP; }
	int getMaxEXP() { return maxEXP; }
	int getBaseDamage() { return baseDamage; }
	int getDamage() { return damage; }
	Position getPosition() { return currentPosition; }
	Position getInventoryPosition() { return inventoryPosition; }
	bool getIsDead() { return isDead; }

	void setLevel(int newLevel) { level = newLevel; }
	void setCurrentHP(int hp);
	void setMaxHP(int hp) { maxHealth = hp; }
	void setCurrentEXP(int exp);
	void setMaxEXP(int exp) { maxEXP = exp; }
	void setBaseDamage(int newDamage) {	baseDamage = newDamage;	}
	void setDamage(int newDamage) { damage = newDamage; }
	void setPosition(Position pos) { currentPosition = pos; }
	bool unequip();

	virtual string toString() = 0;

	bool levelUp();

	void move(Map &map, Direction dir); // friend of Map
	bool pickup(Map &map, string input); // friend of Map
	bool drop(Map &map, string input); // friend of Map
	bool equip(Map &map, string input); // friend of map
	string eat(Map &map, string input); // friend of map
	string drink(Map &map, string input); // friend of map
	string showInventory(Map &map);
	string attack(Map &map, string input); // friend of Map
	string cast(Map &map, string input); // friend of Map

	friend string attack(Hero &myHero); // from enemy
};
#endif