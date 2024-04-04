#include<iostream>
#include  "structures.hpp"

using namespace std;

#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

enum Arguments {MIN, MAX, x, y};

int getCoordSimpleObject(Forme F, Arguments coord, Arguments m);

int getCoordComplexObject(FormeComplexe FC, Arguments coord, Arguments m);

Point findCenterSimpleObject(Forme F);

Point findCenterComplexObject(FormeComplexe FC);

#endif