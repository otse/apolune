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

#include "ap/gui/all.h"


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

#include "awesome.h"

Awesomium::WebCore *ap::webcore;
Awesomium::WebView *ap::webview;
Awesomium::WebSession *ap::websession;
en::FBO *ap::web;

using namespace en;


#include "boilerplate.h"

#include "ap/gui/all.h"
#include "ap/craft/all.h"
#include "ap/ais/chicken.h"

#include "ap/shards/stats.cpp"
#include "ap/shards/debugbox.cpp"

void switches();


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

void switches() {}


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

void envars::make() {
	using namespace Awesomium;
	using namespace boilerplate;

	ap::webcore = WebCore::Initialize(WebConfig());
	ap::webview = ap::webcore->CreateWebView(en::width, en::height);
	ap::webview->session()->AddDataSource(WSLit("baze"), new MyDataSource());

	using namespace std;

	//std::replace(file.begin(), file.end(), '\\', '/');

	WebURL url(WSLit("asset://baze/htmls/first.html"));
	ap::webview->LoadURL(url);

	en::Region *r = new en::Region { 0,0,en::width,en::height };

	ap::web = new en::FBO(&en::BLACK, *r);
	ap::web->gdraws().yflip = false;

	en::add(&ap::web->gdraws());

	//loader = new Loader();
	//en::add(loader);
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


void secondpass();
void react();

void envars::frame() {
	//draws.resort = true;
	//draws.sort();
	
	if ( world && second() )
		secondpass();
		
	frameCount ++;
	
	oar::poll();
	react();

	//if (webview->IsLoading())
		webcore->Update();

	BitmapSurface* surface = (BitmapSurface*) webview->surface();

	if (NULL != surface) {
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, web->gfbid());
		glBindTexture(GL_TEXTURE_2D, web->gtid());
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, en::width, en::height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, surface->buffer());
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
	
	if ( world )
		world->step();
	
	en::drawsstep();
	
	return;
}

void secondpass() {
	stats::rebuild();
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