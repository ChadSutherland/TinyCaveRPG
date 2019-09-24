// Felipe Oliveira
// 5/12/2019
#pragma once
#ifndef SPELL_H
#define SPELL_H
#include "Weapon.h"

class Spell : public Weapon {
private: 

public:
	Spell(string description, int value, Position pos);
	~Spell();


	string toString();
	void serialize(fstream &os) {}
};
#endif