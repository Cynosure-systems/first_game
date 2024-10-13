# First game

This is the first instance of a 2D platformer with basic mechanics.

### TODO:
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

### Classes:

#### Scene:
The scene is the class that get all object to draw and update into the game.
It stores terrains, entities but should not hold the player for now as there will
be only one scene. If there is no scene we need to manually add in the game class
all the object which could bloat the code for the game classe for every object added.

#### Physics:
- collisions system
- gravity

#### Entity:
- hitbox
- position
- sprite
- velocity

#### Player:
- input
- jump
- move
- sprite
- hitbox

#### Enemy:
- AI (path)
- interaction with player