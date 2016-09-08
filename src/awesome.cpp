#include "stdafx.h"

#include "awesome.h"
#include "ap/world.h"
#include "en/draws.h"
#include "en/fbo.h"

#include "ap/ship/all.h"

#include "ll/method_dispatcher.h"

#include "boilerplate.h"


using namespace ap::as;

Awesomium::WebCore *ap::as::core;
Awesomium::WebView *ap::as::view;
Awesomium::WebSession *ap::as::session;
MethodDispatcher ap::as::dispatcher;

en::FBO *ap::as::web;

JSObject ap::as::global;

Load ap::as::load;

void ap::as::Load::OnBeginLoadingFrame(Awesomium::WebView* caller,
	int64 frame_id,
	bool is_main_frame,
	const Awesomium::WebURL& url,
	bool is_error_page) {
	LOG("OnBeginLoadingFrame")
}

/// This event occurs when a frame fails to load. See error_desc
/// for additional information.
void ap::as::Load::OnFailLoadingFrame(Awesomium::WebView* caller,
	int64 frame_id,
	bool is_main_frame,
	const Awesomium::WebURL& url,
	int error_code,
	const Awesomium::WebString& error_desc) {
	LOG("OnFailLoadingFrame")
}

/// This event occurs when the page finishes loading a frame.
/// The main frame always finishes loading last for a given page load.
void ap::as::Load::OnFinishLoadingFrame(Awesomium::WebView* caller,
	int64 frame_id,
	bool is_main_frame,
	const Awesomium::WebURL& url) {
	if (nullptr != ap::world) {
		LOG("webview 1:1 for ui")
		en::Draws &d = web->gdraws();
		d.sx(0);
		d.sy(0);
		d.sw(en::width);
		d.sh(en::height);
	}
	LOG("OnFinishLoadingFrame")
}

/// This event occurs when the DOM has finished parsing and the
/// window object is available for JavaScript execution.
void ap::as::Load::OnDocumentReady(Awesomium::WebView* caller,
	const Awesomium::WebURL& url) {
	LOG("OnDocumentReady")
}

void ap::as::mawe() {
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

	view = core->CreateWebView(en::width, en::height, session);
	view->session()->AddDataSource(WSLit("baze"), new Baze());
	view->set_load_listener(&load);
	view->set_js_method_handler(&dispatcher);

	JSValue var(view->CreateGlobalJavascriptObject(WSLit("app")));

	global = var.ToObject();

	as::global.SetPropertyAsync(WSLit("orientation"), JSValue(0));
	as::global.SetPropertyAsync(WSLit("w"), JSValue(en::width/2));
	as::global.SetPropertyAsync(WSLit("h"), JSValue(en::height/2));

	dispatcher.Bind(global, WSLit("start"), JSDelegate(&start));
	dispatcher.Bind(global, WSLit("scale"), JSDelegate(&scale));
	dispatcher.Bind(global, WSLit("crossSection"), JSDelegate(&crossSection));

	WebURL url(WSLit("asset://baze/htmls/first.html"));
	view->LoadURL(url);

	en::Region *r = new en::Region{ 0,0,en::width,en::height };

	using namespace ap::as;
	web = new en::FBO(&en::BLACK, *r);
	en::Draws &d = web->gdraws();
	d.sw(en::width * 2);
	d.sh(en::height * 2);
	//d.gregion()->x = r->w / 4;
	//d.gregion()->y = r->h / 4;
	d.yflip = false;

	//en::add(&web->gdraws());
}

void ap::as::start(WebView* caller, const JSArray& args) {
	LOG("start")

	//web->gdraws().remove = true;

	WebURL url(WSLit("asset://baze/htmls/ui.html"));
	as::global.SetPropertyAsync(WSLit("w"), JSValue(en::width));
	as::global.SetPropertyAsync(WSLit("h"), JSValue(en::height));
	view->LoadURL(url);
	view->SetTransparent(true);

	ap::launchworld();
}

void ap::as::scale(WebView* caller, const JSArray& args) {
	WebString value = args[0].ToString();

	LOG("scale " << ToString(value))

	if (value == WSLit("3x")) {
		ap::scale = 3;
	}
	else if (value == WSLit("2x")) {
		ap::scale = 2;
	}
	else if (value == WSLit("1x")) {
		ap::scale = 1;
	}

	world->rescale(); // not used

}

void ap::as::crossSection(WebView* caller, const JSArray& args) {
	WebString value = args[0].ToString();

	if (value == WSLit("on")) {
		ap::world->craft->crosssection = true;
		LOG("LOL")
	}
	else if (value == WSLit("off")) {
		ap::world->craft->crosssection = false;
		LOG("NO")
	}
	return;

}