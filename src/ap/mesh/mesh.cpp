#include "stdafx.h"

#include "mesh.h"

#include "block.h"
#include "../ship/truss.h"


using namespace ap::mesh;

Part *ap::mesh::partfactory(Tile &t, std::string &type) {

	Part *part = nullptr;

	if (0 == type.compare("hull")) {
		part = new Block(t);
	}
	else if (0 == type.compare("truss")) {
		part = new ship::Truss(t);
	}
	else if (0 == type.compare("trussangled")) {
		part = new ship::Truss(t);
	}

	return part;
}