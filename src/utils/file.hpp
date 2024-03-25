#include<iostream>
#include "structures.hpp"

using std::string;

#ifndef FILE_HPP
#define FILE_HPP

void saveFigure(Forme F, string nomFichier);

string* parseArguments(string s, int* nbArg, char separator = ' ');

Forme loadFigure(string nomFichier);

#endif