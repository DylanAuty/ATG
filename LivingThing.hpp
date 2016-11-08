/// Class to represent any living object, i.e. the player, NPCs, enemies.
/** All characteristics shared by moving living things are here.
 * Includes any undead things, if they end up in the game, since I mean living in that they're
 * not just inanimate things which do nothing. Inherits GameObject.
 *
 * Dylan Auty, 2016
 */

#ifndef LIVINGTHING_HPP
#define LIVINGTHING_HPP

class LivingThing : public GameObject {
	public:
		LivingThing();

		// Living thing attributes
		int maxSpeed;	///< Maximum movement speed in units/turn
		int health;		///< Amount of health that the living thing has
		

}

#endif
