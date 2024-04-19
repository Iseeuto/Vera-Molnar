#include<iostream>
#include<fstream>
#include "utils/structures.hpp"
#include "utils/svg.hpp"
using namespace std;

// void circle_to_svg(Point centre, float rayon,string fill ){
//     cout << "<circle cx=\"" << centre.x << "\" cy=\"" << centre.y <<"\" r=\""<< rayon <<"\" fill=\""<< fill << "\"/>" ;
//     cout << endl;
// }

string circle_to_svg(Point centre, int rayon,string fill ){
    string str;
    str = "<circle cx=\"" + to_string(centre.x) + "\" cy=\"" + to_string(centre.y) + "\" r=\"" + to_string(rayon) + "\" fill=\"" + fill + "\"/>" ;
    return str;
}



// void polygon_to_svg(int N ,Point *p ,string fill){
//     cout << "<polygon points=\"";
//     for(int i =0;i<N;i++){
//         cout << p[i].x << ',' << p[i].y << ' ';
//     }  
//     cout << "\" fill=\"" << fill << "\"/>";
//     }

string polygon_to_svg(int N ,Point *p ,string fill){
    string str;
    str = "<polygon points=\"";
    for(int i =0;i<N;i++){
        str += to_string(p[i].x) + ',' + to_string(p[i].y) + ' ';
    }  
    str += "\" fill=\"" + fill + "\"/>";
    return str;
    }


string canvas_to_svg(int width, int height, Forme *f, int N){
    
    string str = "<svg height=\"" + to_string(height) + "\" width=\"" + to_string(width) +  "\" xmlns=\"http://www.w3.org/2000/svg\">";
    for(int i=0;i<N;i++){
    if(f[i].type == Cercle){
        str += circle_to_svg(f[i].p[0],f[i].rayon,f[i].color);
    }
    else if(f[i].type == Polygone){
        str+=polygon_to_svg(f[i].Nb_Pts,f[i].p,f[i].color);
    }}

    str+= "</svg>";
    return str;
}

string example2_to_svg(int width, int height, Forme *f, int N){
    Forme *F_bis = new Forme[2];
    F_bis[1] = f[0];
    F_bis[0] = f[1];
    string str = canvas_to_svg(width,height,F_bis,N);
    return str;
}

string example3_to_svg(int width, int height, Forme *f, int N){
    string str = canvas_to_svg(width,height,f,N);
    return str;
}

string example1_to_svg(int width, int height, Forme *f, int N){
    for(int i=0;i<f[0].Nb_Pts;i++){
        f[0].p[i].x += 40 ;
        f[0].p[i].y += 40 ;
    }
    string str = canvas_to_svg(width,height,f,N);
    return str;
}

void svg_to_html(string file, string svg){
    ofstream Fichier(file);
    Fichier << "<!DOCTYPE html>" << endl;
    Fichier << "<html>" << endl;
    Fichier << "<body>" << endl;
    Fichier << svg;
    Fichier << "</body>" << endl;
    Fichier << "</html>" << endl;
}

void canvas_to_file(int width, int height, Forme *f, int N,string nomFic){
    ofstream Fichier(nomFic);
    Fichier << "<!DOCTYPE html>" << endl;
    Fichier << "<html>" << endl;
    Fichier << "<body>" << endl;
    Fichier << canvas_to_svg(width,height,f,N);
    Fichier << "</html>" << endl;
}

void canvas_to_file_complex(int width, int height, FormeComplexe *FC, int N, string nomFic){
    ofstream Fichier(nomFic);
    Fichier << "<!DOCTYPE html>" << endl;
    Fichier << "<html>" << endl;
    Fichier << "<body>" << endl;
    Fichier << "<svg>";
    for(int i=0; i<N; i++){
        Forme f = FC->formes[i];
        if(f.type == Cercle){ Fichier << circle_to_svg(f.p[0], f.rayon, f.color); }
        else if(f.type == Polygone) { Fichier << polygon_to_svg(f.Nb_Pts, f.p, f.color); }
    }
    Fichier << "</svg>" << endl;
    Fichier << "</body>" << endl;
    Fichier << "</html>" << endl;
}

void canvas_to_file_exemple(int width, int height, Forme *f, int N,string nomFic,int ex){
    ofstream Fichier(nomFic);
    Fichier << "<!DOCTYPE html>" << endl;
    Fichier << "<html>" << endl;
    Fichier << "<body>" << endl;
    if(ex == 1){
        Fichier << example1_to_svg(width,height,f,N);
    }
    if(ex == 2){
        Fichier << example2_to_svg(width,height,f,N);
    }
    if(ex == 3){
        Fichier << example3_to_svg(width,height,f,N);
    }
    Fichier << "</html>" << endl;
}

