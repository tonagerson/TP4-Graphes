#ifndef GUI_H
#define GUI_H

#include <wx/wx.h>
#include "GrapheGenerique.h"
#include "Aeroport.h"
#include "Connexion.h"

// Déclaration de la fenêtre 
class Fenetre : public wxFrame {
private:
    GrapheGenerique<Aeroport, Connexion> reseauAerien; // graphe générique
    wxButton* btnQuitter;                              //  premier bouton 

public:
    Fenetre(const wxString& title);
    
    // Méthodes pour gérer les événements (dessin et clics) 
    void OnPaint(wxPaintEvent& event);
    void OnQuitter(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE(); // Table des événements 
};

// Déclaration de l'application 
class MonApp : public wxApp {
public:
    bool OnInit() override;
};

#endif