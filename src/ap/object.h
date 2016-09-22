#ifndef apobject_H
#define apobject_H

#include "../h.h"

#include "mover.h"
#include "sprite.h"

using namespace en;

namespace ap {
	class Object : public Sprite {
	public:
		Object(en::sort_t, en::Texture *, en::Region *);
		~Object();
		
		virtual void click();
		virtual void hover(mou::Hover);
		
		const char *tip;
		
		virtual void step();
		
		void tryactivate();
		
	protected:
		int activaterange;
		double thovering;
		
		virtual void activate();
	};
}

#endif