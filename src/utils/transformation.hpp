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

void rotate_object(Forme *F,float angle,Point centre);

float deg_to_rad(float n);

void colorChange_ComposedObject(FormeComplexe *FC, string color);

void colorChange_object(Forme *f,string color);

void dilate_ComposedObject(FormeComplexe *FC, int k);

void dilate_object(Forme *f,int k);


#endif