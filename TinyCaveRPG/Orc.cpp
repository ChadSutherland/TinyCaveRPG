// Daniyar Aubekerov
// 5/12/2019
#include "Orc.h"
#include "Axe.h"
#include <fstream>
Orc::Orc(fstream &is) : Vicious("orc", 3, 6,nullptr) {
	int currentHP;
	Position pos;
	is.read(reinterpret_cast<char*>(&currentHP), sizeof(int));
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setHealth(currentHP);
	setPosition(pos);
	setWeapon(new Axe(getPosition()));
}

Orc::Orc(Position pos) : Vicious("orc", pos,
	3, 6, 6,new Axe(pos))
{
}

Orc::Orc(int currentHP, Position pos) : Vicious("orc", pos,
	3, currentHP, 6,new Axe(pos))
{
}

string Orc::toString() {
	return getName();
}

void Orc::serialize(fstream &os) {
	int id = getID();
	int hp = getCurrentHealth();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&hp), sizeof(int)); 
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}