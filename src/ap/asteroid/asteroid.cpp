#include "asteroid.h"


// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Asteroid::Asteroid()
	: ap::Sprite(GDUMP, nullptr, &regfluke ) ,
	fbo(&BLACK, *(new Region{0,0,16,16}))
	{
	Asteroid::count ++;

	sx(200);
	sy(200);
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}

void ap::asteroid::Asteroid::step() {
	step();
}