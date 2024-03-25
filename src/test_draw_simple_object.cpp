#include<iostream>
#include "utils/structures.hpp"
#include "utils/test_svg.hpp"

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

Forme init_object(Figure type, int nbPoints, Point *tabPoints, string color, int rayon=0){
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

void copySimpleObject(Forme F, Forme* copie){
    copie->type = F.type;
    copie->color = F.color;
    copie->Nb_Pts = F.Nb_Pts;
    copie->rayon = F.rayon;
    copie->p = new Point[copie->Nb_Pts];

    for(int i=0; i<copie->Nb_Pts; i++){ 
        (copie->p)[i] = {F.p[i].x, F.p[i].y}; 
    }
}

/*
int main(){

    Point* tab1 = new Point[1];
    tab1[0] = {1, 1};
    Forme F1 = init_object(Cercle, 1, tab1, "red", 5);
    afficher_forme(F1); cout << endl;

    Point* tab2 = new Point[4];
    tab2[0] = {1, 1}; tab2[1] = {2, 1}; tab2[2] = {2, 2}; tab2[3] = {1, 2};
    Forme F2 = init_object(Polygone, 4, tab2, "green");
    afficher_forme(F2); cout << endl;

    Forme F3;
    copySimpleObject(F2, &F3);
    F3.p[0] = {4, 5};
    afficher_forme(F3);

    return 1;
}
*/