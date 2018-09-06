#ifndef _240_04HW_MAIN_H
#define _240_04HW_MAIN_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;
using std::endl;
using std::to_string;

#include "point2d.h"
using csce240::Point2d;
#include "vector2d.h"
using csce240::Vector2d;
#include "polygon.h"
using csce240::Polygon;

bool ExtractDouble(const char* cstr_dbl, double &d, bool verbose = false);

#endif
