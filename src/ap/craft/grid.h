#ifndef apcraftgrid_H
#define apcraftgrid_H

#include "../../h.h"

namespace ap {
	
	namespace craft {
		class Grid {
		public:
			Grid();
			~Grid();

			void step();

		protected:
			int asd;
		};
	}
}

#endif