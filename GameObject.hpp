/// Generic class defining any object which exists in the game world.
/** Represents the general characteristics which any object can
 * have.
 *
 * Dylan Auty, 2016
 */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject {
	public:
		GameObject();

		// Object attributes
		char renderChar;	///< ASCII character to use for object rendering.
		
		bool passable; 		///< Whether the object, if set on the floor, will obstruct another object moving into its space.
		bool fillable;		///< Whether the object has an inventory, e.g. boxes
		int health;			///< All objects can be destroyed because hey why not.

}

#endif
