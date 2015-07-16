# apolune
starbound knockoff
a

Classes of /src/ap:

`World` aka game. this class acts like a singleton. it renders the different fbos. it is rather bloated. also, it renders sprites like /src/en renders draws

`Sprite` is an extended `/en/Draws` meant to show in-world.

`Objects` extends `Sprite`. this is a base for game-objects, or very dormant game objects that need a tooltip

`Mover` is a destination for physics. Niy

`Hangar` the hangar. also hangar-related apparatus

`Planet` is not done

Folders of /src/ap
`/craft` this folder means both spacecraft and literal craft. this contains shipbuilding

`craft/Craft` le spacecraft. its a sprite, so that it gets posed, rendered and stepped. has its own draw routine into an fbo.

`craft/Grid` holds tiles
`craft/Tile` a grid tile that you can click to place a `Part`
`craft/Part` any piece of a spaceship. more of a marker class
`craft/Truss` the outside of the spaceship
`craft/Wall` placed onto truss