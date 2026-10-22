# Modélisation et Optimisation de Réseau Aérien (Graphes en C++)

Application développée en **C++ moderne** permettant de modéliser, manipuler et visualiser un réseau de transport aérien sous forme de **graphe orienté et pondéré**.

---

## Fonctionnalités

- **Structures de données génériques :** Implémentation d'un graphe à l'aide de templates C++ (`GrapheGenerique<Sommet, Arete>`), totalement découplé des types manipulés.
- **Modélisation métier :** Instanciation du graphe avec les classes `Aeroport` (sommets avec coordonnées géographiques) et `Connexion` (arêtes avec durée de vol).
- **Conteneurs STL :** Utilisation intensive de la bibliothèque standard (`std::vector`, itérateurs) pour garantir des performances optimales de parcours.
- **Parsing de réseau :** Lecture et chargement dynamique depuis un fichier de données structuré (`reseau.txt`).
- **Interface graphique (GUI) :** Affichage visuel du réseau de vol avec le framework **wxWidgets**.

---

## Aperçu du résultat

![Aperçu du réseau aérien](Yo/Objet%20de%20programmation/Tp%20-%20Copie/Images/Capture%20du%20r%C3%A9seau%20a%C3%A9rien.png)

---

## Compilation et exécution

Le projet utilise un **Makefile** :

```bash
# Compilation
make

# Exécution
./testReseauAerien
