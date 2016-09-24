#ifndef apmeshpart_H
#define apmeshpart_H

#include "../../h.h"

#include "../sprite.h"

#include "mesh.h"
#include "tile.h"

namespace ap {
	
	namespace mesh {

		class Part : public Sprite {
		public:
			bool SEETHROUGH;

			enum SIDE { SINGLE, UNI, DUO, OPPOSITE, TRI, QUAD, JUNCTION };

			Part(FIXTURE, Tile &, sort_t);

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw(PASS);

			Tile &tile;
			Emitter *em;

			const FIXTURE fixture;

			virtual void connect();
			virtual void* prefit();
			virtual void refit();

			bool bools[8];

			template<class T> bool* friends() {
				bool bools[8];
				std::fill_n(bools, 8, false);

				Tile **all = tile.gneighbors();

				for (int i = 0; i < 8; i++) {
					Tile *t = all[i];

					if (nullptr == t)
						continue;

					_ASSERT(t);

					T* type = static_cast<T*> (t->gpart(fixture));

					bools[i] = !!type;
				}

				return bools;
			};

		protected:

		private:

		};
	}
}

#endif