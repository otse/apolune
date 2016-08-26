#include "stdafx.h"

#pragma once

#include "boilerplate.h"

using namespace Awesomium;


// SOME INLINES
namespace boilerplate {
	const char* cpychr(const char *q) {
		char *d = new char[strlen(q) + 1];
		strcpy(d, q);
		return d;
	}

	basefile gbasefile(const char *n) {

		if (!PHYSFS_exists(n)) {
			std::cout << "'" << n << "' not found in archive" << std::endl;
			return { n,nullptr,0,0 };
		}

		PHYSFS_File *file;
		file = PHYSFS_openRead(n);
		PHYSFS_sint64 len = PHYSFS_fileLength(file);
		char *buf = new char[len+1];
		PHYSFS_sint64 read = PHYSFS_read(file, buf, 1, len);
		buf[len] = '\0';
		if (!read) {
			std::cout << "'" << n << "' couldn't be read" << std::endl;
			return { n, nullptr, len, read };
		}

		PHYSFS_close(file);

		LOG("'"<<n<<"' successfully read");

		return { n, buf, len, read };
	}

	const char* toroaming(basefile bf) {
		std::ofstream disk;
		std::string loc = *en::extraction + '\\' + bf.n;
		LOG(loc.c_str())

		disk.open(loc, std::ios::out | std::ios::trunc | std::ios::binary);
		disk.write(bf.buf, bf.len);
		disk.close();

		return cpychr(loc.c_str());
	}

	void boilerplate::Baze::OnRequest(int request_id, const ResourceRequest& request, const WebString& path) {
		basefile bf = gbasefile(ToString(path).c_str());
		const unsigned char* a = reinterpret_cast<const unsigned char*>(cpychr(bf.buf));
		SendResponse( request_id, strlen(bf.buf), a, WSLit("text/html") );
	};

}