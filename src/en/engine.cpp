#include <stdio.h>
#include <iostream>
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <windows.h>

#include "engine.h"
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
mou::Click mou::left = IDLE;
mou::Click mou::right = IDLE;
sf::Vector2i mou::pos;

oar::KEY_STATE oar::keys[sf::Keyboard::KeyCount] = { oar::UP };

const int en::GROUP_SATURATION = 100;
bool en::twdd = false;
int en::width = 800;
int en::height = 600;
int en::WindowHandle = 0;
Draws *en::groups[en::Group::COUNT] = { nullptr };

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
	RenderWindow window(VideoMode(width, height), EN_WINDOWNAME, EN_SFSTYLE);
	window.setVerticalSyncEnabled(true);
	
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
	
	en::make();
	
	while ( window.isOpen() ) {
		sf::Event event;

		while ( window.pollEvent(event) ) {
			if ( event.type == sf::Event::Closed )
			window.close();
		}

		mou::pos = Mouse::getPosition();
		//window.clear();
		render();
		//window.draw(shape);
		window.display();
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

void en::click() {
	
	en::click();
}

/*
	keys[key] = UP;

	if ( UP == keys[key] )
		keys[key] = DOWN;
	else if ( DOWN == keys[key] )
		keys[key] = STILL_DOWN;
*/

void en::idle(void) {
    //glutPostRedisplay();
}

void en::timer(int value) {
	/*if (0 != Value) {
        char* TempString = (char*)
            malloc(512 + strlen(APOLUNESTR));
		
        sprintf(
            TempString,
            "%s: %d Frames Per Second @ %d x %d",
            APOLUNESTR,
            fps,
            WIDTH,
            HEIGHT
        );
 
        glutSetWindowTitle(TempString);
        free(TempString);
    }*/
	
	// 17 good for 60
	//glutTimerFunc(17, en::timer, 1);
	//glutPostRedisplay();
}

// shard

void en::render(void) {
	s2d();
	
	//glClear(GL_COLOR_BUFFER_BIT);
	
	cdelta();
	
	en::frame();
	
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
