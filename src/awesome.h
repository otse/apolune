#pragma once

#include "h.h"
#include "ll/js_delegate.h"

#include <Awesomium/WebCore.h>
#include <Awesomium/WebView.h>
#include <Awesomium/WebViewListener.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>


using namespace Awesomium;

namespace ap {
	namespace as {
		extern WebCore *core;
		extern WebView *view;
		extern WebSession *session;
		//extern MethodDispatcher madness;

		extern en::FBO *web;

		extern JSObject global;

		typedef std::map<std::wstring, JSDelegate> DelegateMap;
		extern DelegateMap delegateMap;

		class Load : public Awesomium::WebViewListener::Load {
		public:
			//Load();
			//~Load();
			virtual void OnBeginLoadingFrame(Awesomium::WebView*, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url, bool is_error_page);
			virtual void OnFailLoadingFrame(Awesomium::WebView*, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url, int error_code,const Awesomium::WebString& error_desc);
			virtual void OnFinishLoadingFrame(Awesomium::WebView*, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url);
			virtual void OnDocumentReady(Awesomium::WebView*, const Awesomium::WebURL& url);
		};

		extern Load load;
	}
}