#ifndef boilerplate_H
#define boilerplate_H

#include "h.h"
#include "awesome.h"

#include "Q:/physfs-2.0.3/physfs.h"
#include <Awesomium/DataSource.h>

#include <cstring>
#include <fstream> // for roaming

using namespace Awesomium;

// INLINES
namespace boilerplate {
	struct basefile {
		const char *n;
		char *buf;
		PHYSFS_sint64 len;
		PHYSFS_sint64 read;
	};
	
	const char* cpychr(const char *q);
	basefile gbasefile(const char *n);
	const char* toroaming(basefile bf);

	class MyDataSource : public DataSource {
	public:
		MyDataSource() { }
		virtual ~MyDataSource(void){}

		virtual void OnRequest(int, const ResourceRequest&, const WebString&);
	};
	
}

#endif