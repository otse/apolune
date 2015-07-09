#include <iostream>

#include "../h.h"
#include "../en/font.h"
#include "def.h"

using namespace en;
glyph gnormal1[] = {
		{' ', 0, 153, 4, 0, 0},
		{'a', 0, 153, 8, 0, 0},
		{'b', 0, 153, 8, 0, 0},
		{'c', 0, 153, 6, 0, 0},
		{'d', 0, 153, 7, 0, 0},
		{'e', 0, 153, 6, 0, 0},
		{'f', 3, 153, 5, 1, 0},
		{'g', 0, 153, 7, 0, 0},
		{'h', 0, 153, 8, 0, 0},
		{'i', 0, 153, 3, 0, 0},
		{'j', 2, 153, 5, 2, 0},
		{'k', 0, 153, 7, 0, 1},
		{'l',-1, 153, 3, 0, 0},
		{'m', 0, 153, 11, 0, 0},
		{'n', 0, 153, 8, 0, 0},
		{'o', 0, 153, 8, 0, 0},
		{'p', 0, 153, 8, 0, 0},
		{'q', 0, 153, 7, 0, 0},
		{'r', 0, 153, 5, 0, 0},
		{'s', 0, 153, 6, 0, 0},
		{'t', 3, 153, 5, 1, 0},
		{'u', 0, 153, 8, 0, 0},
		{'v', 0, 153, 7, 0, 1},
		{'w', 3, 153, 10, 0, 1},
		{'x', 3, 153, 6, 0, 0},
		{'y', 0, 153, 7, 0, 1},
		{'z', 3, 153, 7, 0, 0},
		
		{'1', 4, 153, 7, 0, 0},
		{'2', 0, 153, 7, 0, 0},
		{'3', 0, 153, 7, 0, 0},
		{'4', 0, 153, 7, 0, 0},
		{'5', 0, 153, 7, 0, 0},
		{'6', 0, 153, 7, 0, 0},
		{'7', 0, 153, 7, 0, 0},
		{'8', 0, 153, 7, 0, 0},
		{'9', 0, 153, 7, 0, 0},
		{'0', 0, 153, 7, 0, 0},
		
		{'\0'},
		{'A', 0, 173, 9, 0, 0},
		{'B', 0, 173, 8, 0, 0},
		{'C', 0, 173, 9, 0, 0},
		{'D', 0, 173, 10, 0, 0},
		{'E', 0, 173, 7, 0, 0},
		{'F', 0, 173, 7, 0, 0},
		{'G', 0, 173, 9, 0, 0},
		{'H', 0, 173, 9, 0, 0},
		{'I', 0, 173,  3, 0, 0},
		{'J', 0, 173, 5, 0, 0},
		{'K', 0, 173, 8, 0, 0},
		{'L', 0, 173, 5, 0, 0},
		{'M', 0, 173, 11, 0, 0},
		{'N', 0, 173, 10, 0, 0},
		{'O', 0, 173, 11, 0, 0},
		{'P', 0, 173, 8, 0, 0},
		{'Q', 0, 173, 11, 0, 0},
		{'R', 0, 173, 8, 0, 0},
		{'S', 0, 173, 7, 0, 0},
		{'T', 0, 173, 7, 0, 0},
		{'U', 0, 173, 9, 0, 0},
		{'V', 0, 173, 9, 0, 0},
		{'W', 3, 173, 13, 0, 0},
		{'X', 0, 173, 8, 0, 0},
		{'Y', 0, 173, 8, 0, 0},
		{'Z', 3, 173, 8, 0, 0},

		{'\0'},
		{'.', 0, 193,  3, 0, 0},
		{',', 0, 193,  3, 0, 0},
		{'?', 0, 193,  6, 0, 0},
		{'!', 0, 193,  5, 0, 0},
		{'\'', 0, 193,  3, 0, 0},
		{'"', 0, 193,  5, 0, 0},
		{'-', 0, 193,  6, 0, 0}
};
int lnormal1 = sizeof(gnormal1) / sizeof(gnormal1[0]);
const Font ap::normal1("normal1", 20, 16, false, gnormal1, lnormal1, textures::normal1);

glyph gnormal2[] = {
		{' ', 0, 153, 4, 0, 0},
		{'a', 6, 153, 7, 0, 0},
		{'b', 15, 153, 8, 0, 0},
		{'c', 25, 153, 6, 0, 0},
		{'d', 33, 153, 8, 0, 0},
		{'e', 43, 153, 7, 0, 0},
		{'f', 52, 153, 5, 0, 1},
		{'g', 58, 153, 8, 0, 0},
		{'h', 68, 153, 8, 0, 1},
		{'i', 77, 153, 3, 0, 0},
		{'j', 80, 153, 5, 2, 0},
		{'k', 87, 153, 7, 0, 1},
		{'l', 95, 153, 3, 0, 0},
		{'m', 100, 153, 12, 0, 0},
		{'n', 114, 153, 8, 0, 1},
		{'o', 123, 153, 8, 0, 0},
		{'p', 133, 153, 8, 0, 0},
		{'q', 143, 153, 8, 0, 0},
		{'r', 153, 153, 5, 0, 0},
		{'s', 160, 153, 5, 0, 0},
		{'t', 167, 153, 5, 0, 1},
		{'u', 173, 153, 8, 0, 1},
		{'v', 182, 153, 7, 0, 1},
		{'w', 190, 153, 10, 0, 1},
		{'x', 201, 153, 6, 0, 0},
		{'y', 209, 153, 7, 0, 1},
		{'z', 217, 153, 7, 0, 1},
		
		{'A', 0, 172, 9, 0, 0},
		{'B', 11, 172, 8, 0, 0},
		{'C', 21, 172, 9, 0, 0},
		{'D', 32, 172, 9, 0, 0},
		{'E', 43, 172, 7, 0, 0},
		{'F', 53, 172, 7, 0, 0},
		{'G', 61, 172, 9, 0, 0},
		{'H', 72, 172, 9, 0, 0},
		{'I', 83, 172, 3, 0, 0},
		{'J', 88, 172, 5, 0, 0},
		{'K', 95, 172, 7, 0, 0},
		{'L', 104, 172, 6, 0, 0},
		{'M', 112, 172, 12, 0, 0},
		{'N', 126, 172, 10, 0, 0},
		{'O', 138, 172, 11, 0, 0},
		{'P', 151, 172, 8, 0, 0},
		{'Q', 161, 172, 11, 0, 0},
		{'R', 174, 172, 8, 0, 0},
		{'S', 184, 172, 7, 0, 0},
		{'T', 193, 172, 7, 0, 0},
		{'U', 202, 172, 9, 0, 0},
		{'V', 213, 172, 8, 0, 0},
		{'W', 223, 172, 13, 0, 0},
		{'X', 238, 172, 8, 0, 0},
		{'Y', 248, 172, 8, 0, 0},
		{'Z', 258, 172, 8, 0, 0},
		
		{'.', 0, 191, 3, 0, 0},
		{',', 5, 191, 3, 0, 0},
		{'?', 10, 191, 6, 0, 0},
		{'!', 18, 191, 4, 0, 0},
		{'\'', 24, 191, 3, 0, 0},
		{'"', 29, 191, 5, 0, 0},
		{':', 36, 191, 3, 0, 0},
		{';', 41, 191, 3, 0, 0},
		{'-', 46, 191, 6, 0, 0},
		{'=', 54, 191, 9, 0, 0},
		{'(', 65, 191, 4, 0, 0},
		{')', 71, 191, 4, 0, 0},
		{'/', 77, 191, 5, 0, 0},
		{'\\', 84, 191, 5, 0, 0},
		
		{'0', 0, 210, 7, 0, 0},
		{'1', 9, 210, 7, 0, 0},
		{'2', 18, 210, 7, 0, 0},
		{'3', 27, 210, 7, 0, 0},
		{'4', 36, 210, 7, 0, 0},
		{'5', 45, 210, 7, 0, 0},
		{'6', 54, 210, 7, 0, 0},
		{'7', 63, 210, 7, 0, 0},
		{'8', 72, 210, 7, 0, 0},
		{'9', 81, 210, 7, 0, 0}
};
int lnormal2 = sizeof(gnormal2) / sizeof(gnormal2[0]);
const Font ap::normal2("normal", 19, 16, true, gnormal2, lnormal2, textures::sheet);


glyph gbig1[] = {
	{' ', 0, 0, 10, 0, 0},
	{'a', 0, 0, 19, 0, 0},
	{'b', 0, 0, 21, 0, 0},
	{'c', 0, 0, 17, 0, 0},
	{'d', 0, 0, 21, 0, 0},
	{'e', 0, 0, 19, 0, 0},
	{'f', 0, 0, 12, 0, 2},
	{'g', 8, 0, 21, 0, 0},
	{'h', 0, 0, 20, 0, 0},
	{'i', 0, 0, 8, 0, 0},
	{'j', 5, 0, 13, 5, 0},
	{'k', 0, 0, 17, 0, 0},
	{'l', 0, 0, 8, 0, 0},
	{'m', 0, 0, 31, 0, 0},
	{'n', 0, 0, 20, 0, 0},
	{'o', 0, 0, 21, 0, 0},
	{'p', 0, 0, 21, 0, 0},
	{'q', 0, 0, 21, 0, 0},
	{'r', 0, 0, 13, 0, 0},
	{'s', 0, 0, 15, 0, 0},
	{'t', 0, 0, 11, 0, 0},
	{'u', 0, 0, 20, 0, 0},
	{'v', 0, 0, 17, 0, 0},
	{'w', 0, 0, 26, 0, 0},
	{'x', 0, 0, 16, 0, 0},
	{'y', 0, 0, 17, 0, 0},
	{'z', 0, 0, 18, 0, 0},
	
	// numbers aren't done yet
	{'0', 0, 0, 18, 0, 0},
	{'1', 0, 0, 18, 0, 0},
	{'2', 0, 0, 18, 0, 0},
	{'3', 0, 0, 18, 0, 0},
	{'4', 0, 0, 18, 0, 0},
	{'5', 0, 0, 18, 0, 0},
	{'6', 0, 0, 18, 0, 0},
	{'7', 0, 0, 18, 0, 0},
	{'8', 0, 0, 18, 0, 0},
	{'9', 0, 0, 18, 0, 0},

	{'A', 0, 51, 24, 0, 0},
	{'B', 0, 51, 21, 0, 0},
	{'C', 0, 51, 24, 0, 0},
	{'D', 0, 51, 26, 0, 0},
	{'E', 0, 51, 19, 0, 0},
	{'F', 0, 51, 18, 0, 0},
	{'G', 0, 51, 25, 0, 0},
	{'H', 0, 51, 26, 0, 0},
	{'I', 0, 51, 9, 0, 0},
	{'J', 0, 51, 12, 0, 0},
	{'K', 0, 51, 20, 0, 0},
	{'L', 0, 51, 17, 0, 0},
	{'M', 0, 51, 32, 0, 0},
	{'N', 0, 51, 27, 0, 0},
	{'O', 0, 51, 29, 0, 0},
	{'P', 0, 51, 21, 0, 0},
	{'Q', 0, 51, 29, 0, 0},
	{'R', 0, 51, 21, 0, 0},
	{'S', 0, 51, 19, 0, 0},
	{'T', 0, 51, 19, 0, 0},
	{'U', 0, 51, 25, 0, 0},
	{'V', 0, 51, 23, 0, 0},
	{'W', 0, 51, 34, 0, 0},
	{'X', 0, 51, 21, 0, 0},
	{'Y', 0, 51, 21, 0, 0},
	{'Z', 0, 51, 22, 0, 0},

	{'.', 0, 51 * 2, 8, 0, 0},
	{',', 0, 51 * 2, 8, 0, 0},
	{'?', 0, 51 * 2, 16, 0, 0},
	{'!', 0, 51 * 2, 11, 0, 0},
	{'\'', 0, 51 * 2, 8, 0, 0},
	{'"', 0, 51 * 2, 13, 0, 0},
	{':', 0, 51 * 2, 8, 0, 0},
	{';', 0, 51 * 2, 8, 0, 0},
	{'-', 0, 51 * 2, 15, 0, 0},
	{'=', 0, 51 * 2, 25, 0, 0}
};
int lbig1 = sizeof(gbig1) / sizeof(gbig1[0]);
const Font ap::big1("big", 51, 10, false, gbig1, lbig1, textures::sheet);

glyph gstatfont[] = {
		{'\0'},
		{'a', 1, 0, 8, 0, 1},
		{'b', 3, 0, 8, 0, 1},
		{'c', 3, 0, 7, 0, 1},
		{'d', 3, 0, 9, 0, 1},
		{'e', 3, 0, 7, 0, 1},
		{'f', 3, 0, 6, 0, 1},
		{'g', 3, 0, 8, 0, 1},
		{'h', 3, 0, 9, 0, 1},
		{'i', 3, 0, 4, 0, 1},
		{'j', 3, 0, 5, 0, 1},
		{'k', 3, 0, 7, 0, 1},
		{'l', 3, 0, 5, 0, 1},
		{'m', 3, 0, 12, 0, 1},
		{'n', 3, 0, 8, 0, 1},
		{'o', 3, 0, 8, 0, 1},
		{'p', 3, 0, 9, 0, 1},
		{'q', 3, 0, 8, 0, 1},
		{'r', 3, 0, 6, 0, 1},
		{'s', 3, 0, 7, 0, 1},
		{'t', 3, 0, 5, 0, 1},
		{'u', 3, 0, 9, 0, 1},
		{'v', 3, 0, 7, 0, 1},
		{'w', 3, 0, 10, 0, 1},
		{'x', 3, 0, 7, 0, 1},
		{'y', 3, 0, 7, 0, 1},
		{'z', 3, 0, 7, 0, 1},

		{'\0'},
		{'A', 1, 16, 9, 0, 1},
		{'B', 3, 16, 8, 0, 1},
		{'C', 3, 16, 9, 0, 1},
		{'D', 3, 16, 10, 0, 1},
		{'E', 3, 16, 8, 0, 1},
		{'F', 3, 16, 7, 0, 1},
		{'G', 3, 16, 9, 0, 1},
		{'H', 3, 16, 10, 0, 1},
		{'I', 3, 16, 5, 0, 1},
		{'J', 3, 16, 6, 0, 1},
		{'K', 3, 16, 9, 0, 1},
		{'L', 3, 16, 7, 0, 1},
		{'M', 3, 16, 12, 0, 1},
		{'N', 3, 16, 10, 0, 1},
		{'O', 3, 16, 10, 0, 1},
		{'P', 3, 16, 8, 0, 1},
		{'Q', 3, 16, 11, 0, 1},
		{'R', 3, 16, 8, 0, 1},
		{'S', 3, 16, 8, 0, 1},
		{'T', 3, 16, 8, 0, 1},
		{'U', 3, 16, 9, 0, 1},
		{'V', 3, 16, 9, 0, 1},
		{'W', 3, 16, 13, 0, 1},
		{'X', 3, 16, 8, 0, 1},
		{'Y', 3, 16, 8, 0, 1},
		{'Z', 3, 16, 8, 0, 1},

		{'\0'},
		{'1', 1, 32, 8, 0, 1},
		{'2', 3, 32, 8, 0, 1},
		{'3', 3, 32, 8, 0, 1},
		{'4', 3, 32, 8, 0, 1},
		{'5', 3, 32, 8, 0, 1},
		{'6', 3, 32, 8, 0, 1},
		{'7', 3, 32, 8, 0, 1},
		{'8', 3, 32, 8, 0, 1},
		{'9', 3, 32, 7, 0, 1},
		{'0', 3, 32, 8, 0, 1},

		{'\0'},
		{' ', 1, 48, 5, 0, 1},
		{'.', 3, 48, 4, 0, 1},
		{',', 3, 48, 5, 0, 1},
		{'\'', 3, 48, 4, 0, 1},
		{'"', 3, 48, 7, 0, 1}
};
int lstatfont = sizeof(gstatfont) / sizeof(gstatfont[0]);
const Font ap::statfont("stat font", 15, 11, false, gstatfont, lstatfont, textures::statfont);

glyph gvaluefont[] = {
		{'\0'},
		{'a', 0, 0, 11, 2, 2},
		{'b', 1, 0, 11, 2, 2},
		{'c', 1, 0, 11, 2, 2},
		{'d', 1, 0, 11, 2, 2},
		{'e', 1, 0, 11, 2, 2},
		{'f', 1, 0, 11, 2, 2},
		{'g', 1, 0, 11, 2, 2},
		{'h', 1, 0, 11, 2, 2},
		{'i', 1, 0, 11, 2, 2},
		{'j', 1, 0, 11, 2, 2},
		{'k', 1, 0, 11, 2, 2},
		{'l', 1, 0, 11, 2, 2},
		{'m', 1, 0, 11, 2, 2},
		{'n', 1, 0, 11, 2, 2},
		{'o', 1, 0, 11, 2, 2},
		{'p', 1, 0, 11, 2, 2},
		{'q', 1, 0, 11, 2, 2},
		{'r', 1, 0, 11, 2, 2},
		{'s', 1, 0, 11, 2, 2},
		{'t', 1, 0, 11, 2, 2},
		{'u', 1, 0, 11, 2, 2},
		{'v', 1, 0, 11, 2, 2},
		{'w', 1, 0, 11, 2, 2},
		{'x', 1, 0, 11, 2, 2},
		{'y', 1, 0, 11, 2, 2},
		{'z', 1, 0, 11, 2, 2},
		
		{'\0'},
		{'A', 0, 15, 11, 2, 2},
		{'B', 1, 15, 11, 2, 2},
		{'C', 1, 15, 11, 2, 2},
		{'D', 1, 15, 11, 2, 2},
		{'E', 1, 15, 11, 2, 2},
		{'F', 1, 15, 11, 2, 2},
		{'G', 1, 15, 11, 2, 2},
		{'H', 1, 15, 11, 2, 2},
		{'I', 1, 15, 11, 2, 2},
		{'J', 1, 15, 11, 2, 2},
		{'K', 1, 15, 11, 2, 2},
		{'L', 1, 15, 11, 2, 2},
		{'M', 1, 15, 11, 2, 2},
		{'N', 1, 15, 11, 2, 2},
		{'O', 1, 15, 11, 2, 2},
		{'P', 1, 15, 11, 2, 2},
		{'Q', 1, 15, 11, 2, 2},
		{'R', 1, 15, 11, 2, 2},
		{'S', 1, 15, 11, 2, 2},
		{'T', 1, 15, 11, 2, 2},
		{'U', 1, 15, 11, 2, 2},
		{'V', 1, 15, 11, 2, 2},
		{'W', 1, 15, 11, 2, 2},
		{'X', 1, 15, 11, 2, 2},
		{'Y', 1, 15, 11, 2, 2},
		{'Z', 1, 15, 11, 2, 2},
		
		{'\0'},
		{'1', 0, 30, 11, 2, 2},
		{'2', 1, 30, 11, 2, 2},
		{'3', 1, 30, 11, 2, 2},
		{'4', 1, 30, 11, 2, 2},
		{'5', 1, 30, 11, 2, 2},
		{'6', 1, 30, 11, 2, 2},
		{'7', 1, 30, 11, 2, 2},
		{'8', 1, 30, 11, 2, 2},
		{'9', 1, 30, 11, 2, 2},
		{'0', 1, 30, 11, 2, 2},
		
		{'\0'},
		{' ', 0, 45, 11, 2, 2},
		{'.', 1, 45, 11, 2, 2},
		{',', 1, 45, 11, 2, 2},
		{'\'', 1, 45, 11, 2, 2},
		{'"', 1, 45, 11, 2, 2}
};
int lvaluefont = sizeof(gvaluefont) / sizeof(gvaluefont[0]);
const Font ap::valuefont("value font", 14, 11, false, gvaluefont, lvaluefont, textures::valuefont);

glyph gvaluefontchangeable[] = {
		{'\0'},
		{'a', 1, 0, 9, 1, 1},
		{'b', 3, 0, 9, 1, 1},
		{'c', 3, 0, 9, 1, 1},
		{'d', 3, 0, 9, 1, 1},
		{'e', 3, 0, 9, 1, 1},
		{'f', 3, 0, 9, 1, 1},
		{'g', 3, 0, 9, 1, 1},
		{'h', 3, 0, 9, 1, 1},
		{'i', 3, 0, 9, 1, 1},
		{'j', 3, 0, 9, 1, 1},
		{'k', 3, 0, 9, 1, 1},
		{'l', 3, 0, 9, 1, 1},
		{'m', 3, 0, 9, 1, 1},
		{'n', 3, 0, 9, 1, 1},
		{'o', 3, 0, 9, 1, 1},
		{'p', 3, 0, 9, 1, 1},
		{'q', 3, 0, 9, 1, 1},
		{'r', 3, 0, 9, 1, 1},
		{'s', 3, 0, 9, 1, 1},
		{'t', 3, 0, 9, 1, 1},
		{'u', 3, 0, 9, 1, 1},
		{'v', 3, 0, 9, 1, 1},
		{'w', 3, 0, 9, 1, 1},
		{'x', 3, 0, 9, 1, 1},
		{'y', 3, 0, 9, 1, 1},
		{'z', 3, 0, 9, 1, 1},
		
		{'\0'},
		{'A', 1, 15, 9, 1, 1},
		{'B', 3, 15, 9, 1, 1},
		{'C', 3, 15, 9, 1, 1},
		{'D', 3, 15, 9, 1, 1},
		{'E', 3, 15, 9, 1, 1},
		{'F', 3, 15, 9, 1, 1},
		{'G', 3, 15, 9, 1, 1},
		{'H', 3, 15, 9, 1, 1},
		{'I', 3, 15, 9, 1, 1},
		{'J', 3, 15, 9, 1, 1},
		{'K', 3, 15, 9, 1, 1},
		{'L', 3, 15, 9, 1, 1},
		{'M', 3, 15, 9, 1, 1},
		{'N', 3, 15, 9, 1, 1},
		{'O', 3, 15, 9, 1, 1},
		{'P', 3, 15, 9, 1, 1},
		{'Q', 3, 15, 9, 1, 1},
		{'R', 3, 15, 9, 1, 1},
		{'S', 3, 15, 9, 1, 1},
		{'T', 3, 15, 9, 1, 1},
		{'U', 3, 15, 9, 1, 1},
		{'V', 3, 15, 9, 1, 1},
		{'W', 3, 15, 9, 1, 1},
		{'X', 3, 15, 9, 1, 1},
		{'Y', 3, 15, 9, 1, 1},
		{'Z', 3, 15, 9, 1, 1},
		
		{'\0'},
		{'1', 1, 30, 9, 1, 1},
		{'2', 3, 30, 9, 1, 1},
		{'3', 3, 30, 9, 1, 1},
		{'4', 3, 30, 9, 1, 1},
		{'5', 3, 30, 9, 1, 1},
		{'6', 3, 30, 9, 1, 1},
		{'7', 3, 30, 9, 1, 1},
		{'8', 3, 30, 9, 1, 1},
		{'9', 3, 30, 9, 1, 1},
		{'0', 3, 30, 9, 1, 1},
		
		{'\0'},
		{' ', 1, 45, 9, 1, 1},
		{'.', 3, 45, 9, 1, 1},
		{',', 3, 45, 9, 1, 1},
		{'\'', 3, 45, 9, 1, 1},
		{'"', 3, 45, 9, 1, 1}
};
int lvaluefontchangeable = sizeof(gvaluefontchangeable) / sizeof(gvaluefontchangeable[0]);
const Font ap::valuefontchangeable("value font changeable", 14, 11, false, gvaluefontchangeable, lvaluefontchangeable, textures::valuefontchangeable);

glyph gnotice[] = {
		{'\0'},
		{'a', 1, 0, 9, 0, 1},
		{'b', 3, 0, 9, 0, 1},
		{'c', 3, 0, 9, 0, 1},
		{'d', 3, 0, 9, 0, 1},
		{'e', 3, 0, 9, 0, 1},
		{'f', 3, 0, 9, 0, 1},
		{'g', 3, 0, 9, 0, 1},
		{'h', 3, 0, 9, 0, 1},
		{'i', 3, 0, 9, 0, 1},
		{'j', 3, 0, 9, 0, 1},
		{'k', 3, 0, 9, 0, 1},
		{'l', 3, 0, 9, 0, 1},
		{'m', 3, 0, 9, 0, 1},
		{'n', 3, 0, 9, 0, 1},
		{'o', 3, 0, 9, 0, 1},
		{'p', 3, 0, 9, 0, 1},
		{'q', 3, 0, 9, 0, 1},
		{'r', 3, 0, 9, 0, 1},
		{'s', 3, 0, 9, 0, 1},
		{'t', 3, 0, 9, 0, 1},
		{'u', 3, 0, 9, 0, 1},
		{'v', 3, 0, 9, 0, 1},
		{'w', 3, 0, 9, 0, 1},
		{'x', 3, 0, 9, 0, 1},
		{'y', 3, 0, 9, 0, 1},
		{'z', 3, 0, 9, 0, 1},

		{'\0'},
		{'A', 1, 13, 9, 0, 1},
		{'B', 3, 13, 9, 0, 1},
		{'C', 3, 13, 9, 0, 1},
		{'D', 3, 13, 9, 0, 1},
		{'E', 3, 13, 9, 0, 1},
		{'F', 3, 13, 9, 0, 1},
		{'G', 3, 13, 9, 0, 1},
		{'H', 3, 13, 9, 0, 1},
		{'I', 3, 13, 9, 0, 1},
		{'J', 3, 13, 9, 0, 1},
		{'K', 3, 13, 9, 0, 1},
		{'L', 3, 13, 9, 0, 1},
		{'M', 3, 13, 9, 0, 1},
		{'N', 3, 13, 9, 0, 1},
		{'O', 3, 13, 9, 0, 1},
		{'P', 3, 13, 9, 0, 1},
		{'Q', 3, 13, 9, 0, 1},
		{'R', 3, 13, 9, 0, 1},
		{'S', 3, 13, 9, 0, 1},
		{'T', 3, 13, 9, 0, 1},
		{'U', 3, 13, 9, 0, 1},
		{'V', 3, 13, 9, 0, 1},
		{'W', 3, 13, 9, 0, 1},
		{'X', 3, 13, 9, 0, 1},
		{'Y', 3, 13, 9, 0, 1},
		{'Z', 3, 13, 9, 0, 1},

		{'\0'},
		{'1', 1, 26, 9, 0, 1},
		{'2', 3, 26, 9, 0, 1},
		{'3', 3, 26, 9, 0, 1},
		{'4', 3, 26, 9, 0, 1},
		{'5', 3, 26, 9, 0, 1},
		{'6', 3, 26, 9, 0, 1},
		{'7', 3, 26, 9, 0, 1},
		{'8', 3, 26, 9, 0, 1},
		{'9', 3, 26, 9, 0, 1},
		{'0', 3, 26, 9, 0, 1},

		{'\0'},
		{' ', 1, 39, 9, 0, 1},
		{'.', 3, 39, 9, 0, 1},
		{',', 3, 39, 9, 0, 1},
		{'\'', 3, 39, 9, 0, 1},
		{'"', 3, 39, 9, 0, 1}

};
int lnotice = sizeof(gnotice) / sizeof(gnotice[0]);
const Font ap::noticefont("notice font", 12, 11, false, gnotice, lnotice, textures::noticefont);

glyph gmonospace1[] = {
		{'\0'},
		{' ', 0, 0, 7, 0, 0},
		{'a', 0, 0, 7, 0, 0},
		{'b', 0, 0, 7, 0, 0},
		{'c', 0, 0, 7, 0, 0},
		{'d', 0, 0, 7, 0, 0},
		{'e', 0, 0, 7, 0, 0},
		{'f', 0, 0, 7, 0, 0},
		{'g', 0, 0, 7, 0, 0},
		{'h', 0, 0, 7, 0, 0},
		{'i', 0, 0, 7, 0, 0},
		{'j', 0, 0, 7, 0, 0},
		{'k', 0, 0, 7, 0, 0},
		{'l', 0, 0, 7, 0, 0},
		{'m', 0, 0, 7, 0, 0},
		{'n', 0, 0, 7, 0, 0},
		{'o', 0, 0, 7, 0, 0},
		{'p', 0, 0, 7, 0, 0},
		{'q', 0, 0, 7, 0, 0},
		{'r', 0, 0, 7, 0, 0},
		{'s', 0, 0, 7, 0, 0},
		{'t', 0, 0, 7, 0, 0},
		{'u', 0, 0, 7, 0, 0},
		{'v', 0, 0, 7, 0, 0},
		{'w', 0, 0, 7, 0, 0},
		{'x', 0, 0, 7, 0, 0},
		{'y', 0, 0, 7, 0, 0},
		{'z', 0, 0, 7, 0, 0},
		
		{'\0'},
		{'A', 0, 0+12, 7, 0, 0},
		{'B', 0, 0+12, 7, 0, 0},
		{'C', 0, 0+12, 7, 0, 0},
		{'D', 0, 0+12, 7, 0, 0},
		{'E', 0, 0+12, 7, 0, 0},
		{'F', 0, 0+12, 7, 0, 0},
		{'G', 0, 0+12, 7, 0, 0},
		{'H', 0, 0+12, 7, 0, 0},
		{'I', 0, 0+12, 7, 0, 0},
		{'J', 0, 0+12, 7, 0, 0},
		{'K', 0, 0+12, 7, 0, 0},
		{'L', 0, 0+12, 7, 0, 0},
		{'M', 0, 0+12, 7, 0, 0},
		{'N', 0, 0+12, 7, 0, 0},
		{'O', 0, 0+12, 7, 0, 0},
		{'P', 0, 0+12, 7, 0, 0},
		{'Q', 0, 0+12, 7, 0, 0},
		{'R', 0, 0+12, 7, 0, 0},
		{'S', 0, 0+12, 7, 0, 0},
		{'T', 0, 0+12, 7, 0, 0},
		{'U', 0, 0+12, 7, 0, 0},
		{'V', 0, 0+12, 7, 0, 0},
		{'W', 0, 0+12, 7, 0, 0},
		{'X', 0, 0+12, 7, 0, 0},
		{'Y', 0, 0+12, 7, 0, 0},
		{'Z', 0, 0+12, 7, 0, 0},
		
		{'\0'},
		{'0', 0, 0+36, 7, 0, 0},
		{'1', 0, 0+36, 7, 0, 0},
		{'2', 0, 0+36, 7, 0, 0},
		{'3', 0, 0+36, 7, 0, 0},
		{'4', 0, 0+36, 7, 0, 0},
		{'5', 0, 0+36, 7, 0, 0},
		{'6', 0, 0+36, 7, 0, 0},
		{'7', 0, 0+36, 7, 0, 0},
		{'8', 0, 0+36, 7, 0, 0},
		{'9', 0, 0+36, 7, 0, 0},
		
		{'\0'},
		{'.', 0, 0+24, 7, 0, 0},
		{',', 0, 0+24, 7, 0, 0},
		{'?', 0, 0+24, 7, 0, 0},
		{'!', 0, 0+24, 7, 0, 0},
		{'\'', 0, 0+24, 7, 0, 0},
		{'"', 0, 0+24, 7, 0, 0},
		{':', 0, 0+24, 7, 0, 0},
		{';', 0, 0+24, 7, 0, 0},
		{'-', 0, 0+24, 7, 0, 0},
		{'=', 0, 0+24, 7, 0, 0},
		{'(', 0, 0+24, 7, 0, 0},
		{')', 0, 0+24, 7, 0, 0},
		{'/', 0, 0+24, 7, 0, 0},
		{'\\', 0, 0+24, 7, 0, 0}
		
};
int lmonospace1 = sizeof(gmonospace1) / sizeof(gmonospace1[0]);
const Font ap::monospace1("monospace1", 14, 9, false, gmonospace1, lmonospace1, textures::monospace1);

glyph gmonospace2[] = {
		{'\0'},
		{' ', 0, 0, 6, 0, 0},
		{'a', 2, 0, 6, 0, 0},
		{'b', 2, 0, 6, 0, 0},
		{'c', 2, 0, 6, 0, 0},
		{'d', 2, 0, 6, 0, 0},
		{'e', 2, 0, 6, 0, 0},
		{'f', 2, 0, 6, 0, 0},
		{'g', 2, 0, 6, 0, 0},
		{'h', 2, 0, 6, 0, 0},
		{'i', 2, 0, 6, 0, 0},
		{'j', 2, 0, 6, 0, 0},
		{'k', 2, 0, 6, 0, 0},
		{'l', 2, 0, 6, 0, 0},
		{'m', 2, 0, 6, 0, 0},
		{'n', 2, 0, 6, 0, 0},
		{'o', 2, 0, 6, 0, 0},
		{'p', 2, 0, 6, 0, 0},
		{'q', 2, 0, 6, 0, 0},
		{'r', 2, 0, 6, 0, 0},
		{'s', 2, 0, 6, 0, 0},
		{'t', 2, 0, 6, 0, 0},
		{'u', 2, 0, 6, 0, 0},
		{'v', 2, 0, 6, 0, 0},
		{'w', 2, 0, 6, 0, 0},
		{'x', 2, 0, 6, 0, 0},
		{'y', 2, 0, 6, 0, 0},
		{'z', 2, 0, 6, 0, 0},
		
		{'\0'},
		{'A', 0, 0+12, 6, 0, 0},
		{'B', 2, 0+12, 6, 0, 0},
		{'C', 2, 0+12, 6, 0, 0},
		{'D', 2, 0+12, 6, 0, 0},
		{'E', 2, 0+12, 6, 0, 0},
		{'F', 2, 0+12, 6, 0, 0},
		{'G', 2, 0+12, 6, 0, 0},
		{'H', 2, 0+12, 6, 0, 0},
		{'I', 2, 0+12, 6, 0, 0},
		{'J', 2, 0+12, 6, 0, 0},
		{'K', 2, 0+12, 6, 0, 0},
		{'L', 2, 0+12, 6, 0, 0},
		{'M', 2, 0+12, 6, 0, 0},
		{'N', 2, 0+12, 6, 0, 0},
		{'O', 2, 0+12, 6, 0, 0},
		{'P', 2, 0+12, 6, 0, 0},
		{'Q', 2, 0+12, 6, 0, 0},
		{'R', 2, 0+12, 6, 0, 0},
		{'S', 2, 0+12, 6, 0, 0},
		{'T', 2, 0+12, 6, 0, 0},
		{'U', 2, 0+12, 6, 0, 0},
		{'V', 2, 0+12, 6, 0, 0},
		{'W', 2, 0+12, 6, 0, 0},
		{'X', 2, 0+12, 6, 0, 0},
		{'Y', 2, 0+12, 6, 0, 0},
		{'Z', 2, 0+12, 6, 0, 0},
		
		{'\0'},
		{'.', 0, 0+24, 6, 0, 0},
		{',', 2, 0+24, 6, 0, 0},
		{'?', 2, 0+24, 6, 0, 0},
		{'!', 2, 0+24, 6, 0, 0},
		{'\'', 2, 0+24, 6, 0, 0},
		{'"', 2, 0+24, 6, 0, 0},
		{':', 2, 0+24, 6, 0, 0},
		{';', 2, 0+24, 6, 0, 0},
		{'-', 2, 0+24, 6, 0, 0},
		{'=', 2, 0+24, 6, 0, 0},
		{'(', 2, 0+24, 6, 0, 0},
		{')', 2, 0+24, 6, 0, 0},
		{'/', 2, 0+24, 6, 0, 0},
		{'\\', 2, 0+24, 6, 0, 0},
		
		{'\0'},
		{'0', 0, 0+36, 6, 0, 0},
		{'1', 2, 0+36, 6, 0, 0},
		{'2', 2, 0+36, 6, 0, 0},
		{'3', 2, 0+36, 6, 0, 0},
		{'4', 2, 0+36, 6, 0, 0},
		{'5', 2, 0+36, 6, 0, 0},
		{'6', 2, 0+36, 6, 0, 0},
		{'7', 2, 0+36, 6, 0, 0},
		{'8', 2, 0+36, 6, 0, 0},
		{'9', 2, 0+36, 6, 0, 0}
};
int lmonospace2 = sizeof(gmonospace2) / sizeof(gmonospace2[0]);
const Font ap::monospace2("monospace2", 12, 9, false, gmonospace2, lmonospace2, textures::monospace2);

glyph gcli[] = {
		{'\0'},
		{'a', 0, 0, 11, 2, 2},
		{'b', 1, 0, 11, 2, 2},
		{'c', 1, 0, 11, 2, 2},
		{'d', 1, 0, 11, 2, 2},
		{'e', 1, 0, 11, 2, 2},
		{'f', 1, 0, 11, 2, 2},
		{'g', 1, 0, 11, 2, 2},
		{'h', 1, 0, 11, 2, 2},
		{'i', 1, 0, 11, 2, 2},
		{'j', 1, 0, 11, 2, 2},
		{'k', 1, 0, 11, 2, 2},
		{'l', 1, 0, 11, 2, 2},
		{'m', 1, 0, 11, 2, 2},
		{'n', 1, 0, 11, 2, 2},
		{'o', 1, 0, 11, 2, 2},
		{'p', 1, 0, 11, 2, 2},
		{'q', 1, 0, 11, 2, 2},
		{'r', 1, 0, 11, 2, 2},
		{'s', 1, 0, 11, 2, 2},
		{'t', 1, 0, 11, 2, 2},
		{'u', 1, 0, 11, 2, 2},
		{'v', 1, 0, 11, 2, 2},
		{'w', 1, 0, 11, 2, 2},
		{'x', 1, 0, 11, 2, 2},
		{'y', 1, 0, 11, 2, 2},
		{'z', 1, 0, 11, 2, 2},

		{'\0'},
		{'A', 0, 16, 11, 2, 2},
		{'B', 1, 16, 11, 2, 2},
		{'C', 1, 16, 11, 2, 2},
		{'D', 1, 16, 11, 2, 2},
		{'E', 1, 16, 11, 2, 2},
		{'F', 1, 16, 11, 2, 2},
		{'G', 1, 16, 11, 2, 2},
		{'H', 1, 16, 11, 2, 2},
		{'I', 1, 16, 11, 2, 2},
		{'J', 1, 16, 11, 2, 2},
		{'K', 1, 16, 11, 2, 2},
		{'L', 1, 16, 11, 2, 2},
		{'M', 1, 16, 11, 2, 2},
		{'N', 1, 16, 11, 2, 2},
		{'O', 1, 16, 11, 2, 2},
		{'P', 1, 16, 11, 2, 2},
		{'Q', 1, 16, 11, 2, 2},
		{'R', 1, 16, 11, 2, 2},
		{'S', 1, 16, 11, 2, 2},
		{'T', 1, 16, 11, 2, 2},
		{'U', 1, 16, 11, 2, 2},
		{'V', 1, 16, 11, 2, 2},
		{'W', 1, 16, 11, 2, 2},
		{'X', 1, 16, 11, 2, 2},
		{'Y', 1, 16, 11, 2, 2},
		{'Z', 1, 16, 11, 2, 2},

		{'\0'},
		{'1', 0, 38, 11, 2, 2},
		{'2', 1, 38, 11, 2, 2},
		{'3', 1, 38, 11, 2, 2},
		{'4', 1, 38, 11, 2, 2},
		{'5', 1, 38, 11, 2, 2},
		{'6', 1, 38, 11, 2, 2},
		{'7', 1, 38, 11, 2, 2},
		{'8', 1, 38, 11, 2, 2},
		{'9', 1, 38, 11, 2, 2},
		{'0', 1, 38, 11, 2, 2},

		{'\0'},
		{' ', 0, 57, 11, 2, 2},
		{'.', 1, 57, 11, 2, 2},
		{',', 1, 57, 11, 2, 2},
		{'/', 1, 57, 11, 2, 2},
		{'\\', 1, 57, 11, 2, 2},
		{'\'', 1, 57, 11, 2, 2},
		{'"', 1, 57, 11, 2, 2}


};
int lcli = sizeof(gcli) / sizeof(gcli[0]);
const Font ap::clifont("CLI", 15, 7, false, gcli, lcli, textures::clifont);


void ap::bulk() {
	
}