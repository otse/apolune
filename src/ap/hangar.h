#ifndef aphangar_H
#define aphangar_H

#include "../h.h"
#include "mover.h"

// todo remove mover depend
namespace ap {

	class Hangar : public Mover {
	public:
		Hangar();
		~Hangar();
		
		virtual void step();
		void post();

		craft::Craft *craft;
		craft::Grid *grid;

	protected:
		int asd;

		Sprite *clawbase;

	};
}
#endif