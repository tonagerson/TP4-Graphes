#include <string>
#ifndef CONNEXION_H
#define CONNEXION_H

class Connexion{
    private:
      
        std::string _depart;
        std::string _arrivee;
        int _duree;
    public:
        Connexion(std::string depart, std::string arrivee, int duree);
        void afficher() const;
        std::string getArrivee() const;
    };

#endif