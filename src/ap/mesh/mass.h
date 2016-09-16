#ifndef apmeshmass_H
#define apmeshmass_H

#include "../../h.h"

#include "../sprite.h"

#include "grid.h"


namespace ap {
	
	namespace mesh {
		class Mass : public Sprite {
		public:
			Mass();
			~Mass();

			virtual void step();
			virtual void draw();

			virtual void clicked(Tile &);

			Grid grid;
			Grid grid2;

			void add(Part *);

			en::FBO *gobf() const;

		protected:
			en::Region r;
			en::FBO *obf;


			en::Vector<mesh::Part *> parts;

		};
	}
}

#endif