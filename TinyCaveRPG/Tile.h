// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef TILE_H
#define TILE_H
#include <string>
using namespace std;
enum Terrain {
	RESERVED,
	WALL, 
	FOREST, 
	VALLEY, 
	CAVERN,
	HOUSE,
	ROAD,
	VALLEYENTRANCE,
	CAVEENTRANCE,
	HOUSEENTRANCE,
	CAVEPASSAGE
};
class Tile {
private:
	Terrain terrainType;
	string description;
	bool isWall;

public:
	Tile();
	Tile(int ter);

	string getDescription() const { return description; }
	bool checkWall() const { return isWall; }

	void setTileType(Terrain ter);
};
#endif