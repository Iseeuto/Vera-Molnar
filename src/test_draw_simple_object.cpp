#include<iostream>
#include "utils/structures.hpp"
#include "utils/svg.hpp"
#include "utils/simple_object.hpp"

using namespace std;

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
    copy_simple_object(F2, &F3);
    F3.p[0] = {4, 5};
    afficher_forme(F3);

    return 1;
}
