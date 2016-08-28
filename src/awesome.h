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
			void ap::as::Load::OnBeginLoadingFrame(Awesomium::WebView* caller, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url, bool is_error_page);
			void ap::as::Load::OnFailLoadingFrame(Awesomium::WebView* caller, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url, int error_code,const Awesomium::WebString& error_desc);
			void ap::as::Load::OnFinishLoadingFrame(Awesomium::WebView* caller, int64 frame_id, bool is_main_frame, const Awesomium::WebURL& url);
			virtual void ap::as::Load::OnDocumentReady(Awesomium::WebView* caller, const Awesomium::WebURL& url);
		};

		extern Load load;
	}
}