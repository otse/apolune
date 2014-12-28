#ifndef apobject_H
#define apobject_H

#include "../h.h"

#include "mover.h"
#include "sprite.h"

namespace ap {
	/**
	 * An Object is a Sprite that can be activated,
	 * or interacted with.
	 * @terrublyAbstract
	 * @PowerPuffGirls
	 */
	class Object : public Sprite {
	public:
		Object(en::Group, en::Texture *, en::Region *);
		~Object();
		
		virtual void click(en::Button, en::Click);
		virtual void hover(en::Hover);
		
		const char *tip;
		
		virtual void step();
		
		void tryactivate();
		bool inrange();
		
		//virtual void tooltipping();
	protected:
		//en::Text *tooltip;
		int activaterange;
		double thovering;
		
		virtual void activate();
	};
}

#endif