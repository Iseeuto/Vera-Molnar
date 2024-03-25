#include<iostream>
#include<fstream>
#include "utils/file.hpp"
#include "utils/structures.hpp"
#include "utils/test_draw_simple_object.hpp"

using namespace std;

void object_to_file(Forme F, string nomFichier){
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

string* parseArguments(string s, int* nbArg, char separator){
    // On rajoute un espace à la fin de la chaine pour avoir autant d'espaces que d'arguments
    s += separator;
    // On compte le nombre d'arguments sur la ligne (nb espaces)
    int count=0; for(int i=0; i<s.size(); i++){ count = (s[i] == separator) ? count+1 : count; }

    *nbArg = count;
    string* args = new string[*nbArg];

    int lastspace=0;

    for(int i=0; i<count; i++){
        int idx = 0;
        while(s[lastspace+idx] != separator){
            args[i] += s[lastspace+idx];
            idx++;
        }
        lastspace = lastspace+idx+1;
    }

    return args;
} 

Forme file_to_object(string nomFichier){
    Forme F;

    ifstream Fichier(nomFichier);
    string line; getline(Fichier, line);

    int nbArg, _n;
    string* args = parseArguments(line, &nbArg, ' ');

    if(args[0] == "Cercle"){
        F.type = Cercle;
        F.Nb_Pts = 1;
        F.p = new Point[1];
        F.color = args[nbArg-1];
        F.rayon = stoi(args[2]);

        string* coord = parseArguments(args[1], &_n, '.');

        F.p[0] = {stoi(coord[0]), stoi(coord[1])};
        delete[] coord;
    }
    else if(args[0] == "Polygone"){
        F.type = Polygone;
        F.Nb_Pts = stoi(args[1]);
        F.p = new Point[F.Nb_Pts];
        for(int i=0; i<F.Nb_Pts; i++){
            string* coord = parseArguments(args[2+i], &_n, '.');
            F.p[i] = {stoi(coord[0]), stoi(coord[1])};
            delete[] coord;
        }
        F.color = args[nbArg-1];
    }

    delete[] args;

    return F;
};

// int main(){

//     Forme F = file_to_object("test.txt");
//     afficher_forme(F);

//     return 1;
// }