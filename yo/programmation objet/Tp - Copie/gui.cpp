#include "gui.h"
#include <fstream>
#include <iostream>
#include <string>

// 1. On récupère notre fonction de lecture qu'on place en haut du fichier
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

// Initialisation de l'application wxWidgets
wxIMPLEMENT_APP(MonApp);

bool MonApp::OnInit() {
    Fenetre *fenetre = new Fenetre(wxT("Réseau Aérien - Livrable 3"));
    fenetre->Show(true);
    return true;
}

// Identifiants des boutons
enum {
    ID_QUITTER = 101
};

// Table des événements
wxBEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_PAINT(Fenetre::OnPaint)
    EVT_BUTTON(ID_QUITTER, Fenetre::OnQuitter)
wxEND_EVENT_TABLE()

// Constructeur de la fenêtre
Fenetre::Fenetre(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    
    // Création du bouton
    btnQuitter = new wxButton(this, ID_QUITTER, wxT("Quitter"), wxPoint(10, 10));
    new wxStaticText(this, wxID_ANY, wxT("Carte du Réseau Aérien"), wxPoint(120, 15));
    // 2. C'EST ICI QU'ON CHARGE LE FICHIER !
    // Dès que la fenêtre s'ouvre, on remplit l'attribut reseauAerien
    chargerDepuisFichier(reseauAerien, "reseau.txt");

    // 3. On l'affiche dans le terminal en arrière-plan pour prouver que ça marche
    reseauAerien.afficherGraphe();
}

// Zone de dessin (OnPaint)
void Fenetre::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this); 
    
    // 1. DESSINER LES ARÊTES (VOLS) EN PREMIER
    dc.SetPen(wxPen(*wxRED, 1, wxPENSTYLE_SOLID)); // On prépare un crayon rouge fin
    
    for (const auto& a : reseauAerien.getSommets()) {
        // Coordonnées de l'aéroport de départ
        int x1 = (a.getLon() * 10) + 200; 
        int y1 = (a.getLat() * 10) + 200; 

        // On parcourt tous les vols qui partent de cet aéroport
        for (const auto& vol : a.getVols()) {
            std::string idDest = vol.getArrivee();
            
            // On cherche l'aéroport d'arrivée pour avoir ses coordonnées
            for (const auto& dest : reseauAerien.getSommets()) {
                if (dest.getId() == idDest) {
                    int x2 = (dest.getLon() * 10) + 200;
                    int y2 = (dest.getLat() * 10) + 200;
                    
                    // On trace la ligne rouge entre le départ et l'arrivée
                    dc.DrawLine(x1, y1, x2, y2); 
                    break; // On a trouvé la destination, on arrête de chercher
                }
            }
        }
    }

    // 2. DESSINER LES SOMMETS (AÉROPORTS) PAR-DESSUS
    dc.SetBrush(*wxBLUE_BRUSH); 
    dc.SetPen(*wxBLACK_PEN);
    for (const auto& a : reseauAerien.getSommets()) {
        int x = (a.getLon() * 10) + 200; 
        int y = (a.getLat() * 10) + 200; 

        dc.DrawCircle(x, y, 5);
        dc.DrawText(wxString(a.getId()), x + 10, y - 15); 
    }
}

// Action du bouton
void Fenetre::OnQuitter(wxCommandEvent& event) {
    Close(true);
}