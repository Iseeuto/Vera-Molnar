#include<iostream>
#include "utils/svg.hpp"
#include "utils/structures.hpp"

using namespace std;


int main(int arg, char* argv[]){

    int width = stoi(argv[3]) ;int height = stoi(argv[2]); string NomFic = argv[1];
    int ex = stoi(argv[4]);
    
    Point c; c.x = 60 ; c.y = 50;
    Point p1; p1.x = 2;p1.y = 50;
    Point p2; p2.x = 10;p2.y = 10;
    Point P[3] = {c,p1,p2};

    Forme cercle;
    cercle.nom = "cercle"; cercle.color = "yellow"; cercle.rayon = 50; 
    cercle.p = new Point; cercle.Nb_Pts = 1;
    cercle.p[0] = c;

    Forme Poly ;
    Poly.nom = "polygone" ; Poly.color = "purple" ; Poly.p = new Point[3];
    Poly.Nb_Pts = 3;
    Poly.p[0] = c ; Poly.p[1] = p1 ; Poly.p[2] = p2 ;

    Forme *F = new Forme[2];
    F[0] = cercle ; F[1] = Poly;

    canvas_to_file_exemple(height,width,F,2,NomFic,ex);

    return 1;
}