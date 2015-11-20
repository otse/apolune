#ifndef apguibutton_H
#define apguibutton_H

#include "element.h"
#include "label.h"


namespace ap {
	namespace gui {
		class Button : public Label {
		public:
			Button(Box *, const char *, const char *, t_click);
			virtual ~Button();
			
			//void slabel(const char *);
			virtual void svalue(const char *);
			
			virtual void step();
			virtual void draw();
			
			virtual void click();
			virtual void hover(en::mou::Hover);
			
			virtual void rebuild();
			virtual void reposition();
			
			t_click onclick;
			
		private:			
			en::Draws *bleft;
			en::Draws *bmiddle;
			en::Draws *bright;
		};
	}
}

#endif