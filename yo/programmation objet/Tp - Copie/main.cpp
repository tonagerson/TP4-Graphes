#include <iostream>
#include "Graphe.h"
int main(){
    Graphe monReseau;
    monReseau.chargerDepuisFichier("reseau.txt");
    monReseau.afficherGraphe();
    return 0;
}