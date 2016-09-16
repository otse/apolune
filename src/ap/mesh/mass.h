#ifndef apmeshmass_H
#define apmeshmass_H

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

			virtual void clicked(Tile &);

			void pose();

			Grid &ggrid();
			Grid &ggrid2();

			en::FBO *gfbo() const;
			void add(Part *);

		protected:
			en::Region r;
			en::FBO *fbo;
			Sprite *sprite;

			Grid grid;
			Grid grid2;

			en::Vector<mesh::Part *> parts;

		};
	}
}

#endif