#include <random>
#include "time.h"

#include "chicken.h"

#include "../def.h"

ap::ais::Chicken::Chicken(en::Region *b) :
	ap::AI::AI(&textures::chicken, &regions::chicken) ,
	bounds(b),
	timetonext(.0d),
	next(IDLE),
	current(NONE)
	{
	//feathers = new Emitter(Emitter::feathers);
	//ap::add(feathers);
}

ap::ais::Chicken::~Chicken() {}

void ap::ais::Chicken::step() {
	Object::step();
	
	docurrent();
	
	if ( timetonext-en::dnow <= 0 )
		donext();	
	
	//feathers->sx(gx());
	//feathers->sy(gy());
}

void ap::ais::Chicken::donext() {
	
	switch(next) {
		case IDLE :
			{
			next = RUN;
			current = NONE;
			if ( !! round(ilrand()) ) {
				current = FLAPPING;
				timetonext = en::dnow + RANDRANGE(500, 2000);
			} else {
				sregion( &regions::chicken );
				timetonext = en::dnow + RANDRANGE(1000, 4000);
				animi = {0,0.D,false};
			}
			}
			break;
			
		case RUN :
			{
			bool b;
			if ( ax <= bounds->x) {
				b = false;
			}
			else if ( ax + gw() >= bounds->x + bounds->w ) {
				b = true;
			}
			else
				b = !! round(ilrand());
			current = (b) ? GOINGLEFT : GOINGRIGHT;
			xflip = !b;
			
			timetonext = en::dnow + RANDRANGE(350, 2500);
			
			next = IDLE;
			}
			break;
			
		default:
			break;
	}
}

void ap::ais::Chicken::docurrent() {
	switch(current) {
		case FLAPPING :
			sregion( anims::chickenflap.progress(animi) );
			break;
			
		case GOINGLEFT :
			sx(ax - (en::delta * 50) );
			sregion( anims::chickenrun.progress(animi) );
			break;
			
		case GOINGRIGHT :
			sx(ax + (en::delta * 50) );
			sregion( anims::chickenrun.progress(animi) );
			break;
		
		default:
			break;
	}
}