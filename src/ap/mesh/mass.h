#ifndef apmassgrid_H
#define apmassgrid_H

#include "../../h.h"

#include "../sprite.h"
#include "mesh.h"


namespace ap {
	
	namespace mesh {
		class Mass : public Sprite {
		public:
			Mass();
			~Mass();

			virtual void step();

		protected:
			int a;
		};
	}
}

#endif