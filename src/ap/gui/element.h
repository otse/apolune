#ifndef apguielement_H
#define apguielement_H

#include "../../h.h"

#include "../../en/draws.h"


using namespace en;

namespace ap {
	namespace gui {
		class Element : public en::Draws {
		public:
			Element(Box *);
			virtual ~Element();
			
			virtual void step();
			virtual void draw();
			
			virtual void rebuild();
			virtual void reposition();
			
			virtual void click(mou::Button, mou::Click);
			virtual void hover(mou::Hover);
			
			typedef void (*t_click)(en::mou::Button b, en::mou::Click c);
			
			//bool reposition;
		protected:
			Box *box;
		};
	}
}

#endif