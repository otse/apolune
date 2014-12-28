#ifndef boilerplate_H
#define boilerplate_H

// INLINES
namespace boilerplate {
	struct basefile {
		char *buf;
		PHYSFS_sint64 len;
		PHYSFS_sint64 read;
	};
	
	inline basefile gbasefile(const char *n) {
		if ( ! PHYSFS_exists(n) ) {
			LOG("'"<<n<<"' not found in archive");
			return {nullptr,0,0};
		}
		
		PHYSFS_File *file;
		file = PHYSFS_openRead(n);
		PHYSFS_sint64 len = PHYSFS_fileLength(file);
		char *buf = new char[len];
		PHYSFS_sint64 read = PHYSFS_read(file, buf, 1, len);
		if ( ! read ) {
			LOG("'"<<n<<"' couldn't be read");
			return {nullptr,len,read};
		}
		
		PHYSFS_close(file);
		
		//LOG("'"<<n<<"' successfully read");
		
		return {buf, len, read};
	}
	
	inline char* cpychr(const char *q) {
		char *d = new char[strlen(q)+1];
		strcpy(d,q);
		return d;
	}
}

#endif