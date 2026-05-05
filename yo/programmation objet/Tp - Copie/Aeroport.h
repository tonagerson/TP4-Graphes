#ifndef AEROPORT_H
#define AEROPORT_H

#include <string>
#include <vector>
#include "Connexion.h"

class Aeroport{
    private:
        std::string _id, _nom;
        int _lon, _lat;
        std::vector<Connexion> _volsaller;
        std::vector<Connexion> _volretour;
   
     public:
        Aeroport(std::string id, std::string nom, int lon, int lat);
         void AjouterArete(const Connexion& vol);
         std::string getId() const; 
         void afficher() const;
         
         // Les getters pour la fenêtre graphique
         int getLon() const;
         int getLat() const;
         std::vector<Connexion> getVols() const;
        
};
#endif