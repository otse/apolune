#ifndef apguilabel_H
#define apguilabel_H

#include "element.h"


namespace ap {
	namespace gui {
		class Label : public Element {
		public:
			Label(Box *, const char *, const char *);
			virtual ~Label();
			
			void slabel(const char *);
			void svalue(const char *);
			
			//void sstate(int);
			//int gstate();
			bool category;
			bool changeable;
			
			virtual void step();
			virtual void draw();
			
			virtual void click(en::Button, en::Click);
			virtual void hover(en::Hover);
			
			virtual void rebuild();
			virtual void reposition();
			
		protected:
			//int state;
			
			const char *label;
			const char *value;
			
			en::Draws *lleft;
			en::Draws *lmiddle;
			en::Draws *lright;
			
			en::Draws *vleft;
			en::Draws *vmiddle;
			en::Draws *vright;
			
			en::Text *tlabel;
			en::Text *tvalue;
		};
	}
}

#endif