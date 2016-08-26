#pragma once

#include "h.h"

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>


using namespace Awesomium;

class MethodDispatcher;

namespace ap {
	extern WebCore *webcore;
	extern WebView *webview;
	extern WebSession *websession;
	extern MethodDispatcher madness;

	extern en::FBO *web;
}