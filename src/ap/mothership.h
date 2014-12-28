#ifndef apmothership_H
#define apmothership_H

#include "../h.h"
#include "mover.h"


namespace ap {

	class Mothership : public Mover {
	public:
		Mothership();
		~Mothership();
		
		
		//void late();
		//void key(void);
	//protected:
		//virtual void translate();
		
		//speed_ps speed;
		void post();
	private:
		int cock;
		//const char *name;
		Sprite *clawbase;
		
		Light *light1;
		Light *light2;
		
		Light *light3;
		Light *light4;
		Light *light5;
		//int hp;
		//void move();
		//speed_ps inline spd();
	};
}
#endif