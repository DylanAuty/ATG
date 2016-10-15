/* Map.cpp
 * Map method implementations.
 *
 * Dylan Auty 2016
 */

#include "Map.hpp"
#include "MapFloor.hpp"
#include <vector>

//TEMPORARY #defines BELOW.
#define MAP_FLOORS_TOTAL 5
#define MAP_X 100
#define MAP_Y 100

Map::Map() {
	//TODO: Import generation parameters from file? Or from menu?
	//TODO: Maybe have constructor with params sent to it?
	this->generate(MAP_FLOORS_TOTAL, MAP_Y, MAP_X);
}

Map::~Map() {
	return;
}

void Map::generate(int numFloors, int floorSizeY, int floorSizeX){
	// Populate the vector with map layers
	for(int i = 0; i < MAP_FLOORS_TOTAL; i++){
		this->floorVec.push_back(MapFloor(floorSizeY, floorSizeX));
	}
	// TODO: Link layers together.
	return;
}


