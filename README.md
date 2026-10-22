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
<img width="960" height="540" alt="resultat png" src="https://github.com/user-attachments/assets/6c5082a9-a949-4f29-976b-013228104534" />




---

## Compilation et exécution

Le projet utilise un **Makefile** :

```bash
# Compilation
make

# Exécution
./testReseauAerien
