#ifndef apcraftcraft_H
#define apcraftcraft_H

#include "../../h.h"

#include "../sprite.h"

namespace ap {
	
	namespace craft {
		class Craft : public Sprite {
		public:
			Craft();
			~Craft();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();

		protected:
			en::Vector<Part *> parts;

			int asd;
		};
	}
}

#endif