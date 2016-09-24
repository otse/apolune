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

			enum CONNECT { SINGLE, UNI, DUO, OPPOSITE, TRI, QUAD, JUNCTION };
			// static const en::Region[7] CONNECTS;

			struct Attitude {
				float degrees;
				CONNECT connect;
			};

			Part(FIXTURE, Tile &, sort_t);
			~Part();

			virtual void click();
			virtual void hover(mou::Hover h);
			virtual void step();
			virtual void draw(PASS);

			bool SEETHROUGH;
			Tile& tile;
			Emitter* em;

			const FIXTURE fixture;

			virtual void connect();
			virtual void refit() = 0;

			// todo: entangle is a nonsensical word here
			virtual const Attitude* entangle() const;

			bool bools[8];

			template<class T> bool* friends() {
				//bool bools[8]; // = {!!0,!!0,!!0,!!0,!!0,!!0,!!0,!!0};
				//std::fill_n(bools, 8, false);

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

			#define TOP 		bools[0]
			#define TOPRIGHT 	bools[1]
			#define RIGHT 		bools[2]
			#define BOTTOMRIGHT bools[3]
			#define BOTTOM 		bools[4]
			#define BOTTOMLEFT 	bools[5]
			#define LEFT 		bools[6]
			#define TOPLEFT 	bools[7]

			template<class T>
			const Attitude* prefit() {
				friends<T>();

				const Attitude* attitude = entangle();

				return attitude;
			}

		protected:

		private:

		};
	}
}

#endif