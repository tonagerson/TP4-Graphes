#include"Graphe.h"
#include <fstream>
#include <iostream>
#include<vector>

Graphe::Graphe(){}
void Graphe::AjoutAeroport(const Aeroport &aeroport) {
    _ListAeroport.push_back(aeroport);
}
void Graphe::AjouterConnexion(std::string idDepart, const Connexion& vol) {
    for (auto& a : _ListAeroport) {
        if (a.getId() == idDepart) {
            a.Ajoutvolaller(vol); 
            std::cout << "Vol ajoute avec succes a l'aeroport " << idDepart << std::endl;
            return; 
        }
    }
    std::cout << "Erreur : Aeroport de depart introuvable !" << std::endl;
}
void Graphe::chargerDepuisFichier(std::string nomFichier) {
    std::ifstream fichier(nomFichier);
    // On vérifie si le fichier existe bien
    if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << " !" << std::endl;
        return;
    }
      int nbAeroports;
    fichier >> nbAeroports; // Lit le premier chiffre
     for (int i = 0; i < nbAeroports; i++) {
        std::string id, nom;
        int lon, lat;
        // Le >> lit mot par mot automatiquement !
        fichier >> id >> nom >> lon >> lat; 
         Aeroport nouvelAeroport(id, nom, lon, lat); 
        AjoutAeroport(nouvelAeroport);              // On l'ajoute au graphe
    }
    // 2. Lecture des connexions
    int nbVols;
    fichier >> nbVols; // Lit le nombre de vols 
    
    for (int i = 0; i < nbVols; i++) {
        std::string depart, arrivee;
        int duree;
        fichier >> depart >> arrivee >> duree;
        
        Connexion nouveauVol(depart, arrivee, duree); // l'arête
        AjouterConnexion(depart, nouveauVol);         // ajoute au bon aéroport
    }

    fichier.close();
    std::cout << "Fichier " << nomFichier << " charge avec succes et graphe construit !" << std::endl;
}

void Graphe::afficherGraphe() const {
    std::cout << "\n RESEAU AERIEN " << std::endl;
    for (const auto& a : _ListAeroport) {
        a.afficher();
    }
    std::cout << "Fin mon ami \n" << std::endl;
}