#include<iostream>
#include "structures.hpp"

using std::string;

#ifndef FILE_HPP
#define FILE_HPP

void object_to_file(Forme F, string nomFichier);

string* parseArguments(string s, int* nbArg, char separator);

Forme file_to_object(string nomFichier);

FormeComplexe files_to_composedObject(string* files, int N);

#endif