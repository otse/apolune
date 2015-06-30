#include <stdio.h>
#include <iostream>
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <windows.h>

#include "engine.h"
#include "draws.h"
#include "texture.h"
#include "../ll/stb_image.h"

//#include "string.h"

// https://github.com/otse/cpph/tree/master/planets/src/gl/opengl.cpp

using namespace en;
en::Region en::regfluke = {0,0,0,0};
Color en::BLACK = {0, 0, 0};
Color en::WHITE = {1, 1, 1};

int mou::mx = 0;
int mou::my = 0;
int mou::pmx = 0;
int mou::pmy = 0;
mou::Click mou::left = mou::IDLE;
mou::Click mou::right = mou::IDLE;
mou::Click *mou::active = nullptr;
sf::Vector2i mou::pos;

oar::KEY_STATE oar::keys[sf::Keyboard::KeyCount] = { oar::UP };

const int en::GROUP_SATURATION = 100;
bool en::twdd = false;
int en::width = 800;
int en::height = 600;
int en::WindowHandle = 0;
bool en::focus = true;
Draws *en::groups[en::Group::COUNT] = { nullptr };

Vector<Draws *> en::late;
List<Draws *> en::draws;


LARGE_INTEGER en::frequency;
LARGE_INTEGER en::deltatime;
LARGE_INTEGER en::now;
double en::dnow = 0.D;
double en::delta = 0;


std::string *en::extraction = nullptr;

void en::window() {
	/*
	char *argv [1];
	int argc=1;
	argv [0]=strdup("Myappname/Apolune");
	
	glut(argc, argv);
	*/
	
	using namespace sf;
	RenderWindow window(VideoMode(width, height), envars::windowname, envars::windowstyle);
	//window.setVerticalSyncEnabled(true);
	
	GLenum GlewInitResult;
	GlewInitResult = glewInit();
	
	if ( GLEW_OK != GlewInitResult ) {
		fprintf(
			stderr,
			"ERROR: %s\n",
			glewGetErrorString(GlewInitResult)
		);
		//exit(EXIT_FAILURE);
	}

	fprintf(stdout, "INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));
	
	//shaders();
	
	glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	
	// depreciated
	//for ( int i = 0; i < Group::COUNT; i ++ ) {
	//	groups[i] = i * GROUP_SATURATION;
	//}
	
	QueryPerformanceFrequency(&frequency);
	dnow = (now.QuadPart) * 1000.0 / frequency.QuadPart;
	
	envars::make();
	
	while ( window.isOpen() ) {
		sf::Event event;

		while ( window.pollEvent(event) ) {
			if ( event.type == sf::Event::Closed )
				window.close();

			if (event.type == sf::Event::GainedFocus)
				focus = true;

			if (event.type == sf::Event::LostFocus)
				focus = false;
		}

		mou::mice(window);

		//window.clear();

		render();
		
		//window.draw(shape);

		window.display();
	}
}

void en::mou::mice(const sf::RenderWindow &a) {
	using namespace sf;
	
	pos = Mouse::getPosition(a);
	mx = pos.x;
	my = pos.y;
	
	bool l = Mouse::isButtonPressed(Mouse::Left);
	bool r = Mouse::isButtonPressed(Mouse::Right);
	
	if (l) {
		if (PRESSED==left) {
			left = DRAG;
			return;
		} else if (DRAG==left)
			return;
			
		left = PRESSED;
		active = &left;
		pmx = mx;
		pmy = my;
		//LOG("pressed left at " << mx << ", " << my)
	} else if (PRESSED==left||DRAG==left) {
		left = RELEASED;
		//LOG("released left")
	} else if (IDLE!=left) {
		left = IDLE;
		//LOG("idled left")
	}
	
	else if (r) {
		if (PRESSED==right) {
			right = DRAG;
			return;
		} else if (DRAG==right)
			return;
		
		right = PRESSED;
		active = &right;
		pmx = mx;
		pmy = my;
	} else if (PRESSED==right||DRAG==right) {
		right = RELEASED;
	} else if (IDLE!=right) {
		right = IDLE;
	}
	
	else if (nullptr!=active) {
		//LOG("mouse to null")
		active = nullptr;
	}
}

void en::oar::poll() {
	if ( ! focus )
		return;

	for(int i=0; i<sf::Keyboard::KeyCount; i++) {
	   sf::Keyboard::Key e = (sf::Keyboard::Key) i;
	   if (sf::Keyboard::isKeyPressed(e)) {
		   if ( KEY_STATE::UP==keys[e] )
				keys[e] = KEY_STATE::DOWN;
		   else
			   keys[e] = KEY_STATE::STILL_DOWN;
	   }
	   else
		   keys[e] = KEY_STATE::UP;
	}
}

void en::drawsstep() {
	// step
	{std::list<Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		Draws *d = *it;
		d->step();
	}}
	
	// remove
	{std::list<Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		Draws *d = *it;
		if ( d->remove ) {
			LOG("removing Draws in remove loop ")
			it = draws.l.erase(it);
			d->remove = false;
			if ( d->delete_ )
				delete d;
		}
	}}
	
	// add late
	{std::vector<Draws *>::iterator it;
	for ( it = late.v.begin(); it < late.v.end(); it ++) {
		Draws *d = *it;
		d->step();
		add(d);
	}}
	late.v.clear();
	
	// draw
	{std::list<Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		Draws *d = *it;
		d->draw();
	}}
}


void en::add(Draws *p) {
	draws.l.push_back(p);
}

void en::later(Draws *p) {
	late.v.push_back(p);
}

void en::rm(Draws *s) {
	if ( nullptr == s )
		return;
	
	std::list<Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		if ( *it == s ) {
			draws.l.erase(it);
			break;
		}
	}
}

void en::cleanup() {

    //DestroyVBO();
}

/*void en::resize(int w, int h) {
	ap::resize();
	LOG(w << ", " << h)
	
	if ( w != en::width  ||  h != en::height ) {
		//LOG("correcting resize; pls don't resize")
		//width = w;
		//height = h;
		//glutReshapeWindow(en::width, en::height);
	}
	
	glViewport(0,0, en::width, en::height);
}*/

/*
	keys[key] = UP;

	if ( UP == keys[key] )
		keys[key] = DOWN;
	else if ( DOWN == keys[key] )
		keys[key] = STILL_DOWN;
*/

void en::render(void) {
	s2d();
	
	//glClear(GL_COLOR_BUFFER_BIT);
	
	cdelta();
	
	envars::frame();
	
	/*if ( PRESSED == left ) left = STILL_PRESSED;
	if ( PRESSED == right ) right = STILL_PRESSED;
	
	if ( RELEASED == left ) left = IDLE;
	if ( RELEASED == right ) right = IDLE;*/
	
	//glutSwapBuffers();
	//glutPostRedisplay();
}

//delta
void en::cdelta() {
	static double last = 0;//now;
	
	QueryPerformanceCounter(&now);
	
	dnow = (now.QuadPart) * 1000.0 / frequency.QuadPart;
	
	en::delta = (dnow-last)/1000;
	last = dnow;
	
}

/**
 * useful for render-to-texture
 */
void en::s2d() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, en::width, en::height, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//twdd = true;
}
