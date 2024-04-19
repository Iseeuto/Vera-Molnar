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
    C1.Rep_col = 10; C1.Rep_lig = 10;

    C1.FC = file_to_composedObject("tab1.txt");
    listTransformComposed LTC1 = file_to_transform("transfo1.txt");

    svg_to_html("tab1.html", canvas_to_svg_veramolnar(C1, LTC1));

    return 1;
}