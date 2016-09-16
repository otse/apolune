#ifndef apshipship_H
#define apshipship_H

#include "../../h.h"

#include "../sprite.h"

#include "all.h"

namespace ap {
	
	namespace ship {
		class Ship : public mesh::Mass {
		public:
			Ship();
			~Ship();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			//virtual void draw();

			//virtual void clicked(mesh::Tile &t);

			bool crosssection;

		protected:
			

		};
	}
}

#endif