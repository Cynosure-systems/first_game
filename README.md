# First game

This is the first instance of a 2D platformer with basic mechanics.

## TODO:
Structure : 
- [ ] Add scene
- [ ] Draw from the scene
- [ ] Finish terrain basic
- [ ] Add entity
- [ ] Add player
- [ ] Add collision
- [ ] Add stock sprites
- [ ] Add enemy
- [ ] Add hitbox
- [ ] Add input


## Classes:

#### Game 
The game class containing the necessary to go through the main game loop (update, render the scene)

### Graphics

#### Scene:
The scene is the class that get all object to draw and update into the game.
It stores terrains, entities but should not hold the player for now as there will
be only one scene. If there is no scene we need to manually add in the game class
all the object which could bloat the code for the game classe for every object added.

#### MapManager
The manager of the maps when there will be more than one level (for the moment only manages a single level)

#### Animation
A class to take care of animating the entities, goes through the sprites

### Creatures

#### Physics: No need, the physics will be added in the entities classes, or the entities itself

#### Entity:
Abstraction of all entities in the game, players and enemies
- hitbox
- position
- sprite
- velocity

#### Player:
The player of the game, inherits from the entity
- input
- jump
- move
- sprite
- hitbox

#### Enemy:
Abstraction of all the enemies of the game, an enemy will inherit from this class
- AI (path)
- interaction with player

### Objects 

#### Object
An abstraction of all the objects in the game

#### BonusItem
An item that gives additional strenghs to the player

#### Weapon
A class for the weapons in the game : abstraction
