#ifndef apguielement_H
#define apguielement_H

#include "../../h.h"

#include "../../en/draws.h"


//using namespace en;

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
			
			virtual void click(en::Button, en::Click);
			virtual void hover(en::Hover);
			
			typedef void (*t_click)(en::Button b, en::Click c);
			
			//bool reposition;
		protected:
			Box *box;
		};
	}
}

#endif