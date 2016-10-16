/* MapFloor.cpp
 * MapFloor method implementations.
 *
 * Dylan Auty 2016
 */

#include "MapFloor.hpp"
#include <ctime>
#include <cstdlib>

MapFloor::MapFloor(int floorSizeY, int floorSizeX) {
	//Placeholder code.
	this->generate(floorSizeY, floorSizeX);
}

void MapFloor::generate(int floorSizeY, int floorSizeX) {
	// First pass: define all passable tiles.
	// Denoted by 1 for passable or 0 for impassable (default)
	/*
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
	*/

	// Method 1: Drunken walk + boxes
	// Select a random tile to start from
	srand(time(NULL));
	int currX, currY;
	int stepNum = 1000;
	int dir;

	currX = rand() % (floorSizeX - 1);
	currY = rand() % (floorSizeY - 1);
	
	for(int i = 0; i < stepNum; i++){
		dir = rand() % 3;	// Pick a compass dir, 0 = N, 1 = E, 2 = S, 3 = W
		switch(dir){
			case 0:	// N
				currY -= 1;
				break;
			case 1: // E
				currX += 1;
				break;
			case 2: // S
				currY += 1;
				break;
			case 3: // W
				currX -= 1;
				break;
		}
		// Sanity check direction then assign to currX
		if(currX > floorSizeX){
			currX = floorSizeX;
		}
		if(currX < 0){
			currX = 0;
		}
		if(currY > floorSizeY){
			currY = floorSizeY;
		}
		if(currY < 0){
			currY = 0;
		}
		// Assign tile (currY, currX) to 1.
		this->tiles[currY][currX] = 1;

	}
	return;
}
