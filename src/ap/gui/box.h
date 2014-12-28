#ifndef apguibox_H
#define apguibox_H

#include "../../h.h"

#include "../../en/draws.h"
#include "element.h"

namespace ap {
	namespace gui {
		class Box : public en::Draws {
		public:
			Box();
			~Box();
			
			virtual void step();
			virtual void draw();
			
			void resize(int, int);
			
			void add(Element *);
			void rm(Element *);
		
			bool reposition;
			int elementy;
		protected:
			std::vector<Element *> e;
		};
	}
}

#endif