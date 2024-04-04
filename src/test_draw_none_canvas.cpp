#include<iostream>
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "fstream"
#include "utils/test_draw_simple_object.hpp"
#include "utils/test_svg.hpp"

using namespace std;

int main(){

/*
    Canvas C;
    C.width = 800; C.height = 800;
    C.Rep_col = 10; C.Rep_lig = 10;

    C.FC = file_to_composedObject("test.txt");

    ofstream Fichier("test.html");
    Fichier << "<!DOCTYPE html><html><body>";
    Fichier << canvas_composed_to_svg(C);
    Fichier << "</body></html>";

    return 1;
    */
    
    Forme f = file_to_object("rectangle.txt");
    afficher_forme(f);
    
    Forme F ;
    copy_simple_object(f,&F);
    Point centre;
    centre.x = 50;
    centre.y = 50;
    rotate_object(&F, 90, centre);
    canvas_to_file(800, 800, &F, 1, "test.html");
    canvas_to_file(800, 800, &f, 1, "test2.html");
    
    afficher_forme(F);
    cout << endl << deg_to_rad(90) << endl ;
    return 1;
}