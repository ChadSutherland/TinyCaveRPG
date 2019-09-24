// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
class Warrior : public Hero {
private:
public:
	Warrior();
	Warrior(int maxHP, int currentHP, Position currentPos);
	string toString();
};

#endif