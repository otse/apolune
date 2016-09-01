#include "stdafx.h"

#include <chrono>
#include <windows.h>

#include "h.h"

#include "ap/cli.h"
#include "ap/loader.h"
#include "ap/lua.h"
#include "ap/start.h"

//#include "ap/world.h"
#include "ap/ply.h"
#include "ap/def.h"

#include "Q:/jsoncpp-master/include/json/json.h"

#include <sstream> // for json, stats
#include <direct.h> // for mkdir
#include <cstring> // for gl ext

using namespace ap;

std::ofstream ap::log;
const char *envars::windowname = "Ap";
int envars::windowstyle = sf::Style::Titlebar | sf::Style::Close;

double ap::zoom = 3;
double ap::zoomto = 1;
double ap::zoomspeed = 1;

int ap::fps = 0;
int ap::frameCount = 0;
int ap::scale = 3;

CLI *ap::cli = nullptr;
Loader *ap::loader;
World *ap::world = nullptr;
Ply *ap::ply = nullptr;


Json::Value ap::midrash;

start::Menu *ap::menu;
std::random_device ap::rd;
std::default_random_engine ap::e1(ap::rd());
std::mt19937 ap::rng(ap::rd());
std::uniform_real_distribution<double> ap::randy(.0, 1);

ais::Chicken *ap::chicken;

using namespace en;

#include "awesome.h"
#include "boilerplate.h"

#include "ap/ship/all.h"
#include "ap/ais/chicken.h"


void switches();
void awesome();
void secondpass();
void react();

int wmain(int argc, wchar_t* argv[]) {
	ap::log.open(LOGFILE);
	LOG(VERSION);
	LOG("hi ô_ô")
	
	uint32_t seed = time(0);
	
	rng.seed(seed);

	en::width = 1024;
	en::height = 768;

	//switches();
	
	en::boot(argc, argv);
    
	exit(EXIT_SUCCESS);
	
	return 0;
}

bool ap::commentary() {
	
	using namespace boilerplate;
	
	basefile bf = gbasefile("Midrash.json");
	if ( ! bf.read )
		return false;
	
	using namespace Json;
	Reader reader;
	bool parsingSuccessful = reader.parse(bf.buf, midrash);
	
	std::string version = midrash.get("version", "unknown").asString();
	
	LOG("Midrash.json versions " << version);
	
	if ( version.compare(ap::VERSION) ) {
		LOG("base/exe version mismatch");
		return false;
	}
	
	return true;
}

void ap::launchworld() {
	world = new World();
	world->load();
}


void envars::make() {
	en::flat();
	ap::as::mawe();

	loader = new Loader();
	en::add(loader);
}

bool second() {
	static double dsecond = 0.;
	
	if ( dnow-dsecond >= 1000. ) {
		dsecond = dnow;
		fps = frameCount;
		frameCount = 0;
		
		as::global.SetPropertyAsync(WSLit("fps"), JSValue(ap::fps));
		as::global.SetPropertyAsync(WSLit("delta"), JSValue(en::delta));

		LOG(fps);
		return true;
	}
	
	return false;
}

void envars::frame() {
	//draws.resort = true;
	//draws.sort();

	glViewport(0, 0, en::width, en::height);						// Reset The Current Viewport


	glViewport(0, 0, width, height);						// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.1, 5);			// In Stead Of GluPerspective
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	


	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	//glDisable(GL_TEXTURE_2D);
	glColor4f(1, 0, 0, 1);

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	glTranslatef(3.0f, 0.0f, 0.0f);						// Move Right 3 Units
	glBegin(GL_QUADS);									// Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
	glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
	glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
	glVertex3f(-1.0f, -1.0f, 0.0f);					// Bottom Left
	glEnd();											// Done Drawing The Quad

	glPopMatrix();

	return;
	
	if ( second() )
		secondpass();
		
	frameCount ++;
	
	oar::poll();
	react();

	if (nullptr == ap::world)
		ap::as::view->InjectMouseMove(mou::mx / 2, mou::my / 2);
	else
		ap::as::view->InjectMouseMove(mou::mx, mou::my);

	as::view->ExecuteJavascript(WSLit("js.second();"), WSLit(""));

	if (en::mou::PRESSED == en::mou::left)
		as::view->InjectMouseDown(kMouseButton_Left);
	else if (en::mou::RELEASED == en::mou::left)
		as::view->InjectMouseUp(kMouseButton_Left);

	if (en::mou::PRESSED == en::mou::right)
		as::view->InjectMouseDown(kMouseButton_Right);
	else if (en::mou::RELEASED == en::mou::right)
		as::view->InjectMouseUp(kMouseButton_Right);

	BitmapSurface* surface = (BitmapSurface*)ap::as::view->surface();

	//if (world == nullptr)
	if (NULL != surface) {
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::as::web->gfbid());
		glBindTexture(GL_TEXTURE_2D, ap::as::web->gtid());
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, en::width, en::height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, surface->buffer());
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
	
	if ( world )
		world->step();


	threed();
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	//glDisable(GL_TEXTURE_2D);
	glColor4f(0, 1, 1, 1);

	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	glTranslatef(3.0f, 0.0f, 0.0f);						// Move Right 3 Units
	glBegin(GL_QUADS);									// Draw A Quad
		glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
		glVertex3f(-1.0f, -1.0f, 0.0f);					// Bottom Left
	glEnd();											// Done Drawing The Quad

	glPopMatrix();

	en::drawsstep();

	flat();
	as::web->gdraws().draw();

	//if (world == nullptr)
	ap::as::core->Update();
	
	return;
}

void secondpass() {
	//stats::rebuild();
}

void react() {
	if ( ply )
		ply->key();
	
	if (nullptr!=world  &&  oar::DOWN==oar::keys[sf::Keyboard::Escape] /* ESC */ ) {
		
	}

	if ( oar::DOWN==oar::keys[sf::Keyboard::Tilde] ) {
		if ( nullptr == cli ) {
			cli = new CLI();
			add(cli);
		}
		else {
			cli->remove = true;
			cli = nullptr;
		}
	}
} 