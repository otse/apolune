#include "stdafx.h"

#include "awesome.h"
#include "ll/method_dispatcher.h"

Awesomium::WebCore *ap::as::core;
Awesomium::WebView *ap::as::view;
Awesomium::WebSession *ap::as::session;
MethodDispatcher ap::as::madness;

en::FBO *ap::as::web;

JSObject ap::as::global;