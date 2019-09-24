// Felipe Oliveira
// 5/12/2019
#include "Potion.h"

Potion::Potion() : Drink("potion", 4) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Potion::Potion(fstream &is) : Drink("potion", 4) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Potion::Potion(string description, int value, Position pos) : Drink(description, value, pos) {
}

void Potion::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}