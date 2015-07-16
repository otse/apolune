#include "wall.h"

#include "../def.h"

using namespace ap::craft;

const Wall::Model Wall::iris = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walliris
		}, 100};

const Wall::Model Wall::single = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallsingle
		}, 100};

const Wall::Model Wall::uni = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walluni
		}, 100};

const Wall::Model Wall::duo = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallduo
		}, 100};

const Wall::Model Wall::opposite = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallopposite
		}, 100};

const Wall::Model Wall::tri = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::walltri
		}, 100};

const Wall::Model Wall::quad = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::wallquad
		}, 100};


ap::craft::Wall::Wall(Craft &c, const Model m) : Part(c, m.m, WALL) ,
	outline(nullptr)
	{
	// LOG("new wall, region " << m.m.r->x << m.m.r->y << m.m.r->w << m.m.r->h)

}

ap::craft::Wall::~Wall() {
	
}


void ap::craft::Wall::step() {
	Part::step();


}

void ap::craft::Wall::click() {
	
}


void ap::craft::Wall::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}


/* ###########################
   ## Getters & Setters
   ########################### */
//void ap::craft::Tile::sgrid(int c, int r) {
	//cols = c;
	//rows = r;

	//table();
//}

//float ap::Ply::gy() {
//	return .0;
//}