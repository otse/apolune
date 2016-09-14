#ifndef apshiptruss_H
#define apshiptruss_H

#include "../../h.h"

#include "all.h"

namespace ap {
	
	namespace ship {
		class Truss : public mesh::Part {
		public:
			struct Model {
				Draws::Model m;
				int strength;
				int weight;
			};

			static const Model single;
			static const Model uni;
			static const Model duo;
			static const Model opposite;
			static const Model tri;
			static const Model quad;

			static const Draws::Model jjunction;

			Truss(Tile &);
			~Truss();

			virtual void click();
			virtual void hover(mou::Hover h);

			virtual void step();
			virtual void draw();

			virtual void connect();
			virtual void refit();

			Model &gmodel();
			Wall *gwall();

		private:
			const Model *model;
			Wall *wall;
			Sprite *outline;

			void junction(int,int);
			Sprite *junctions[4];
		};
	}
}

#endif