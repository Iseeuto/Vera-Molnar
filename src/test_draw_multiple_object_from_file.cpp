#include<iostream>
#include "utils/structures.hpp"
#include "utils/test_svg.hpp"
#include "utils/file.hpp"

using namespace std;

/*
int main(int argc, char* argv[]){

    int N = argc-1;
    if(N < 1){ cout << "Arguments manquants"; return 0; }

    string* files = new string[N];

    for(int i=0; i<N; i++){ files[i] = argv[i+1]; }

    FormeComplexe FC = files_to_composedObject(files, N);

    canvas_to_file_complex(800, 800, &FC, N, "test.html");

    return 1;
}
*/