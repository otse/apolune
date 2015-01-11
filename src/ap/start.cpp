#include <algorithm>
#include <cmath>
#include <sstream>
#include "time.h"

#include "../en/font.h"
#include "start.h"
#include "loader.h"
#include "def.h"

using namespace en;
double ap::start::Menu::accel = 13;

void playac();
void exitac();

//#CBS

ap::start::Menu::Menu() :
	en::Draws(GDEF, nullptr, &regfluke) ,
	rocks(0)
	{
	
	loader->remove = true;
	loader = nullptr;
	
	stars = new en::Draws(GDEF, &textures::backdrop, &regions::backdrop);
	
	/*wit = new en::Text(&monospace, &en::WHITE, "moored in space 0km/h");
	wit->name = "wit";
	wit->sscale(2.D);
	wit->sy(en::HEIGHT-monospace.gh()*2);
	wit->position();
	int s = monospace.getglyph(' ')->w*2;
	wit->sx( (en::WIDTH) - (wit->gtextw()*2) - s );
	
	wit->position();*/
	
	later(stars);
	//ap::add(wit);
	
	later( play = new Button("play", 0, Button::PLAY, nullptr) );
	later( quit = new Button("quit", 1, Button::QUIT, nullptr) );
	
	//this->decals();
	
	//draws.resort = true;
	
}

void ap::start::Menu::step() {
	/*rm(loader);
	delete loader;
	loader = nullptr;*/
}

void ap::start::Menu::draw() {
	if ( accel > 1 ) {
		accel -= ((accel*0.2) + 3) * 0.003D;
		if ( accel < 1 )
			accel = 1;
	}
}

ap::start::Menu::~Menu() {
	LOG("deleting menu and affiliates");
	
	stars->remove = true;
	play->remove = true;
	quit->remove = true;
	
	//std::vector<Asteroid *>::iterator it;
	//for ( it = roids.begin(); it < roids.end(); it ++)
		//rm(*it);
		
	//std::for_each( roids.begin(), roids.end(), DeleteVector<Asteroid *>() );
	
}

void ap::start::Menu::decals() {
	// sick cunt
	for ( int i = 0; i < 50; i ++ ) {
		Asteroid *o = new Asteroid();
		roids.push_back(o);
		later(o);
	}
}

ap::start::Button::Button(const char *c, int pos, Action a, ac_t cb)
	: en::Text( en::GDUMP, monospace2, &en::WHITE, c) ,
	action(a),
	ac(cb)
	{
	scale = 4;
	
	//sclicky(cb, nullptr, nullptr, nullptr);
	
	position();
	
	sy( 150 + (pos*monospace2.gh()*5) );
	sx( (en::width/2) - ((gtextw()*scale)/2) );
	position();
}

ap::start::Button::~Button() {
	
}

void ap::start::Button::click() {
	LOG("pressed button")
		
	if ( MOURELEASED ) {
		switch (action) {
			case PLAY :
				menu->remove = true;
				//ap::rm(ap::menu);
				//delete ap::menu;
				ap::launchworld();
				break;

			case QUIT :
				exit(EXIT_SUCCESS);
				break;
		}
	}
}

void ap::start::Button::hover(mou::Hover h) {
	if ( mou::HOVER_IN == h ) {
		scolor(&colors::YELLOW);
		scale = 5;
		position();
	} else {
		scolor(&WHITE);
		scale = 4;
		//sx(x-5);
		position();
	}
}


//ap::MButton::~MButton() {}


ap::start::Asteroid::Asteroid()
	: en::Draws(GDUMP, &textures::sheet, &regions::masteroid) ,
	stats(false),
	pane(nullptr),
	descriptor(nullptr)
	{
	
	const int basespeed = 3;
	const int variablespeed = 15;
	
	this->direction = ap::ilrand();
	
	int m = ap::ilrand() * (gw()*1);
	sw(m + gw());
	sh(m + gh());
	
	sx( (en::width/2)-gw()/2 );
	sy( (en::height/2)-gh()/2 );
	
	LOG("w " << gw() << " h " << gh())
	
	this->speed =  ( ap::ilrand() * variablespeed ) + basespeed;
	
	LOG("speed " << speed);
}

ap::start::Asteroid::~Asteroid() {
	
}

void ap::start::Asteroid::in() {
	/*x = x - (((w*RESCALE)-w)/2);
	y = y - (((h*RESCALE)-h)/2);
	w = w*RESCALE;
	h = h*RESCALE;*/
}

void ap::start::Asteroid::out() {
	/*sx( gx() - (((gw()/RESCALE)-gw())/2) );
	sy( gy() - (((gh()/RESCALE)-gh())/2) );
	sw(gw()/RESCALE);
	sh(gh()/RESCALE);*/
}

void ap::start::Asteroid::draw() {
	float pangle = ((M_PI * 2) * this->direction);
	
	float m = (speed*Menu::accel) * 0.1D;//en::delta;
	
	x += m * cos(pangle);
	y += m * sin(pangle);
	
	//LOG("x " << gx() << " y " << gy())
	
	Draws::draw();
}