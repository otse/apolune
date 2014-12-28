#include <iostream>

#include "../h.h"

#include "load.h"

ap::load::load() {
	std::cout << "load::load()" << std::endl;
}

ap::load::~load() {
	std::cout << "load::~load()" << std::endl;
}

std::string ap::load::doo(std::string *) {
	std::cout << "load::~doo()" << std::endl;
}