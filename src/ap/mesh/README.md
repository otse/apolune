# Mesh

The mesh is the grid and its tiles. This folder contains the low-level parts that most game objects inherit.

Quick rundown of the classes;
`Mass` Any floating collection of blocks in the game (e.g. asteroids and ships, or pieces of asteroids and ships, excluding players).
`Grid` A mass has a grid, which takes care of tiles.
`Tile` Can register a foreground and background part (aka `fore`/`aft`). Keeps a reference to its neighbours; if a part wants to know who surrounds it, it inquires this from the tile that it's sitting on.
`Part` Any game object that wants to be placed.

The folder does not keep all its inheritors/extenders, only the basic ones like `block`; instead, ap/parts/ keeps things like the piston and airlock.
