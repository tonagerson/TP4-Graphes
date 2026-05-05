#include"Aeroport.h"
#include<string>
#include <iostream>

Aeroport::Aeroport(std::string id, std::string nom, int lon, int lat) :_id(id), _nom(nom), _lon(lon), _lat(lat) {}
void Aeroport::AjouterArete(const Connexion& vol){
    _volsaller.push_back(vol);
}
std::string Aeroport::getId() const {
    return _id;
}
void Aeroport::afficher() const {
    std::cout << "[" << _id << "] " << _nom << " (Lat: " << _lat << ", Lon: " << _lon << ")" << std::endl;
      for (const auto& vol : _volsaller) {
        vol.afficher();
    }
}
int Aeroport::getLon() const {
    return _lon;
}

int Aeroport::getLat() const {
    return _lat;
}
std::vector<Connexion> Aeroport::getVols() const {
    return _volsaller;
}
