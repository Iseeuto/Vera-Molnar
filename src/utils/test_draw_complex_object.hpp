#include<iostream>
#include "structures.hpp"
#include "test_draw_simple_object.hpp"

using std::string;

#ifndef T_D_COMPLEX_OBJECT_HPP
#define T_D_COMPLEX_OBJECT_HPP

FormeComplexe init_complex_object(int nbForme, Forme *tab);

void copy_complex_object(FormeComplexe FC, FormeComplexe* copie);

void afficher_complex_object(FormeComplexe FC);

#endif