# TP4 - Programmation par Objets : Graphes (Réseau Aérien)

**Auteurs :** TONA Gerson

## 1. Compilation et Exécution
Le projet a été configuré avec un Makefile standard. Pour compiler le programme, ouvrez un terminal dans le dossier du projet et tapez simplement :
make

Pour exécuter le programme, assurez-vous d'avoir votre fichier de données (ex: vols.txt) dans le même dossier, puis lancez :
./testReseauAerien

## 2. Format du fichier de données
Le graphe est généré dynamiquement en lisant un fichier texte structuré de la manière suivante :
- Première ligne : le nombre total d'aéroports.
- Lignes suivantes : les données de chaque aéroport (Identifiant, Nom, Longitude, Latitude).
- Ligne suivante : le nombre total de connexions (vols).
- Lignes suivantes : les données de chaque connexion (Aéroport de départ, Aéroport d'arrivée, Durée du vol).

## 3. Choix techniques et Structures de données
- **Généricité (Templates) :** Le noyau de l'application repose sur la classe `GrapheGenerique<Sommet, Arete>`. Conformément aux règles du C++ sur les templates, l'intégralité de son code (déclaration et implémentation) se trouve dans le fichier d'en-tête `GrapheGenerique.h`.
- **Conteneurs STL :** Nous avons utilisé les conteneurs de la Standard Template Library (STL), en particulier `std::vector`, pour stocker efficacement la liste des sommets dans le graphe et la liste des connexions sortantes dans chaque objet `Aeroport`.
- **Classes spécifiques :** Lors de l'exécution, le graphe est instancié avec nos classes dédiées au problème : `Aeroport` (agissant comme Sommet) et `Connexion` (agissant comme Arête). La fonction de lecture du fichier texte a été placée en dehors de la classe générique pour respecter la séparation des concepts.

## 4. État d'avancement
- **Livrable 1 (Validé) :** Implémentation des classes spécifiques `Aeroport` et `Connexion`, lecture des données depuis le flux d'entrée et construction du réseau en mémoire.
- **Livrable 2 (Validé) :** Refactoring complet pour transformer le graphe initial en un `GrapheGenerique` utilisant les templates. L'application compile parfaitement et affiche le réseau de manière générique.
