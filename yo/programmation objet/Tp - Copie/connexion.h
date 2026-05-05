#include <string>

class Connexion{
    private:
      
        std::string _depart;
        std::string _arrivee;
        int _duree;
    public:
        Connexion(std::string depart, std::string arrivee, int duree);
        void afficher() const;
    };