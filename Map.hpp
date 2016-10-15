/// Map - Class defining the map object.
/** Represents the entire map from top to bottom. Includes map generation routines. Is comprised of a collection of floor objects.
 * TODO: Deal with multiple floors being accessible from one floor, i.e. 2 staircases go to different places. Maybe using pointers for staircase tiles.
 *
 * Dylan Auty, 2016
 */

#ifndef MAP_HPP
#define MAP_HPP
#include "MapFloor.hpp"
#include <vector>

class Map {
	public:
		Map();		///< Constructor, calls map generation routine
		~Map();		///< Destructor, possibly useless at this point

		int totalFloors;	///< Total number of floors in map.
		int floorDim_x;		///< Max floor size, cols.
		int floorDim_y;		///< Max floor size, lines.
		
		std::vector <MapFloor> floorVec;	///< Array of MapFloor object instances denoting all floors in the map.

	private:
		void generate(int numFloors, int floorSizeY, int floorSizeX);	///< Map generation routine, called by constructor.


};

#endif
