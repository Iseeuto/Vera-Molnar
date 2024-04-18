#include<iostream>
#include "structures.hpp"
#include "transformation.hpp"

using std::string;

#ifndef FILE_HPP
#define FILE_HPP

void object_to_file(Forme F, string nomFichier);

string* parseArguments(string s, int* nbArg, char separator);

Forme args_to_object(string* args, int N);

Forme file_to_object(string nomFichier);

FormeComplexe files_to_composedObject(string* files, int N);

FormeComplexe file_to_composedObject(string file);

void composedObject_to_file(FormeComplexe FC, string file);

listTransformComposed file_to_transform(string file);

#endif