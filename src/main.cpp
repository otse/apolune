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

using namespace en;

#include "awesome.h"
#include "boilerplate.h"

#include "ap/gui/all.h"
#include "ap/craft/all.h"
#include "ap/ais/chicken.h"

#include "ap/shards/stats.cpp"
#include "ap/shards/debugbox.cpp"

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
	
	ap::debugbox::init();
}


void envars::make() {
	awesome();

	en::Region *r = new en::Region { 0,0,1024,1024 };

	using namespace ap::as;
	web = new en::FBO(&en::BLACK, *r);
	Draws &d = web->gdraws();
	d.sw(en::width*2);
	d.sh(en::height*2);
	//d.gregion()->x = r->w / 4;
	//d.gregion()->y = r->h / 4;
	d.yflip = false;

	en::add(&web->gdraws());
}

void awesome() {
	using namespace Awesomium;
	using namespace boilerplate;

	//WebStringArray arr = WebStringArray();
	//std::string glStr = "--use-gl=desktop";
	//arr.Push(Awesomium::WebString::CreateFromUTF8(glStr.c_str(), glStr.size()));

	WebConfig c = WebConfig();

	// Bind our method dispatcher to the WebView
	//ap::webview->set_js_method_handler(&madness);
	//c.additional_options = arr;

	WebPreferences prefs;
	prefs.enable_gpu_acceleration = true;
	prefs.enable_web_gl = true;
	prefs.enable_javascript = true;
	prefs.allow_file_access_from_file_url = true;
	prefs.allow_running_insecure_content = true;
	prefs.allow_universal_access_from_file_url = true;
	prefs.enable_web_security = false;
	prefs.enable_smooth_scrolling = true;

	using namespace ap::as;

	core = WebCore::Initialize(c);
	WebString empty = WebString::CreateFromUTF8("", strlen(""));
	session = core->CreateWebSession(empty, prefs);

	view = core->CreateWebView(1024, 1024, session);
	view->session()->AddDataSource(WSLit("baze"), new Baze());
	view->SetTransparent(true);
	view->set_load_listener(&load);

	JSValue var(view->CreateGlobalJavascriptObject(WSLit("app")));
	global = var.ToObject();

	/*madness.Bind(app_object,
	WSLit("sayHello"),
	JSDelegate(this, &TutorialApp::OnSayHello));*/
	
	//std::replace(file.begin(), file.end(), '\\', '/');
	WebURL url(WSLit("asset://baze/htmls/first.html"));
	view->LoadURL(url);

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

		return true;
	}
	
	return false;
}

void envars::frame() {
	//draws.resort = true;
	//draws.sort();
	
	if ( second() )
		secondpass();
		
	frameCount ++;
	
	oar::poll();
	react();

	ap::as::view->InjectMouseMove(mou::mx/2, mou::my/2);

	as::view->ExecuteJavascript(WSLit("second();"), WSLit(""));

	if (en::mou::PRESSED == en::mou::left)
		as::view->InjectMouseDown(kMouseButton_Left);
	else if (en::mou::RELEASED == en::mou::left)
		as::view->InjectMouseUp(kMouseButton_Left);

	if (en::mou::PRESSED == en::mou::right)
		as::view->InjectMouseDown(kMouseButton_Right);
	else if (en::mou::RELEASED == en::mou::right)
		as::view->InjectMouseUp(kMouseButton_Right);

	BitmapSurface* surface = (BitmapSurface*)ap::as::view->surface();

	if (NULL != surface) {
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, ap::as::web->gfbid());
		glBindTexture(GL_TEXTURE_2D, ap::as::web->gtid());
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, en::width, en::height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, surface->buffer());
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
	
	if ( world )
		world->step();
	
	en::drawsstep();

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