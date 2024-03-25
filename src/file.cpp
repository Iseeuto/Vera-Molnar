#include<iostream>
#include<fstream>
#include "utils/file.hpp"
#include "utils/structures.hpp"
#include "utils/test_draw_simple_object.hpp"

using namespace std;

void saveFigure(Forme F, string nomFichier){
    ofstream Fichier(nomFichier);
    if(F.type == Cercle){
        Fichier << "Cercle " << F.p[0].x << '.' << F.p[0].y << ' ' << F.rayon << ' ' << F.color;
    }
    else if(F.type == Polygone){
        Fichier << "Polygone " << F.Nb_Pts << ' ';
        for(int i=0; i<F.Nb_Pts; i++){
            Fichier << F.p[i].x << '.' << F.p[i].y << ' ';
        }
        Fichier << F.color;
    }
};

string* parseArguments(string s, int* nbArg, char separator = ' '){
    // On rajoute un espace à la fin de la chaine pour avoir autant d'espaces que d'arguments
    s += ' ';
    // On compte le nombre d'arguments sur la ligne (nb espaces)
    int count=0; for(int i=0; i<s.size(); i++){ count = (s[i] == ' ') ? count+1 : count; }

    *nbArg = count;
    string* args = new string[*nbArg];

    int lastspace=0;

    for(int i=0; i<count; i++){
        int idx = 0;
        while((s[lastspace+idx] != ' ')){
            args[i] += s[lastspace+idx];
            idx++;
        }
        lastspace = lastspace+idx+1;
    }

    return args;
} 

Forme loadFigure(string nomFichier){
    Forme F;

    ifstream Fichier(nomFichier);
    string line; Fichier >> line;

    return F;
};

int main(){

    // Point* tab2 = new Point[4];
    // tab2[0] = {1, 1}; tab2[1] = {2, 1}; tab2[2] = {2, 2}; tab2[3] = {1, 2};
    // Forme F2 = init_object(Polygone, 4, tab2, "green");
    // saveFigure(F2, "F2.txt");

    int nbArg;
    string* args = parseArguments("Circle 2.3 4 red", &nbArg);
    for(int i=0; i<nbArg; i++){ cout << args[i] << ' '; }

    return 1;
}