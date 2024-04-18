#include<iostream>
#include  "structures.hpp"

using namespace std;

#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

enum Arguments {MIN, MAX, x, y};

enum Transformations {Dilate, Rotate, ChangeColor};

struct transform{
    float angle = 0;
    float size = 1;
    string color;
};

struct listTransform{
    transform t;
    listTransform* next = nullptr;
};

struct listTransformComposed{
    listTransform *l;
    int N;
};

float getCoordSimpleObject(Forme F, Arguments coord, Arguments m);

float getCoordComplexObject(FormeComplexe FC, Arguments coord, Arguments m);

Point findCenterSimpleObject(Forme F);

Point findCenterComplexObject(FormeComplexe FC);

void rotate_object(Forme *F,float angle,Point centre);

void rotate_objectComplexe(FormeComplexe *FC, float angle);

float deg_to_rad(float n);

void colorChange_ComposedObject(FormeComplexe *FC, string color);

void colorChange_object(Forme *f,string color);

void dilate_ComposedObject(FormeComplexe *FC, float k);

void dilate_object(Forme *f,float k,Point centre);

void transform_simple_object(Forme *f, transform t, Point center);

#endif