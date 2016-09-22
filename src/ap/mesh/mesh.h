#pragma once

#include "../../h.h"

namespace ap {
	namespace mesh {
		enum FIXTURE {
			FORE,
			AFT
		};

		Part *partfactory(FIXTURE f, Tile &, std::string &);
	}
}