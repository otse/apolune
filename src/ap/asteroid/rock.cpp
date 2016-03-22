#include "all.h"

#include "../def.h"


// retard the hot flames
int ap::asteroid::Rock::count = 0;
			

ap::asteroid::Rock::Rock(Asteroid &a, int x, int y)
	: ap::Sprite(GDUMP, &textures::parts, &regions::trusssingle ) ,
	asteroid(a),
	x(0),
	y(0)
	{
	Rock::count ++;

	sx(200);
	sy(200);

	fbo = &asteroid.gfbo();

	LOG("something nasty")
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}
