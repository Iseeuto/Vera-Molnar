#include<iostream>
#include "utils/structures.hpp"
#include "utils/complex_object.hpp"
#include "utils/simple_object.hpp"

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