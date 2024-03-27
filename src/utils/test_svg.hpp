#include<iostream>
#include "structures.hpp"

using std::string;

#ifndef TEST_SVG_HPP
#define TEST_SVG_HPP

string circle_to_svg(Point centre, int rayon, string fill);

string polygon_to_svg(int N ,Point *p ,string fill);

string canvas_to_svg(int width, int height, Forme *f, int N);

string example2_to_svg(int width, int height, Forme *f, int N);

string example3_to_svg(int width, int height, Forme *f, int N);

string example1_to_svg(int width, int height, Forme *f, int N);

void canvas_to_file(int width, int height, Forme *f, int N,string nomFic);

void canvas_to_file_complex(int width, int height, FormeComplexe *FC, int N, string nomFic);

void canvas_to_file_exemple(int width, int height, Forme *f, int N,string nomFic,int ex);

#endif