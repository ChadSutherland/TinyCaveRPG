// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"
#include <string>
using namespace std;
class Position;
class Map;
ostream &operator << (ostream &, const Position &);
istream &operator >> (istream &, Position &);
class Position {
private:
	int rowIndex;
	int columnIndex;
public:

	class InvalidPositionexception {};

	Position();
	Position(int row, int col);

	int getRow() { return rowIndex; }
	int getCol() { return columnIndex; }

	void setRow(int newRow) { rowIndex = newRow; }
	void setCol(int newCol) { columnIndex = newCol;  }
	void setPosition(Position newPos);
	void setPosition(Direction dir);
	void setPosition(Map &map, Direction dir);
	bool operator == (const Position &right);

	friend ostream &operator << (ostream &, const Position &);
	friend istream &operator >> (istream &, Position &);
};
#endif