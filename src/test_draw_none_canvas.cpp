#include<iostream>
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "fstream"
#include "utils/test_draw_simple_object.hpp"
#include "utils/test_svg.hpp"
#include "utils/transformation.hpp"

using namespace std;

int main(){
    Canvas C;
    C.FC = file_to_composedObject("test.txt");
    C.height = 8000; C.width = 800;
    C.Rep_col = 1; C.Rep_lig = 100;

    ofstream Fichier("test.html");
    Fichier << "<!DOCTYPE html>" << endl;
    Fichier << "<html>" << endl;
    Fichier << "<body>" << endl;
    Fichier << canvas_transform_composed_to_svg(C);
    Fichier << "</body>" << endl;
    Fichier << "</html>" << endl;

    
    return 1;
}