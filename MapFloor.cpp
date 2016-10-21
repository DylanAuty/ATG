/* MapFloor.cpp
 * MapFloor method implementations.
 *
 * Dylan Auty 2016
 */

#include "MapFloor.hpp"
#include <ctime>
#include <cstdlib>
#include <vector>

MapFloor::MapFloor(int floorSizeY, int floorSizeX) {
	//Placeholder code.
	this->generate(floorSizeY, floorSizeX);
}

void MapFloor::generate(int floorSizeY, int floorSizeX) {
	// First pass: define all passable tiles.
	// Denoted by 1 for passable or 0 for impassable (default)
	
	for(int i = 0; i < floorSizeY; i++){
		for(int j = 0; j < floorSizeX; j++){		
			if(i == 0 || j == 0 || i == floorSizeY || j == floorSizeX){
				this->tiles[i][j] = 'o';
			}
			else{
				this->tiles[i][j] = ' ';
			}
		}
	}
	// Method 1: Drunken walk + boxes
	// Select a random tile to start from
	srand(time(NULL));
	int currX, currY;
	int stepNum = 500;
	int dir;

	currX = rand() % (floorSizeX - 1);
	currY = rand() % (floorSizeY - 1);
	
	dir = rand() % 4;
	int dirWeights[4] = {80, 5, 5, 5};	// These don't need to add to 100

	for(int i = 0; i < stepNum; i++){
		dir = getDir(dir, dirWeights);
		
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
			//default:
			//	currX -= 10;
		}
		// Sanity check direction then assign to currX
		if(currX > floorSizeX - 1){
			currX = floorSizeX - 1;
		}
		if(currX < 1){
			currX = 1;
		}
		if(currY > floorSizeY - 1){
			currY = floorSizeY - 1;
		}
		if(currY < 1){
			currY = 1;
		}
		// Assign tile (currY, currX).
		this->tiles[currY][currX] = '#';

	}


	return;
}

int MapFloor::getDir(int prevDir, int weights[4]){
	// Creates a distribution of weights/dirs, then samples from it.
	// Order of weights is [prevDir, (prevDir + 1) % 4, (prevDir + 2) % 4, (prevDir + 3) % 4)
	int weightTotal = weights[0] + weights[1] + weights[2] + weights[3];
	//int dist[weightTotal];
	// Populate distribution
	
	std::vector<int> dist;
	for(int i = 0; i < 4; i++){	// Iterate over weights.
		for(int j = 0; j < weights[i]; j++){	// For elems in distribution
			dist.push_back((prevDir + i) % 4);
		}
	}
	// Sample from distribution.
	int randIndex = rand() % weightTotal;
	return dist[randIndex];
}



