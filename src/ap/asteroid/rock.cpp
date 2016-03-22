#include "all.h"

#include "rock.h"


// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Rock::Rock(Asteroid &a)
	: ap::Sprite(GDUMP, nullptr, &regfluke ) ,
	asteroid(a),
	fbo(&BLACK, *(new Region{0,0,16,16}))
	{
	Asteroid::count ++;

	sx(200);
	sy(200);

	fbo = asteroid.gfbo();

	LOG("something nasty")
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}