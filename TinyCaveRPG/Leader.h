// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Hero.h"
class Leader : public Hero {
private: 
public:
	Leader();
	Leader(int maxHP, int currentHP, Position currentPos);
	string toString();
};

#endif