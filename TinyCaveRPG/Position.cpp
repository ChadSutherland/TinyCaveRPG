// Chad Sutherland
// 5/12/2019
#include "Position.h"
#include "Map.h"

Position::Position() {
	Position(5, 5);
}

Position::Position(int row, int col) {
	rowIndex = row;
	columnIndex = col;
}

void Position::setPosition(Position newPos) {
	rowIndex = newPos.rowIndex;
	columnIndex = newPos.columnIndex;
}

void Position::setPosition(Direction dir) {
	switch (dir) {
	case N:
		rowIndex--;
		break;
	case NE:
		columnIndex++;
		rowIndex--;
		break;
	case E:
		columnIndex++;
		break;
	case SE:
		columnIndex++;
		rowIndex++;
		break;
	case S:
		rowIndex++;
		break;
	case SW:
		columnIndex--;
		rowIndex++;
		break;
	case W:
		columnIndex--;
		break;
	case NW:
		columnIndex--;
		rowIndex--;
		break;
	}
}

bool Position::operator == (const Position &right) {
	bool status = false;
	if (rowIndex == right.rowIndex && columnIndex == right.columnIndex)
		status = true;
	return status;
}

ostream &operator << (ostream &strm, const Position &obj)
{
	strm << "(" << obj.columnIndex << "," << obj.rowIndex << ")";
	return strm;
}

istream &operator >> (istream &strm, Position &obj) {
	Position temp(obj);
	strm >> temp.rowIndex;
	strm >> temp.columnIndex;
	obj.setPosition(temp);
	return strm;
}

void Position::setPosition(Map &map, Direction dir) {
	Position newPos = *this;
	newPos.setPosition(dir);
	if (newPos.getRow() >= map.getRows() || newPos.getCol() >= map.getCols() || map.getTile(newPos).checkWall())
		throw InvalidPositionexception();

		setPosition(newPos);
}