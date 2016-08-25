#include "stdafx.h"

#include "all.h"

#include "../def.h"

#if 0
// retard the hot flames
int ap::asteroid::Rock::count = 0;

using namespace ap::asteroid;

const Rock::Model Rock::single = {
<<<<<<< HEAD
		&ap::textures::rocks,
		{
			&ap::regions::rocksingle1
		}, 1 };

const Rock::Model Rock::uni = {
		&ap::textures::rocks,
		{
			&ap::regions::rockuni1,
			&ap::regions::rockuni2,
			&ap::regions::rockuni3
		}, 3 };

const Rock::Model Rock::duo = {
		&ap::textures::rocks,
		{
			&ap::regions::rockuni1,
			&ap::regions::rockuni2,
			&ap::regions::rockuni3
		}, 3 };

const Rock::Model Rock::opposite = {
		&ap::textures::rocks,
		{
			&ap::regions::rockuni1,
			&ap::regions::rockuni2,
			&ap::regions::rockuni3
		}, 3 };

const Rock::Model Rock::tri = {
		&ap::textures::rocks,
		{
			&ap::regions::rockuni1,
			&ap::regions::rockuni2,
			&ap::regions::rockuni3
		}, 3 };

const Rock::Model Rock::quad = {
		&ap::textures::rocks,
		{
			&ap::regions::rockuni1,
			&ap::regions::rockuni2,
			&ap::regions::rockuni3
=======
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

const Rock::Model Rock::duo = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
		}, 3 };

const Rock::Model Rock::opposite = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
		}, 3 };

const Rock::Model Rock::tri = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
		}, 3 };

const Rock::Model Rock::quad = {
		&textures::rocks,
		(Region *[])
		{
			&regions::rockuni1,
			&regions::rockuni2,
			&regions::rockuni3
>>>>>>> ad92b5e523892a8971ccc3709474c1f4556c1e1f
		}, 3 };

ap::asteroid::Rock::Rock(Asteroid &a, int x, int y)
	: ap::Sprite(GDUMP, &textures::rocks, &regions::rocksingle1 ) ,
	asteroid(a),
	model(&single),
	x(x),
	y(y),
	variation(0),

	neighbors {nullptr}
	{
	Rock::count ++;

	sx(x*24);
	sy(y*24);

	LOG(Sprite::gx() << " " << Sprite::gy())
	world = false;

	fbo = &asteroid.gfbo();

	// LOG("Rock::Rock " << Rock::count)
}

ap::asteroid::Rock::~Rock() {
	Rock::count --;
}

//void ap::Asteroid::rotate() {
	// retard the hot flames
//}

void ap::asteroid::Rock::connect() {

	for (int i = 0; i < 8; i ++) {
		Rock *r = neighbors[i];
		r->refit();
	}

	refit();
}

#define TOP 		rocks[0]
#define TOPRIGHT 	rocks[1]
#define RIGHT 		rocks[2]
#define BOTTOMRIGHT rocks[3]
#define BOTTOM 		rocks[4]
#define BOTTOMLEFT 	rocks[5]
#define LEFT 		rocks[6]
#define TOPLEFT 	rocks[7]

void ap::asteroid::Rock::refit() {
	Rock **all = gneighbors();

	bool rocks[8];

	for (int i = 0; i < 8; i ++) {
		Rock *r = all[i];
		rocks[i] = r;
	}
	
	// quad
	if ( TOP && RIGHT && BOTTOM && LEFT ) {
		model = &quad;
		rotate = 0;
	}

	// tri
	else if ( TOP && RIGHT && BOTTOM ) {
		model = &tri;
		rotate = 0;
	}
	else if ( RIGHT && BOTTOM && LEFT ) {
		model = &tri;
		rotate = 90;
	}
	else if ( BOTTOM && LEFT && TOP ) {
		model = &tri;
		rotate = 180;
	}
	else if ( LEFT && TOP && RIGHT ) {
		model = &tri;
		rotate = 270;
	}

	// duo
	else if ( TOP && RIGHT ) {
		model = &duo;
		rotate = 0;
	}
	else if ( RIGHT && BOTTOM ) {
		model = &duo;
		rotate = 90;
	}
	else if ( BOTTOM && LEFT ) {
		model = &duo;
		rotate = 180;
	}
	else if ( LEFT && TOP ) {
		model = &duo;
		rotate = 270;
	}

	// opposite
	else if ( TOP && BOTTOM ) {
		model = &opposite;
		rotate = 0;
	}
	else if ( LEFT && RIGHT ) {
		model = &opposite;
		rotate = 90;
	}

	// uni
	else if ( TOP ) {
		model = &uni;
		rotate = 0;
	}
	else if ( RIGHT ) {
		model = &uni;
		rotate = 90;
	}
	else if ( BOTTOM ) {
		model = &uni;
		rotate = 180;
	}
	else if ( LEFT ) {
		model = &uni;
		rotate = 270;
	}

	sregion(model->r[variation]);
}

/* ###########################
   ## Getters & Setters
   ########################### */
Rock **ap::asteroid::Rock::gneighbors() { return neighbors; }
<<<<<<< HEAD
#endif
=======
>>>>>>> ad92b5e523892a8971ccc3709474c1f4556c1e1f
