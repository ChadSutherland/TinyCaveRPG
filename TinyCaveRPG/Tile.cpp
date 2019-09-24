// Chad Sutherland
// 5/12/2019
#include "Tile.h"

Tile::Tile() {
	setTileType(FOREST);
}

Tile::Tile(int ter) {
	setTileType(static_cast<Terrain>(ter));
}

void Tile::setTileType(Terrain ter) {
	terrainType = ter;
	switch (terrainType) {
	case RESERVED:
		description = "ERROR:inventory";
		isWall = true;
	case WALL:
		description = "";
		isWall = true;
		break;
	case FOREST:
		description = "You are in a thickly wooded forest.";
		isWall = false;
		break;
	case VALLEY:
		description = "You are in a wide and rocky valley.";
		isWall = false;
		break;
	case CAVERN:
		description = "You are in a dark, wet cavern.";
		isWall = false;
		break;
	case HOUSE:
		description = "You are in a farmhouse. There is a well plunging into the ground.";
		isWall = false;
		break;
	case ROAD:
		description = "You are on a narrow and bumpy dirt road.";
		isWall = false;
		break;
	case VALLEYENTRANCE:
		description = "You are at the mouth of an expansive valley.";
		isWall = false;
		break;
	case CAVEENTRANCE:
		description = "A gap wide enough to squeeze through is nearly hidden in the rock face.";
		isWall = false;
		break;
	case HOUSEENTRANCE:
		description = "Ahead there is an abandoned and dilapidated farmhouse.";
		isWall = false;
		break;
	case CAVEPASSAGE:
		description = "A narrow passage leads you deep underground.";
		isWall = false;
		break;
	}
}