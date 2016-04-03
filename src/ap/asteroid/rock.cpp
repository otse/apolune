#include "all.h"

#include "../def.h"


// retard the hot flames
int ap::asteroid::Rock::count = 0;

using namespace ap::asteroid;

const Rock::Model Rock::single = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rocksingle1
		}, 1 };

const Rock::Model Rock::uni = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
		}, 3 };

ap::asteroid::Rock::Rock(Asteroid &a, int x, int y)
	: ap::Sprite(GDUMP, &textures::rocks, &regions::rocksingle ) ,
	asteroid(a),
	x(0),
	y(0)
	{
	Rock::count ++;

	sx(x*24);
	sy(y*24);
	world = false;

	fbo = &asteroid.gfbo();

	LOG("something nasty")
}

ap::asteroid::Rock::~Rock() {
	Rock::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}
