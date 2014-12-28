#ifndef applanet_H
#define applanet_H

#include "../h.h"
#include "../en/draws.h"


namespace ap {

	class Planet : public en::Draws {
	public:
		enum Type {
			MOON,
			STAR,
			GASGIANT
		};
	
		Planet(float x, float y, Type type);
		~Planet();
	//protected:
		/*@ovr*/ virtual void draw();
	private:
		void size();
		
		Type type;
		
		Type gtype();
		//void move();
	};
}
#endif