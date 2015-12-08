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
	outline(nullptr),

	junction1(nullptr),
	junction2(nullptr),
	junction3(nullptr),
	junction4(nullptr)
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

	if ( nullptr != junction1 ) junction1->draw();
	if ( nullptr != junction2 ) junction2->draw();
	if ( nullptr != junction3 ) junction3->draw();
	if ( nullptr != junction4 ) junction4->draw();

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

void ap::craft::Truss::connect() {
	Tile **all = tile.gneighbors();

	for (int i = 0; i < 8; i ++) {
		Tile *t = all[i];
		Part *p;
		if ( t && (p = t->gpart()) && p->type == TRUSS ) p->refit();
	}

	refit();
}

void ap::craft::Truss::refit() {
	Part *top = (tile.gtop() && tile.gtop()->gpart()) ? tile.gtop()->gpart() : nullptr;
	Part *topright = (tile.gtopright() && tile.gtopright()->gpart()) ? tile.gtopright()->gpart() : nullptr;
	Part *right = (tile.gright() && tile.gright()->gpart()) ? tile.gright()->gpart() : nullptr;
	Part *bottomright = (tile.gbottomright() && tile.gbottomright()->gpart()) ? tile.gbottomright()->gpart() : nullptr;
	Part *bottom = (tile.gbottom() && tile.gbottom()->gpart()) ? tile.gbottom()->gpart() : nullptr;
	Part *bottomleft = (tile.gbottomleft() && tile.gbottomleft()->gpart()) ? tile.gbottomleft()->gpart() : nullptr;
	Part *left = (tile.gleft() && tile.gleft()->gpart()) ? tile.gleft()->gpart() : nullptr;
	Part *topleft = (tile.gtopleft() && tile.gtopleft()->gpart()) ? tile.gtopleft()->gpart() : nullptr;

	if ( !(top && top->type == TRUSS) ) top = nullptr;
	if ( !(bottom && bottom->type == TRUSS) ) bottom = nullptr;
	if ( !(left && left->type == TRUSS) ) left = nullptr;
	if ( !(right && right->type == TRUSS) ) right = nullptr;
	
	// quad
	if ( top && right && bottom && left ) {
		model = &quad;
		rotate = 0;
	}

	// tri
	else if ( top && right && bottom ) {
		model = &tri;
		rotate = 0;
	}
	else if ( right && bottom && left ) {
		model = &tri;
		rotate = 90;
	}
	else if ( bottom && left && top ) {
		model = &tri;
		rotate = 180;
	}
	else if ( left && top && right ) {
		model = &tri;
		rotate = 270;
	}

	// duo
	else if ( top && right ) {
		model = &duo;
		rotate = 0;
	}
	else if ( right && bottom ) {
		model = &duo;
		rotate = 90;
	}
	else if ( bottom && left ) {
		model = &duo;
		rotate = 180;
	}
	else if ( left && top ) {
		model = &duo;
		rotate = 270;
	}

	// opposite
	else if ( top && bottom ) {
		model = &opposite;
		rotate = 0;
	}
	else if ( left && right ) {
		model = &opposite;
		rotate = 90;
	}

	// uni
	else if ( top ) {
		model = &uni;
		rotate = 0;
	}
	else if ( right ) {
		model = &uni;
		rotate = 90;
	}
	else if ( bottom ) {
		model = &uni;
		rotate = 180;
	}
	else if ( left ) {
		model = &uni;
		rotate = 270;
	}

	sregion(model->m.r);

	// junctions
	if ( model == &quad) {
		if ( ! topleft ) {
			junction1 = new Sprite(en::GDEF, &textures::parts, &regions::trussjunction);
			junction1->rotate = 90;
			junction1->sx(gx());
			junction1->sy(gy());
			LOG ("quad: ! topleft")
		}
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