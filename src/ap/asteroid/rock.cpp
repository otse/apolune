#include "all.h"

#include "../def.h"


// retard the hot flames
int ap::asteroid::Rock::count = 0;

using namespace ap::asteroid;

const Rock::Model Rock::uni = {
		&textures::parts,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
		}
		/*, int i */ };

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

ap::asteroid::Rock::~Rock() {
	Rock::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}
