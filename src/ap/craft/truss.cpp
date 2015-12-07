#include "truss.h"

#include "../def.h"

using namespace ap::craft;

const Truss::Model Truss::single = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trusssingle
		}, /* strength */ 100, /* weight */ 100};

const Truss::Model Truss::uni = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussuni
		}, 100, 100};

const Truss::Model Truss::duo = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussduo
		}, 100, 100};

const Truss::Model Truss::opposite = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussopposite
		}, 100, 100};

const Truss::Model Truss::tri = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trusstri
		}, 100, 100};

const Truss::Model Truss::quad = {
		(en::Draws::Model) {
			&textures::parts,
			&regions::trussquad
		}, 100, 100};


ap::craft::Truss::Truss(Tile &t) : Part(t, single.m, TRUSS) ,
	model(&single),
	wall(nullptr),
	outline(nullptr)
	{

	// if ( !! round(ilrand()) )
	wall = new Wall(tile);
}

ap::craft::Truss::~Truss() {
	
}

void ap::craft::Truss::step() {
	Part::step();

	if ( nullptr != wall )
		wall->step();
}

void ap::craft::Truss::draw() {
	if ( nullptr != wall )
		wall->draw2(true);

	Part::draw();

	if ( ! craft.crosssection && nullptr != wall )
		wall->draw2(false);
}

void ap::craft::Truss::click() {
	
}


void ap::craft::Truss::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		
	} else {
		
	}
}

void ap::craft::Truss::refit() {
	Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	//Part *topleft = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	//Part *topright = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;

	if ( !(top && top->type == TRUSS) ) top = nullptr;
	if ( !(bottom && bottom->type == TRUSS) ) bottom = nullptr;
	if ( !(left && left->type == TRUSS) ) left = nullptr;
	if ( !(right && right->type == TRUSS) ) right = nullptr;
	
	// quad
	if ( top && bottom && left && right ) {
		model = &quad;
		sregion(&regions::trussquad);
		rotate = 0;
	}

	// tri
	else if ( top && right && bottom ) {
		sregion(&regions::trusstri);
		rotate = 0;
	}
	else if ( right && bottom && left ) {
		sregion(&regions::trusstri);
		rotate = 90;
	}
	else if ( bottom && left && top ) {
		sregion(&regions::trusstri);
		rotate = 180;
	}
	else if ( left && top && right ) {
		sregion(&regions::trusstri);
		rotate = 270;
	}

	// duo
	else if ( top && right ) {
		sregion(&regions::trussduo);
		rotate = 0;
	}
	else if ( right && bottom ) {
		sregion(&regions::trussduo);
		rotate = 90;
	}
	else if ( bottom && left ) {
		sregion(&regions::trussduo);
		rotate = 180;
	}
	else if ( left && top ) {
		sregion(&regions::trussduo);
		rotate = 270;
	}

	// opposite
	else if ( top && bottom ) {
		sregion(&regions::trussopposite);
		rotate = 0;
	}
	else if ( left && right ) {
		sregion(&regions::trussopposite);
		rotate = 90;
	}

	// uni
	else if ( top ) {
		sregion(&regions::trussuni);
		rotate = 0;
	}
	else if ( right ) {
		sregion(&regions::trussuni);
		rotate = 90;
	}
	else if ( bottom ) {
		sregion(&regions::trussuni);
		rotate = 180;
	}
	else if ( left ) {
		sregion(&regions::trussuni);
		rotate = 270;
	}

	if ( nullptr != wall )
		wall->refit();
}


/* ###########################
   ## Getters & Setters
   ########################### */
Wall *ap::craft::Truss::gwall() {
	return wall;
}

//float ap::Ply::gy() {
//	return .0;
//}