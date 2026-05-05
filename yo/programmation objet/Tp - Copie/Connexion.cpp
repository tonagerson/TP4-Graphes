#include "Connexion.h"
#include <iostream>
Connexion::Connexion(std::string depart, std::string arrivee, int duree) : _depart(depart), _arrivee(arrivee), _duree(duree) {}
void Connexion::afficher() const {
    std::cout << "    -> Vol vers " << _arrivee << " (" << _duree << " min)" << std::endl;
}
std::string Connexion::getArrivee() const {
    return _arrivee;
}