#include "stdafx.h"

#include "awesome.h"
#include "ll/method_dispatcher.h"

using namespace ap::as;

Awesomium::WebCore *ap::as::core;
Awesomium::WebView *ap::as::view;
Awesomium::WebSession *ap::as::session;
//MethodDispatcher ap::as::madness;

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
	LOG("OnFinishLoadingFrame")
}

/// This event occurs when the DOM has finished parsing and the
/// window object is available for JavaScript execution.
void ap::as::Load::OnDocumentReady(Awesomium::WebView* caller,
	const Awesomium::WebURL& url) {
	LOG("OnDocumentReady")
}