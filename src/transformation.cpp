#include<iostream>
#include "utils/transformation.hpp"
#include <cmath>
#include <climits>

using namespace std;


// TODO : Optimiser
int getCoordSimpleObject(Forme F, Arguments coord, Arguments m){
    int _coord = (m==MIN) ? INT_MAX : INT_MIN;

    for(int i=0; i<F.Nb_Pts; i++){
        if(F.type == Polygone){
            if(coord == x){
            if(m == MIN){ _coord = (F.p[i].x < _coord) ? F.p[i].x : _coord; }
            else{ _coord = (F.p[i].x > _coord) ? F.p[i].x : _coord; }
            }
            else{
                if(m == MIN){ _coord = (F.p[i].y < _coord) ? F.p[i].y : _coord; }
                else{ _coord = (F.p[i].y > _coord) ? F.p[i].y : _coord; }
            }
        }
        else{
            if(coord == x){
            if(m == MIN){ _coord = (F.p[i].x-F.rayon < _coord) ? F.p[i].x-F.rayon : _coord; }
            else{ _coord = (F.p[i].x+F.rayon > _coord) ? F.p[i].x+F.rayon : _coord; }
            }
            else{
                if(m == MIN){ _coord = (F.p[i].y-F.rayon < _coord) ? F.p[i].y-F.rayon : _coord; }
                else{ _coord = (F.p[i].y+F.rayon > _coord) ? F.p[i].y+F.rayon : _coord; }
            }
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

float deg_to_rad(float n){
    float N;
    N = n * (M_PI/180) ;
    return N;
}

void rotate_object(Forme *F,float angle,Point centre){
    int degRad = deg_to_rad(angle);
    if(F->type = Polygone){
        for(int i=0; i<F->Nb_Pts;i++){
            Point p = F->p[i];
            Point newPt;
            newPt.x = (p.x - centre.x) * cos((degRad)) + (p.y - centre.y) * sin(degRad) + centre.x;
            newPt.y = (p.x - centre.x) * (-sin(degRad)) + (p.y - centre.y) * cos(degRad) + centre.y;
            F->p[i] = newPt ;
        }   
    }
}

void dilate_object(Forme *f,int k){
    
    if(f->type == Cercle){
        f->rayon = f->rayon * k;
    }
    if(f->type == Polygone){
        Point centre = findCenterSimpleObject(*f);
        for(int i = 0;i<f->Nb_Pts;i++){
            f->p[i].x = centre.x + k * (f->p[i].x - centre.x);
            f->p[i].y = centre.y + k * (f->p[i].y - centre.y);
        }
    }
}

void dilate_ComposedObject(FormeComplexe *FC, int k){
    Point centre ;
    for(int i=0; i<FC->nbFormes;i++){
        if(FC->formes[i].type == Cercle){
            FC->formes[i].rayon = FC->formes[i].rayon * k;}
        if(FC->formes[i].type == Polygone){
            for(int j = 0;j<FC->formes[i].Nb_Pts;j++){
                FC->formes[i].p[j].x = centre.x + k * (FC->formes[i].p[j].x - centre.x);
                FC->formes[i].p[j].y = centre.y + k * (FC->formes[i].p[j].y - centre.y);
        }
    }
}
}

void colorChange_object(Forme *f,string color){
    f->color = color;
}

void colorChange_ComposedObject(FormeComplexe *FC, string color){
    for(int i=0;i<FC->nbFormes;i++){
        FC->formes[i].color = color;
    }
}