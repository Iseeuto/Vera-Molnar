#include<iostream>

using std::string;

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

enum Figure { Cercle, Polygone };

struct Point{
    int x;
    int y;
};

struct Forme{
    Figure type;
    string nom;
    Point *p;
    int Nb_Pts; 
    string color;
    int rayon;
};

#endif