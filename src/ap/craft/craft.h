#ifndef apcraftcraft_H
#define apcraftcraft_H

#include "../../h.h"

#include "../../en/fbo.h"

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
			virtual void draw();

			void pose();

			en::FBO *gfbo();
			void add(Part *);

			Grid grid;

			int gtop();
			int gleft();

			bool crosssection;

		protected:
			en::Region r;
			en::FBO *ship;
			Sprite *sprite;

			en::Vector<Part *> parts;

			int top;
			int left;
		};
	}
}

#endif