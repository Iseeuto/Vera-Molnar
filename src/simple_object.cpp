#include<iostream>
#include "utils/structures.hpp"
#include "utils/svg.hpp"
#include "utils/simple_object.hpp"

using namespace std;

void init_circle(Forme *C, Point centre, int rayon, string color){
    C->p = new Point[1];
    C->p[0] = centre;
    C->Nb_Pts = 1;
    C->rayon = rayon;
    C->color = color;
    C->type = Cercle;
}

void init_polygon(Forme *P, int nbPoints, Point *tabPoints, string color){
    P->p = tabPoints;
    P->Nb_Pts = nbPoints;
    P->color = color;
    P->type = Polygone;
}

Forme init_object(Figure type, int nbPoints, Point *tabPoints, string color, int rayon){
    Forme F;
    if(type == Cercle){ init_circle(&F, tabPoints[0], rayon, color); }
    else if (type == Polygone){ init_polygon(&F, nbPoints, tabPoints, color); }
    return F;
}

void afficher_forme(Forme F){
    if(F.type == Cercle){
        cout << "Cercle" << endl;
        cout << "Centre: (" << F.p[0].x << ',' << F.p[0].y << ')' << endl;
        cout << "Rayon: " << F.rayon << endl;
    }
    else if (F.type = Polygone)
    {
        cout << "Polygone" << endl;
        cout << "Nombre de points: " << F.Nb_Pts << endl;
        for(int i=0; i<F.Nb_Pts; i++){
            cout << "Point n" << i+1 << ": (" << F.p[i].x << ',' << F.p[i].y << ')' << endl;
        } 
    }

    cout << "Couleur: " << F.color << endl;
}

string simpleObject_to_svg(Forme F){
    if(F.type == Cercle){ return circle_to_svg(F.p[0], F.rayon, F.color); }
    else if(F.type == Polygone){ return polygon_to_svg(F.Nb_Pts, F.p, F.color); }
    return "";
}

void copy_simple_object(Forme F, Forme* copie){
    copie->type = F.type;
    copie->color = F.color;
    copie->Nb_Pts = F.Nb_Pts;
    copie->rayon = F.rayon;
    copie->p = new Point[copie->Nb_Pts];

    for(int i=0; i<copie->Nb_Pts; i++){ 
        (copie->p)[i] = {F.p[i].x, F.p[i].y}; 
    }
}