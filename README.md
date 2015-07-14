# apolune
starbound knockoff
a

Classes of /src/ap:

`World` aka game. this class acts like a singleton. it renders the different fbos. it is rather bloated. also, it renders sprites like /src/en renders draws

`Sprite` is an extended `/en/Draws` meant to show in-world.

`Objects` extends `Sprite`. this is a base for game-object, or very dormant game objects that need a tooltip

`Mover` is a destination for physics. Niy

`Hangar` the hangar. also hangar-related apparatus

`Ship` todo: refactor move to craft?

`Planet` is not done

Folders of /src/ap
`/craft` this folder means both spacecraft and literal craft. this contains shipbuilding

`Craft` le spacecraft. its a sprite, so that it gets posed, rendered and stepped. has its own draw routine into an fbo.