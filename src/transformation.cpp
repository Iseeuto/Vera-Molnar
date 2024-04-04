#include<iostream>
#include "utils/transformation.hpp"

using namespace std;


// TODO : Optimiser
int getCoordSimpleObject(Forme F, Arguments coord, Arguments m){
    int _coord = (m==MIN) ? INT_MAX : INT_MIN;

    for(int i=0; i<F.Nb_Pts; i++){
        if(coord == x){
            if(m == MIN){ _coord = (F.p[i].x < _coord) ? F.p[i].x : _coord; }
            else{ _coord = (F.p[i].x > _coord) ? F.p[i].x : _coord; }
        }
        else{
            if(m == MIN){ _coord = (F.p[i].y < _coord) ? F.p[i].y : _coord; }
            else{ _coord = (F.p[i].y > _coord) ? F.p[i].y : _coord; }
        }
    }

    return _coord;
}

int getCoordComplexObject(FormeComplexe FC, Arguments coord, Arguments m){
    int _coord = (m == MIN) ? INT_MAX : INT_MIN;

    for(int i=0; i<FC.nbFormes; i++){
        int coord_forme = getCoordSimpleObject(FC.formes[i], coord, m); 

        if(m == MIN){ _coord = (coord_forme < _coord) ? coord_forme : _coord; }
        else{ _coord = (coord_forme > _coord) ? coord_forme : _coord; }
    }

    return _coord;

}

Point findCenterSimpleObject(Forme F){
    // On crée un carré qui englobe la structures (que trois points car on veut un axe gauche-droite et haut-bas)
    struct Point haut_gauche = {getCoordSimpleObject(F, x, MIN), getCoordSimpleObject(F, y, MIN)};
    struct Point haut_droite = {getCoordSimpleObject(F, x, MAX), getCoordSimpleObject(F, y, MIN)};
    struct Point bas_gauche = {getCoordSimpleObject(F, x, MIN), getCoordSimpleObject(F, y, MAX)};

    struct Point milieu = {
        haut_gauche.x + (haut_droite.x-haut_gauche.x)/2,
        haut_gauche.y + (bas_gauche.y-haut_gauche.y)/2
    };

    return milieu;
}

Point findCenterComplexObject(FormeComplexe FC){
    struct Point haut_gauche = {getCoordComplexObject(FC, x, MIN), getCoordComplexObject(FC, y, MIN)};
    struct Point haut_droite = {getCoordComplexObject(FC, x, MAX), getCoordComplexObject(FC, y, MIN)};
    struct Point bas_gauche = {getCoordComplexObject(FC, x, MIN), getCoordComplexObject(FC, y, MAX)};

    struct Point milieu = {
        haut_gauche.x + (haut_droite.x-haut_gauche.x)/2,
        haut_gauche.y + (bas_gauche.y-haut_gauche.y)/2
    };

    return milieu;
}