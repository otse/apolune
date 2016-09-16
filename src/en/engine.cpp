#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <direct.h> // for mkdir
#include <windows.h>

#include "engine.h"
#include "draws.h"
#include "texture.h"
#include "../ll/stb_image.h"


//#include "string.h"

// https://github.com/otse/cpph/tree/master/planets/src/gl/opengl.cpp

using namespace en;
PHYSFS_File *base;
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

int mou::wheel = 0;

oar::KEY_STATE oar::keys[sf::Keyboard::KeyCount] = { oar::UP };

int en::width = 800;
int en::height = 600;
float en::scale = 1;
bool en::pixels = false; // to switch between perspective, unused

int en::WindowHandle = 0;
bool en::focus = true;

Vector<Draws *> en::late;
List<Draws *> en::draws;


LARGE_INTEGER en::frequency;
LARGE_INTEGER en::deltatime;
LARGE_INTEGER en::now;
double en::dnow = 0;
double en::delta = 0;
bool en::ppi = false;


std::string *en::extraction = nullptr;

void en::roaming() {
	PHYSFS_init(0);
	PHYSFS_setSaneConfig("w/e", "apolune", "7z", 0, 0);
	//PHYSFS_addToSearchPath("base", 0);
	PHYSFS_addToSearchPath("../base", 1);
	//PHYSFS_addToSearchPath("base", 1);
	
	char *appdata = getenv("APPDATA");
	extraction = new std::string(appdata);
	extraction->append("\\.apolune");
	_mkdir(extraction->c_str());
	
	LOG("extraction path is " << extraction->c_str() );
}

void en::boot(int argc, wchar_t* argv[]) {
	using namespace sf;

	for (int i = 1; i < argc; i ++) {
		if (wcscmp(argv[i], L"-ppi") == 0) {
			LOG("-~=-> -ppi switch")
			en::ppi = true;
		}

		else if (wcscmp(argv[1], L"-thing") == 0) {}
	}

	int windoww = width;
	int windowh = height;

	if ( en::ppi ) {
		// w = 1920;
		// h = 1080;
		windoww = 1920;
		windowh = 1080;

		width = windoww / 2 ; // 960
		height = windowh / 2 ; // 540
	}

	RenderWindow window(VideoMode(windoww, windowh), envars::windowname, envars::windowstyle);
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
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	
	// depreciated
	//for ( int i = 0; i < Group::COUNT; i ++ ) {
	//	groups[i] = i * GROUP_SATURATION;
	//}
	
	QueryPerformanceFrequency(&frequency);
	dnow = (now.QuadPart) * 1000.0 / frequency.QuadPart;
	
	en::roaming();

	envars::make();
	
	while ( window.isOpen() ) {
		sf::Event event;

		while ( window.pollEvent(event) ) {
			if ( event.type == sf::Event::Closed )
				window.close();

			if (event.type == sf::Event::MouseWheelMoved)
				mou::wheel = event.mouseWheel.delta;

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

	if ( en::ppi /* && (pos.x/2 != mx || pos.y/2 != my)*/ ) {
		mx = pos.x / 2;
		my = pos.y / 2;
		// LOG("mx " << mx << " my " << my)
	}

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

bool en::nukeif(const Draws *p) {
	if (p->remove) {
		LOG("nukeif a draws to " << en::Draws::GCOUNT())
		delete p;
		return true;
	}
	else return false;
}

void en::drawsstep() {
	// step
	{std::list<Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		Draws *d = *it;
		d->step();
	}}

	draws.l.remove_if(en::nukeif);
	
	// add late
	{std::vector<Draws *>::iterator it;
	for ( it = late.v.begin(); it < late.v.end(); it ++) {
		Draws *d = *it;
		d->step();
		add(d);
		LOG("added late draws")
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
	
	delta = (dnow-last)/1000;

	// todo: improve spike prevention
	//if ( delta > 0.005 )
		//delta = 0.005;

	last = dnow;
	
}


void en::flat() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int l, r, b, t;
	l = 0;
	r = width;
	b = height;
	t = 0;
	glOrtho(l, r, b, t, -1, 1);

	pixels = true;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void en::threed() {
	return;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	pixels = false;

	glMatrixMode(GL_MODELVIEW);

	//glDepthMask(GL_FALSE); // todo: ...
}
