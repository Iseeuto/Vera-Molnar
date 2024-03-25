#include<iostream>
#include "utils/structures.hpp"
#include "utils/test_draw_complex_object.hpp"
#include "utils/test_draw_simple_object.hpp"

using namespace std;

FormeComplexe init_complex_object(int nbForme, Forme *tab){
    return {tab, nbForme};
}

void copy_complex_object(FormeComplexe FC, FormeComplexe* copie){
    copie->nbFormes = FC.nbFormes;
    copie->formes = new Forme[copie->nbFormes];
    for(int i=0; i<copie->nbFormes; i++){
        copy_simple_object(FC.formes[i], &(copie->formes[i]));
    }
}

void afficher_complex_object(FormeComplexe FC){
    for(int i=0; i<FC.nbFormes; i++){
        cout << "-----Forme " << i << "-----" << endl;
        afficher_forme(FC.formes[i]); cout << endl;
    }
}

int main(){
    Forme* tab = new Forme[2];
    Point* centre = new Point[1];
    centre[0] = {1, 5};
    Point* pol = new Point[3];
    pol[0] = {1,2}; pol[1] = {4,3}; pol[2] = {2, 2};

    Forme a = {Cercle, "", centre, 1, "red", 4};
    Forme b = {Polygone, "", pol, 3, "blue", 0};

    tab[0] = a; tab[1] = b;

    FormeComplexe FC = init_complex_object(2, tab);

    FormeComplexe FC2; 
    copy_complex_object(FC, &FC2);

    afficher_complex_object(FC2);

    return 1;
}