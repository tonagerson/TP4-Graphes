#include "GrapheGenerique.h"
#include "Aeroport.h"
#include "Connexion.h"
#include <fstream>
#include <iostream>
#include <string>

void chargerDepuisFichier(GrapheGenerique<Aeroport, Connexion>& graphe, std::string nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }
    
    int nbAeroports, nbVols;
    fichier >> nbAeroports; 
    
    for (int i = 0; i < nbAeroports; i++) {
        std::string id, nom;
        int lon, lat;
        fichier >> id >> nom >> lon >> lat; 
        graphe.AjouterSommet(Aeroport(id, nom, lon, lat));              
    }
    
    fichier >> nbVols; 
    for (int i = 0; i < nbVols; i++) {
        std::string depart, arrivee;
        int duree;
        fichier >> depart >> arrivee >> duree;
        graphe.AjouterArete(depart, Connexion(depart, arrivee, duree));         
    }
    fichier.close();
    std::cout << "Fichier " << nomFichier << " charge avec succes !" << std::endl;
}

int main() {
    GrapheGenerique<Aeroport, Connexion> reseauAerien;
    chargerDepuisFichier(reseauAerien, "reseau.txt"); 
    reseauAerien.afficherGraphe();
    return 0;
}