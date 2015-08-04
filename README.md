# apolune
starbound knockoff /w spaceships

Classes of _/src/ap_:

(Look below for non-classes and headers)

`World` aka game. this class acts like a singleton. it renders the different fbos. it is rather bloated. also, it renders sprites like /src/en renders draws

`Sprite` is an extended `/src/en/Draws` meant to show in-world.

`Object` extends `Sprite`. this is a base for game-objects, or very dormant game objects that need a tooltip. most extenders found in /objects

`Light` extends `Sprite`

`Mover` is a destination for physics. Niy

`Hangar` the hangar. also hangar-related apparatus

`Planet` is not done

`Ply` the player class

`CLI` the Command-line interface

Folders of /src/ap

`/craft` this folder means both spacecraft and literal craft. this contains shipbuilding

`craft/Craft` le spacecraft. its a sprite, so that it gets posed, rendered and stepped. has its own draw routine into an fbo.

`craft/Grid` holds tiles

`craft/Tile` a grid tile that you can click to place a `Part`

`craft/Part` any piece of a spaceship. more of a marker class

`craft/Truss` the outside of the spaceship

`craft/Wall` placed onto truss

Non-class and headers:

`h` contains forward declarations and some global external definitions, which are defined in `main.cpp`

`ap/def .cpp & .h` contains most regions, textures and colors

`ap/bulk.cpp` this contains glyphs for some fonts so it's very lengthy

Unused
`ap/Asteroid`

