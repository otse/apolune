#ifndef aphangar_H
#define aphangar_H

#include "../h.h"
#include "mover.h"

#include "craft/craft.h"

// todo remove mover depend
namespace ap {

	class Hangar : public Mover {
	public:
		Hangar();
		~Hangar();
		
		virtual void step();
		void post();

		craft::Grid *grid;

	protected:
		int asd;

		Sprite *clawbase;

	};
}
#endif