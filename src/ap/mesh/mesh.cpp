#include "stdafx.h"

#include "mesh.h"

#include "tile.h"
#include "block.h"


using namespace ap::mesh;

Part *ap::mesh::partfactory(FIXTURE f, Tile &t, std::string &type) {

	Part *part = nullptr;

	if (0 == type.compare("hull")) {
		part = new Block(f, t);
	}
	else if (0 == type.compare("truss")) {
	}
	else if (0 == type.compare("trussangled")) {

	}

	return part;
}