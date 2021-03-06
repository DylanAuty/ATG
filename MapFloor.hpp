/// MapFloor class, defines a single floor of the map.
/** Represents a single floor of the map, of the 
 * size specified or a default size if not. 
 * Name is MapFloor to differentiate from floor tile.
 *
 * Dylan Auty, 2016
 */

#ifndef MAPFLOOR_HPP
#define MAPFLOOR_HPP

class MapFloor {
	public:
		MapFloor(int floorSizeY, int floorSizeX);
		//~MapFloor();
		
		// TODO: Fix this hardcoded crap	
		int tiles[100][100];	///< PLACEHOLDER: Contains the floor tiles, bool for now

	private:
		void generate(int floorSizeY, int floorSizeX);		///< Fills tile array with different kinds of tiles.
		int getDir(int prevDir, int weights[4]); ///< Returns a random direction for use with drunken walk generation.
};

#endif
