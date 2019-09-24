// Felipe Oliveira
// 5/12/2019
#include "Bread.h"

Bread::Bread() : Food("bread", 1) {
	setPosition(Position(randBetween(1, 9), randBetween(1, 19)));
}

Bread::Bread(fstream &is) : Food("bread", 1) {
	Position pos;
	is.read(reinterpret_cast<char*>(&pos), sizeof(Position));
	setPosition(pos);
}

Bread::Bread(string description, int value, Position pos) 
	: Food(description, value, pos) {
}

void Bread::serialize(fstream &os) {
	int id = getID();
	Position pos = getPosition();
	os.write(reinterpret_cast<char*>(&id), sizeof(int));
	os.write(reinterpret_cast<char*>(&pos), sizeof(Position));
}