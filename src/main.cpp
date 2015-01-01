#include <algorithm>
#include <chrono>
#include <windows.h>

#include "h.h"

#include "en/engine.h"
#include "en/fbo.h"
#include "en/draws.h"
#include "en/font.h"
#include "en/text.h"

#include "ap/gui/all.h"
#include "ap/loader.h"
#include "ap/lua.h"
#include "ap/start.h"
#include "ap/world.h"
#include "ap/ply.h"
#include "ap/def.h"

#include "ap/gui/all.h"


#include "Q:/physfs-2.0.3/physfs.h"
#include "Q:/jsoncpp-master/include/json/json.h"

#include <sstream> // for json, stats
#include <direct.h> // for mkdir
#include <cstring> // for gl ext


using namespace ap;
double ap::zoom = 3.d;
double ap::zoomto = 1;
double ap::zoomspeed = 1;

int ap::fps = 0;
int ap::frameCount = 0;

std::ofstream ap::log;

double ap::dresize = 0.D;
bool ap::timeresize = false;

Loader *ap::loader;
Lua *ap::lua;
World *ap::world = nullptr;
Ply *ap::ply = nullptr;

en::Vector<en::Draws *> ap::late;
en::List<en::Draws *> ap::draws;

PHYSFS_File *ap::base;
Json::Value ap::midrash;

start::Menu *ap::menu;
en::FBO *ap::foreground;
en::FBO *ap::lightmap;
en::FBO *ap::stars;
std::random_device ap::rd;
std::default_random_engine ap::e1(ap::rd());
std::mt19937 ap::rng(ap::rd());
std::uniform_real_distribution<double> ap::randy(.0D, 1.D);

ais::Chicken *ap::chicken;

using namespace en;
Text *ap::overlay;


#include "boilerplate.h"

#include "ap/shards/stats.cpp"
#include "ap/shards/debugbox.cpp"


int main(int argc, const char* argv[]) {
	ap::log.open(LOGFILE);
	LOG(VERSION);
	LOG("hi ô_ô")
	
	uint32_t seed = time(0);
	
	dresize = dnow;
	
	rng.seed(seed);
	
	en::window();
    
	exit(EXIT_SUCCESS);
	
	return 0;
}

void ap::roaming() {
	PHYSFS_init(0);
	PHYSFS_setSaneConfig("w/e", "apolune", "7z", 0, 0);
	PHYSFS_addToSearchPath(BASESTR, 0);
	
	char *appdata = getenv("APPDATA");
	extraction = new std::string(appdata);
	extraction->append("\\.apolune");
	mkdir(extraction->c_str());
	
	LOG("extraction path is " << extraction->c_str() );
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
	
	ap::debugbox::init();
}

void ap::add(en::Draws *p) {

	//int pos = group * GROUP_SATURATION;
	
	/*if ( ++ en::groups[group] ==  )
		en::groups[group] = group * GROUP_SATURATION;*/
		
	//order = en::groups[group];
	
	//en::List(
	//std::vector<Draws *>::iterator it;
	//it = draws.v.at(pos);
	
	//draws.v.insert(pos, p);
	//std::list<Draws *>::iterator it;
	//it = it + en::groups[p->group];
	
	draws.l.push_back(p);
	
	return;
	
	LOG("inserting at group " << p->group)
	Draws *o = nullptr;
	if ( nullptr == en::groups[p->group] ) {
		for ( int i = en::Group::COUNT-1; i >= 0; i-- ) {
			if ( nullptr != en::groups[i] )
				o = en::groups[i];
			else
				LOG("group " << i << " is nullptr")
		}
	}
	
	if ( nullptr != o ) {
		std::list<Draws *>::iterator it;
		int i = 0;
		for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
			i++;
			if ( o == *it ) {
				LOG("inserting after " << i)
				draws.l.insert(++it, p);
				break;
			} else {
				
			}
		}
	}
	else
		draws.l.push_back(p);
		
	en::groups[p->group] = p;
	
	LOG("-----")
	
	//draws.l.push_back(p);
}

void ap::later(en::Draws *p) {
	late.v.push_back(p);
}

void ap::rm(en::Draws *s) {
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

void en::make() {
	loader = new Loader();
	add(loader);
}

#define IDEAL_WIDTH 800
#define IDEAL_HEIGHT 600

void en::resize(int w, int h) {
	using namespace en;
	if ( debugbox::bfs ) {
		width = w;
		height = h;
		glViewport(0,0,w,h);
		world->resize();
	}
	else {
		if ( width != IDEAL_WIDTH ) {
			width = IDEAL_WIDTH;
			height = IDEAL_HEIGHT;
			world->resize();
			glViewport(0,0,width,height);
			//glutReshapeWindow(width, height);
		}
		else
		if ( w != IDEAL_WIDTH  ||  h != IDEAL_HEIGHT ) {
			dresize = dnow + 1000;
			timeresize = true;
			//dnow
		}
	}
}

void ap::timedresize() {
	if ( timeresize  &&  dresize-dnow <= 0 ) {
		//glutReshapeWindow(width, en::height);
		dresize = 0;
		timeresize = false;
	}
}

void secondpass() {
	stats::rebuild();
}

void en::click() {
	if ( keys['x'] ) {
		LOG(ply->gx() -xof+ en::mx << "," << ply->gy() -yof+ en::my)
	}
}

void ap::react() {
	if ( ply )
		ply->key();
		
	if ( nullptr != world  &&  DOWN == en::keys[(char)27] /* ESC */ ) {
		
	}
}


bool second() {
	static double dsecond = 0.;
	
	if ( dnow-dsecond >= 1000. ) {
		dsecond = dnow;
		fps = frameCount;
		frameCount = 0;
		return true;
	}
	
	return false;
}

void en::frame() {
	//draws.resort = true;
	//draws.sort();
	
	timedresize();
	
	if ( world && second() )
		secondpass();
		
	frameCount ++;
	
	react();
	
	if ( world )
		world->step();
	
	dnow = (now.QuadPart) * 1000.0 / frequency.QuadPart;
	
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
	
	return;
}