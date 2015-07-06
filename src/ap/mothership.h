#ifndef apmothership_H
#define apmothership_H

#include "../h.h"
#include "mover.h"

#include "craft/craft.h"

// todo remove mover depend
namespace ap {

	class Mothership : public Mover {
	public:
		Mothership();
		~Mothership();
		
		virtual void step();
		void post();
		craft::Grid grid;

	protected:
		int asd;


		Sprite *clawbase;

	};
}
#endif