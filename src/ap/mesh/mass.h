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

			void add(Part *);
			void remove(Part *);

			bool sleeping;

			Grid grid;

			en::FBO *gobf() const;
			en::FBO *gshadow() const;

		protected:
			en::Region r;

			en::FBO *obf;
			en::FBO *outside;

			en::FBO *shadow;

			en::FBO *contiguous;

			std::vector<mesh::Part *> fores;
			std::vector<mesh::Part *> afts;

		};
	}
}

#endif