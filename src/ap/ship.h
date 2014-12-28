#ifndef apship_H
#define apship_H

#include "../h.h"
#include "mover.h"


namespace ap {

	class Ship : public Mover {
	public:
		Ship(const char *, en::Texture *, en::Region *);
		~Ship();
		
		//void late();
		//void key(void);
	//protected:
		//virtual void translate();
		
		//speed_ps speed;
	private:
		const char *name;
		//int hp;
		//void move();
		//speed_ps inline spd();
	};
}
#endif