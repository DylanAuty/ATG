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
	for(int i = 0; i < floorSizeY; i++){
		for(int j = 0; j < floorSizeX; j++){
			if(i == 0 || j == 0 || i == floorSizeY || j == floorSizeX){
			this->tiles[i][j] = 1;
			}
			else{
				this->tiles[i][j] = 2;
			}
		}
	}
	return;
}
