#include "stdafx.h"

#include "mesh.h"

#include "block.h"


using namespace ap::mesh;

Part *ap::mesh::partfactory(Tile &t, std::string &type) {

	Part *part = nullptr;

	if (0 == type.compare("hull")) {
		part = new Block(t);
	}
	else if (0 == type.compare("truss")) {
	}
	else if (0 == type.compare("trussangled")) {

	}

	return part;
}