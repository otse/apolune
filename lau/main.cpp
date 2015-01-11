#include <algorithm>
#include <chrono>
#include <windows.h>
//#include <string>

#include <sstream> // for json, stats
#include <direct.h> // for mkdir
//#include <cstring> // for gl ext

#include "h.h"

#include "Q:/physfs-2.0.3/physfs.h"

double lau::dresize = 0.D;
bool lau::timeresize = false;

en::Vector<en::Draws *> lau::late;
en::List<en::Draws *> lau::draws;

PHYSFS_File *lau::base;
Json::Value lau::midrash;

en::Texture lau::tbackfont("laufontback.png");
en::Texture lau::tbarfont("laufontbar.png");

en::Texture lau::bg("laubg.png");
en::Texture lau::stars("stars.png");
en::Texture lau::starssides("starssides.png");

en::Region lau::rbg = {0, 0, 500, 74};
en::Region lau::rstars = {0, 0, 500, 74};
en::Region lau::rstarsl = {0, 0, 2, 74};
en::Region lau::rstarsr = {2, 0, 2, 74};

lau::Bar *lau::bar;

#include <boilerplate.h>


int main(int argc, const char* argv[]) {
	lau::dresize = en::dnow;
	
	en::width = 500;
	en::height = 74;
	
	en::window();
    
	exit(EXIT_SUCCESS);
	
	return 0;
}

/*
JNIEnv *lau::jvm() {
	using namespace std;
	const char *a = getenv("JAVA_HOME");
	
	string JAVA_HOME = string(a);
	
	if ( NULL == a ) {
		LOG("missing JAVA_HOME")
		return nullptr;
	}
	
	string classpath("-Djava.class.path=" + *en::extraction + "\\classes");
	LOG(classpath.c_str())
	
	string javahome("-Djava.library.path=" + JAVA_HOME + "\\lib");
	LOG(javahome.c_str())
	
	JavaVM* jvm;
	JNIEnv* env;
	JavaVMInitArgs args;
	JavaVMOption options[1];
	
	args.version = JNI_VERSION_1_8;
	args.nOptions = 1;
	
	options[0].optionString = boilerplate::cpychr(classpath.c_str());
	options[1].optionString = boilerplate::cpychr(javahome.c_str());
	
	args.options = options;
	args.ignoreUnrecognized = JNI_FALSE;
	
	JNI_CreateJavaVM(&jvm, (void **)&env, &args);
	return env;
}*/

void lau::roaming() {
	PHYSFS_init(0);
	PHYSFS_setSaneConfig("w/e", "apolune", "7z", 0, 0);
	PHYSFS_addToSearchPath(BASESTR, 0);
	
	char *appdata = getenv("APPDATA");
	en::extraction = new std::string(appdata);
	en::extraction->append("\\.apolune");
	mkdir(en::extraction->c_str());
	
	LOG("extraction path is " << en::extraction->c_str() );
}

void lau::add(en::Draws *p) {
	draws.l.push_back(p);
}

void lau::later(en::Draws *p) {
	late.v.push_back(p);
}

void lau::rm(en::Draws *s) {
	if ( nullptr == s )
		return;
	
	std::list<en::Draws *>::iterator it;
	for ( it = draws.l.begin(); it != draws.l.end(); it ++) {
		if ( *it == s ) {
			draws.l.erase(it);
			break;
		}
	}
}

void en::make() {
	lau::roaming();
	//lau::jvm();
	
	using namespace lau;
	//glutSetWindowTitle("Apolune Launcher");
	tbackfont.load();
	tbarfont.load();
	bg.load();
	stars.load();
	starssides.load();
	
	Draws *bgdraws = new Draws(GDEF, &bg, &rbg);
	add(bgdraws);
	
	bar = new Bar();
	add(bar);
}

void en::click() {
	
}

void lau::keyhandler() {
	using namespace sf;
	using bird = Keyboard;
	
	if ( bird::isKeyPressed( bird::Escape ) ) {
		bar->rewit("pressed esc... quitting...");
		sleep( seconds(.5) );
		exit(0);
	}
}

void en::frame() {
	using namespace lau;
		
	keyhandler();
	
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