#include<iostream>

using std::string;

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

enum Figure { Cercle, Polygone };

struct Point{
    float x;
    float y;
};

struct Forme{
    Figure type;
    string nom;
    Point *p;
    int Nb_Pts = 1; 
    string color;
    float rayon;
};

struct FormeComplexe{
    Forme* formes;
    int nbFormes;
};

struct Canvas{
    int width, height;
    FormeComplexe FC;
    int Rep_col, Rep_lig;
};

#endif