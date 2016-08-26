#pragma once

#include "h.h"

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>


using namespace Awesomium;

class MethodDispatcher;

namespace ap {
	namespace as {
		extern WebCore *core;
		extern WebView *view;
		extern WebSession *session;
		extern MethodDispatcher madness;

		extern en::FBO *web;
	}
}