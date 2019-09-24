// Daniyar Aubekerov
// 5/12/2019
#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Position.h"
#include "Weapon.h"
#include <string>
using namespace std;
class Hero;
class Enemy {
private:
	static int numEnemies;

	string name;
	Position currentPosition;
	int damage;
	int currentHealth;
	int maxHealth;
	Weapon* weapon;

public:
	static int getNumEnemies() { return numEnemies; }
	static Enemy* deserialize(fstream &is);

	Enemy(string newName, int damage, int maxHP, Weapon* weapon);
	Enemy(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon);
	~Enemy();

	void setName(string newName) { name = newName; }
	void setPosition(Position pos) { currentPosition = pos; }
	void setDamage(int newDamage) { damage = newDamage; }
	void setHealth(int health);
	void setMaxHealth(int health) { maxHealth = health; }
	void setWeapon(Weapon* newWeapon) { weapon = newWeapon; }

	string getName() { return name; }
	Position getPosition() { return currentPosition; }
	int getDamage() { return damage; }
	int getCurrentHealth() { return currentHealth; }
	int getMaxHealth() { return maxHealth; }

	int randBetween(int mix, int max);

	virtual bool checkAggressive() = 0;
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;

	string attack(Hero &myHero); //friend of hero
	string dropWeapon(Map &map); // friend of map
};
#endif