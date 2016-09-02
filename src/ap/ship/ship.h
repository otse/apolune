#ifndef apcraftcraft_H
#define apcraftcraft_H

#include "../../h.h"

#include "../../en/fbo.h"
#include "../sprite.h"

namespace ap {
	
	namespace ship {
		class Ship : public Sprite {
		public:
			Ship();
			~Ship();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			virtual void draw();

			void pose();

			en::FBO *gfbo();
			void add(Part *);

			Grid grid;
			
			void refbo();

			bool crosssection;

		protected:
			en::Region r;
			en::FBO *fbo;
			Sprite *sprite;

			en::Vector<Part *> parts;
		};
	}
}

#endif