#include<iostream>
#include"utils/structures.hpp"
#include"utils/canvas.hpp"
#include"utils/svg.hpp"
#include"utils/file.hpp"
#include<fstream>

using namespace std;

int main(){

    Canvas C1,C2,C3,C4,C5;

    // Premier tableau

    C1.width = 1000; C1.height = 1000;
    C1.Rep_col = 9; C1.Rep_lig = 10;

    C1.FC = file_to_composedObject("tab1.txt");
    listTransformComposed LTC1 = file_to_transform("transfo1.txt");

    svg_to_html("tab1.html", canvas_to_svg_veramolnar_good(C1, LTC1));

    // Deuxième tableau

    C2.width = 1000; C2.height = 1000;
    C2.Rep_col = 9; C2.Rep_lig = 9;

    C2.FC = file_to_composedObject("tab2.txt");
    listTransformComposed LTC2 = file_to_transform("transfo2.txt");
    //cout << "hello" << endl;

    svg_to_html("tab2.html", canvas_to_svg_veramolnar_good(C2, LTC2));

    // Troisième tableau

    C3.width = 1000; C3.height = 1000;
    C3.Rep_col = 10; C3.Rep_lig = 10;

    C3.FC = file_to_composedObject("tab3.txt");
    listTransformComposed LTC3 = file_to_transform("transfo3.txt");

    svg_to_html("tab3.html", canvas_to_svg_veramolnar_good(C3, LTC3));

    // Quatrième tableau

    C4.width = 1000; C4.height = 1000;
    C4.Rep_col = 10; C4.Rep_lig = 10;

    C4.FC = file_to_composedObject("tab4.txt");
    listTransformComposed LTC4 = file_to_transform("transfo4.txt");

    svg_to_html("tab4.html", canvas_to_svg_veramolnar_good(C4, LTC4));

    // Cinquième tableau

    C5.width = 1000; C5.height = 1000;
    C5.Rep_col = 10; C5.Rep_lig = 10;

    C5.FC = file_to_composedObject("tab5.txt");
    listTransformComposed LTC5 = file_to_transform("transfo5.txt");

    svg_to_html("tab5.html", canvas_to_svg_veramolnar_good(C5, LTC5));

    return 1;
}