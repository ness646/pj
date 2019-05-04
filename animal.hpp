#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <cmath>
#include <iostream>
using namespace std;

#include "ensCoord.hpp"

const int FoodInit=5;
const int MaxFood=10;
const int FoodLapin=5;
const int FoodReprod=1000000; // CHANGEZ LES VALEURS 
const int ProbbirthRenard=1000000; 
const int minFreebirthlapin=1000000; 
const float ProbRenard=0.20; 
const float ProbLapin=0.07; 

enum Espece {Vide,Lapin,Renard};
struct Animal{
   Espece espece;
   int food;
   coord c;
};


float hasard();
Animal creerAnimal(Espece e, coord c);

coord coordAnimal( Animal a);

Espece especeAnimal( Animal a);

int nourritureRenard(Animal a);

bool estVide (Animal a);
 
void changeCoordAnimal(Animal &a, coord c);

void mangeRenard(Animal &a);

void faimRenard(Animal &a);

bool mortAnimal(Animal a);
  
bool seReproduitAnimal(Animal a, int nbVoisinsVides);

#endif