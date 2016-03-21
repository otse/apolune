#include "asteroid.h"

// retard the hot flames
int ap::asteroid::Asteroid::count = 0;

ap::asteroid::Asteroid::Asteroid(en::Texture *t, en::Region *r)
	: ap::Mover(ASTEROID,en::GDUMP,t,r) ,
	smthng(1337), // smthng very bad
	elsee("elsee")
	{
	Asteroid::count ++;
}

ap::asteroid::Asteroid::~Asteroid() {
	Asteroid::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}

void ap::asteroid::Asteroid::step() {
	ap::Mover::step();
}