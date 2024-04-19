#include<iostream>
#include"utils/svg.hpp"
#include"utils/file.hpp"

using namespace std;

int main(int argc, char* argv[]){

    if(argc < 2){ cout << "Arguments manquants"; return 0; }

    Forme f = file_to_object(argv[1]);
    
    canvas_to_file(800, 800, &f, 1, "test.html");

    return 1;
}