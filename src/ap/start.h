#ifndef apstart_H
#define apstart_H

#include "../h.h"
#include "../en/draws.h"
#include "../en/text.h"

using namespace en;

namespace ap {
	namespace start {
		// fwds
		class Button;
		class Asteroid;
		
		class Menu : public en::Draws {
		public:
			Menu();
			virtual ~Menu();
			
			virtual void step();
			virtual void draw();
			
			static double accel;
			
			Button *play;
			Button *quit;
			
			en::Draws *stars;
			int rocks;
			
		private:
			std::vector<Asteroid *> roids;
		
			en::Text *wit;
			en::Vector<Draws *> things;
			void decals();
		};
		
		class Button : public en::Text {
		public:
			enum Action {
				PLAY,
				QUIT
			};
			typedef void (*ac_t)(void);
			
			Button(const char *, int, Action oct, ac_t);
			virtual ~Button();
			
			Action action;
			
			virtual void click(mou::Button, mou::Click);
			virtual void hover(mou::Hover);
			
			//int (Button::*pt2ConstMember)(void) const = NULL;
			
			ac_t ac;
		};
		
		class Asteroid : public en::Draws {
		public:
			Asteroid();
			virtual ~Asteroid();
			
			const double RESCALE = 1.5D;
			
			virtual void in();
			virtual void out();
			
			en::Draws *pane;
			en::Text *descriptor;
			
			bool stats;
			void describe();
			
			double speed;
			float direction;
			
			virtual void draw();
		};
	}
	
}

#endif