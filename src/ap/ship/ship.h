#ifndef apshipship_H
#define apshipship_H

#include "../../h.h"

#include "../../en/fbo.h"
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
			virtual void draw();

			void pose();

			en::FBO *gfbo() const;
			void add(mesh::Part *);

			mesh::Grid &ggrid();
			mesh::Grid &ggrid2();
			
			void refbo();

			bool crosssection;

		protected:
			en::Region r;
			en::FBO *fbo;
			Sprite *sprite;

			en::Vector<mesh::Part *> parts;

			mesh::Grid grid;
			mesh::Grid grid2;
		};
	}
}

#endif