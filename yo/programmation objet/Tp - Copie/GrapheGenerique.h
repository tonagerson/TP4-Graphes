#ifndef GRAPHE_GENERIQUE_H
#define GRAPHE_GENERIQUE_H

#include <vector>
#include <iostream>

template <class Sommet, class Arete>
class GrapheGenerique {
    private:
        std::vector<Sommet> _listeSommets; 

    public:
        GrapheGenerique() {}

        void AjouterSommet(const Sommet& s) {
            _listeSommets.push_back(s);
        }

        template <typename TypeId>
        void AjouterArete(TypeId idDepart, const Arete& arete) {
            for (auto& sommet : _listeSommets) {
                if (sommet.getId() == idDepart) {
                    sommet.AjouterArete(arete); 
                    return; 
                }
            }
            std::cout << "Erreur : Sommet de depart introuvable !" << std::endl;
        }

        void afficherGraphe() const {
            std::cout << "\n--- AFFICHAGE DU GRAPHE ---" << std::endl;
            for (const auto& sommet : _listeSommets) {
                sommet.afficher();
            }
        }

        
        std::vector<Sommet>& getSommets() { 
            return _listeSommets; 
        }

}; 

#endif