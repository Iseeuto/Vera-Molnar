#include<iostream>
#include "utils/canvas.hpp"
#include "utils/file.hpp"
#include "fstream"

using namespace std;

int main(){

    Canvas C;
    C.width = 800; C.height = 800;
    C.Rep_col = 10; C.Rep_lig = 10;

    C.FC = file_to_composedObject("test.txt");

    ofstream Fichier("test.html");
    Fichier << "<!DOCTYPE html><html><body>";
    Fichier << canvas_composed_to_svg(C);
    Fichier << "</body></html>";

    return 1;
}