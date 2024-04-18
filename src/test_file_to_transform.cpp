#include<iostream>
#include "utils/file.hpp"

using namespace std;

int main(){

    listTransformComposed LTC = file_to_transform("transformation.txt");

    for(int i=0; i<LTC.N; i++){
        cout << i << ' ';
        listTransform *current = &(LTC.l[i]);
        while(current != nullptr){
            cout << current->t.angle << ' ' << current->t.size << ' ' << current->t.color << " | ";
            current = current->next;
        }
        cout << endl;
    }

    return 1;
}