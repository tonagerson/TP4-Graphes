#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <string>
#include "Aeroport.h"

class Graphe{
    private:
        std::vector<Aeroport> _ListAeroport;
    public:
        Graphe();
        void AjoutAeroport(const Aeroport& aeroport);
        void AjouterConnexion(std::string idDepart, const Connexion& vol);
        void chargerDepuisFichier(std::string nomFichier);
        void afficherGraphe() const;
    };
#endif