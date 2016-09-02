#ifndef apmover_H
#define apmover_H

#include "../h.h"
#include "sprite.h"

// three of us klute
// hear my call Dom & Roland
// wasteland ft spl black sun empire
// the resistance spor

namespace ap {

	class Mover : public Sprite {
	public:
		enum Type {
			LINEAR,
			SMOOTH,
			CREATURE,
			PLAYER,
			MOTHERSHIP,
			SHIP,
			ASTEROID
		};
		
		Mover(Type, en::sort_t, en::Texture *, en::Region *);
		~Mover();
		
		virtual void translate();
		virtual void step();
		
		void collide(void);
		bool gcollides();
		void scollides(bool);
		
		virtual void sx(double);
		virtual void sy(double);
		
	protected:
		double momentum;
		virtual void cycle();
		
	private:
		Type type;
		bool cycled;
		bool solid;
		
	};
}
#endif