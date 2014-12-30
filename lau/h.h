#ifndef h_H
#define h_H

#warning building launcher

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "Q:/jsoncpp-master/include/json/json.h"
#include <C:/Program Files (x86)/Java/jdk1.8.0_20/include/jni.h>


#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <random>

#define LOG(A) std::cout << A << std::endl;

#define EN_WINDOWNAME "downloading launcher files"
#include "../src/en/engine.h"

#define APOLUNESTR "launcher"
#define BASESTR "launcherbase"


#define RANDRANGE(base, var) \
	((ap::ilrand() * var) + base) \

typedef struct PHYSFS_File PHYSFS_File; // 'forward declaration'


namespace en {
	void resize(int, int);
	void make();
	void frame();
	void click();
}

namespace lau {
	extern const en::Font fontlauncher;
	extern en::Texture texturefontlauncher;
	extern en::Texture bar;
	
	extern unsigned char clifontwhitedata[];
	extern unsigned char clifontwhitedata[];
	
	void keyhandler();
	void resize(int, int);
	extern double dresize;
	extern bool timeresize;
	void timedresize();
	void secondpass();
	
	extern en::Vector<en::Draws*> late;
	extern en::List<en::Draws*> draws;
	
	void roaming();
	JNIEnv *jvm();
	extern PHYSFS_File *base;
	bool commentary();
	extern Json::Value midrash;
	
	//
	void add(en::Draws *);
	void later(en::Draws *);
	void rm(en::Draws *);
	
	extern en::Text *overlay;
}

#endif