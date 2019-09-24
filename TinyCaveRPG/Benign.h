// Daniyar Aubekerov
// 5/12/2019

#pragma once
#ifndef BENIGN_H
#define BENIGN_H
#include "Enemy.h"
class Benign : public Enemy {
private:
	bool isAggressive;
public:
	Benign(string newName, int damage, int maxHP, Weapon* weapon);
	Benign(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon);
	~Benign();
	virtual string toString() = 0;
	virtual void serialize(fstream &os) = 0;
	bool checkAggressive() { return isAggressive; }
};
#endif