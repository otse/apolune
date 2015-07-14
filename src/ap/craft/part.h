#ifndef apcraftpart_H
#define apcraftpart_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Part : public Sprite {
		protected:
		// abstract
			Part(const Model);
			~Part();

		public:

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