#include <random>
#include "time.h"

#include "Tentacle.h"

#include "../def.h"

ap::ais::Tentacle::Tentacle(en::Region *b) :
	ap::AI::AI(&textures::tentacle, &regions::tentaclepopped) ,
	bounds(b),
	timetonext(.0d),
	next(UNPOP),
	current(CURRENT_NONE)
	{
	timetonext = en::dnow + 1000;
}

ap::ais::Tentacle::~Tentacle() {}

void ap::ais::Tentacle::step() {
	Object::step();
	
	docurrent();
	
	if ( timetonext-en::dnow <= 0 )
		donext();	
	
}

void ap::ais::Tentacle::donext() {
	
	switch(next) {
		case NEXT_NONE :
			break;
			
		case IDLE :
			{
			current = CURRENT_NONE;
			sregion( &regions::tentacle );
			
			double weights[] = {.50, .40, .10};
			std::discrete_distribution<> d(std::begin(weights), std::end(weights));
			
			switch ( (int) d(rng) ) {
				case 0 :
					next = BLINK;
					timetonext = en::dnow + RANDRANGE(250, 500);
					break;
					
				case 1 :
					next = MOVE;
					timetonext = en::dnow + RANDRANGE(500, 1000);
					break;
					
				case 2 :
					timetonext = en::dnow + RANDRANGE(500, 1000);
					next = POP;
					break;
			}
			}
			
			break;
		
		case POP :
			LOG("POP")
			animi = {anims::tentaclepop.gcount()-2,0.D,true};
			current = POPPING;
			next = NEXT_NONE;
			break;
			
		case UNPOP :
			animi = {1,0.D,false};
			current = UNPOPPING;
			next = NEXT_NONE;
			break;
			
		case BLINK :
			animi = {0,0.D,false};
			current = BLINKING;
			timetonext = en::dnow + RANDRANGE(1000, 1000);
			next = IDLE;
			break;
			
		case MOVE :
			{
			animi = {0,0.D,false};
			bool b;
			if ( ax <= bounds->x)
				b = false;
			else if ( ax + gw() >= bounds->x + bounds->w )
				b = true;
			else
				b = !! round(ilrand());
			current = (b) ? GOINGLEFT : GOINGRIGHT;
			xflip = !b;
			
			timetonext = en::dnow + RANDRANGE(1000, 2500);
			
			next = IDLE;
			}
			break;
			
		default:
			break;
	}
}

void ap::ais::Tentacle::docurrent() {
	switch(current) {
		case POPPING :
		
			sregion( anims::tentaclepop.progress(animi) );
			if ( animi.pos == 1 ) {
				current = CURRENT_NONE;
				timetonext = en::dnow + RANDRANGE(3000, 3000);
				next = UNPOP;
			}
				
			break;
			
		case UNPOPPING :
		
			sregion( anims::tentaclepop.progress(animi) );
			if ( animi.pos == 0 ) {
				current = CURRENT_NONE;
				next = IDLE;
			}
				
			break;
			
		case BLINKING :
		
			sregion( anims::tentacleblink.progress(animi) );
			if ( animi.pos == anims::tentacleblink.gcount()-1 )
				current = CURRENT_NONE;
				
			break;
			
		case GOINGLEFT :
			sx(ax - (en::delta * 25) );
			sregion( anims::tentaclemove.progress(animi) );
			break;
			
		case GOINGRIGHT :
			sx(ax + (en::delta * 25) );
			sregion( anims::tentaclemove.progress(animi) );
			break;
		
		default:
			break;
	}
}