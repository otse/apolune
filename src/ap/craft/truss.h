#ifndef apcrafttruss_H
#define apcrafttruss_H

#include "../../h.h"

#include "part.h"

namespace ap {
	
	namespace craft {
		class Truss : public Part {
		public:
			Truss(const Model m);
			~Truss();

			

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

		protected:
			int x;
			int y;
		};
	}
}

#endif