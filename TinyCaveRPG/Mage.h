// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Hero.h"
class Mage : public Hero {
private:
public:
	Mage();
	Mage(int maxHP, int currentHP, Position currentPos);
	string toString();
};

#endif