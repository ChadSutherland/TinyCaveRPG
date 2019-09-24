// Daniyar Aubekerov
// 5/12/2019
#pragma once
#ifndef VICIOUS_H
#define VICIOUS_H
#include "Enemy.h"
class Vicious : public Enemy {
private:
	bool isAggressive;
public:
	Vicious(string newName, int damage, int maxHP, Weapon* weapon);
	Vicious(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon);
	~Vicious();
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
	bool checkAggressive() { return isAggressive; }
};

#endif