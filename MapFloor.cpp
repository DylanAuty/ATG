/* MapFloor.cpp
 * MapFloor method implementations.
 *
 * Dylan Auty 2016
 */

#include "MapFloor.hpp"

MapFloor::MapFloor(int floorSizeY, int floorSizeX) {
	//Placeholder code.
	this->generate(floorSizeY, floorSizeX);
}

void MapFloor::generate(int floorSizeY, int floorSizeX) {
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			this->tiles[i][j] = '@';
		}
	}
	return;
}
