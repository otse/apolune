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
			Part(FIXTURE, Tile &);

			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw(PASS);

			Tile &tile;
			Emitter *em;

			const FIXTURE fixture;

			virtual void connect();
			virtual void refit();

		protected:

		private:

		};
	}
}

#endif