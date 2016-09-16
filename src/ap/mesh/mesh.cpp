#include "stdafx.h"

#include "mesh.h"

#include "../ship/truss.h"


using namespace ap::mesh;

Part *ap::mesh::partfactory(Tile &t, std::string &type) {

	Part *part = nullptr;

	if (type.compare("truss")) {
		part = new ship::Truss(t);
	}
	else if (type.compare("trussangled")) {
		part = new ship::Truss(t);
	}

	return part;
}