#include<iostream>
#include<fstream>
#include<sstream>
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
    // On rajoute un séparateur à la fin de la chaine pour avoir autant d'espaces que d'arguments
    s += separator;
    // On compte le nombre d'arguments sur la ligne (nb séparateur)
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

Forme args_to_object(string* args, int N){
    Forme F;
    int _n;
    if(args[0] == "Cercle"){
        F.type = Cercle;
        F.Nb_Pts = 1;
        F.p = new Point[1];
        F.color = args[N-1];
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
        F.color = args[N-1];
    }

    delete[] args;

    return F;
}

Forme file_to_object(string nomFichier){

    ifstream Fichier(nomFichier);
    string line; getline(Fichier, line);

    int nbArg;
    string* args = parseArguments(line, &nbArg, ' ');

    return args_to_object(args, nbArg);
};

FormeComplexe files_to_composedObject(string* files, int N){
    struct FormeComplexe FC = {new Forme[N], N};

    for(int i=0; i<N; i++){
        FC.formes[i] = file_to_object(files[i]);
    }
    return FC;
}

FormeComplexe file_to_composedObject(string file){
    FormeComplexe FC;
    int N;

    ifstream Fichier(file);
    std::stringstream ss;
    ss << Fichier.rdbuf();

    string* formes = parseArguments(ss.str(), &N, '\n');
    FC.nbFormes = N;
    FC.formes = new Forme[N];

    for(int i=0; i<N; i++){
        int nbArg;
        string* args = parseArguments(formes[i], &nbArg, ' ');
        FC.formes[i] = args_to_object(args, nbArg);
    }

    return FC;
}

void composedObject_to_file(FormeComplexe FC, string file){
    ofstream Fichier(file);

    for(int i=0; i<FC.nbFormes; i++){
        Forme f = FC.formes[i];

        if(f.type == Cercle){
            Fichier << "Cercle ";
            Fichier << to_string(f.p[0].x) << '.' << to_string(f.p[0].y) << ' ';
            Fichier << to_string(f.rayon) << ' ';
        }
        else if(f.type == Polygone){
            Fichier << "Polygone ";
            Fichier << to_string(f.Nb_Pts) << ' ';
            for(int i=0; i<f.Nb_Pts; i++){
                Fichier << to_string(f.p[i].x) << '.' << to_string(f.p[i].y) << ' ';
            }
        }
        Fichier << f.color;
        if(i+1 < FC.nbFormes){ Fichier << '\n'; }
    }
}