#ifndef apcraftgrid_H
#define apcraftgrid_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Grid : public Sprite {
		public:
			Grid();
			~Grid();

			virtual void step();

		protected:
			int asd;
		};
	}
}

#endif