#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
// #include <unistd.h>
#include <sys/stat.h>

#include "files.h"


using namespace std;

bool ll::exists_test0 (char *name) {
    ifstream f(name);
    if (f.good()) {
        f.close();
        return true;
	} else {
        f.close();
        return false;
    }   
}

bool ll::exists_test1 (char *name) {
    if (FILE *file = fopen(name, "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

/*bool ll::exists_test2 (char *name) {
    return ( access( name, F_OK ) != -1 );
}*/

bool ll::exists_test3 (char *name) {
  struct stat buffer;
  return (stat (name, &buffer) == 0); 
}

bool ll::write(char *file, int len, char *stuff) {
	FILE * pFile;
	//fwrite(stuff, sizeof(char), len,
	return false;
}