#include<iostream>

using std::string;

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

struct Point{
    int x;
    int y;
};

struct Forme{
    string nom;
    Point *p;
    int Nb_Pts;
    string color;
    int rayon;
};

#endif