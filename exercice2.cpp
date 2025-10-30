#include <iostream>
using namespace std;

class Fichier {
private:
    char* P;       // Pointeur vers la zone mémoire (données du fichier)
    int longueur;  // Taille du fichier en octets

public:
    // 🔹 Constructeur : initialise le pointeur à nul
    Fichier() {
        P = nullptr;
        longueur = 0;
        cout << "Constructeur : Fichier créé (vide)" << endl;
    }

    // 🔹 Méthode Creation : alloue la mémoire
    void Creation(int n) {
        longueur = n;
        P = new char[longueur]; // allocation dynamique
        cout << "Mémoire de " << longueur << " octets allouée." << endl;
    }

    // 🔹 Méthode Remplit : remplir la mémoire avec des caractères arbitraires
    void Remplit() {
        if (P == nullptr) {
            cout << "Erreur : aucun espace mémoire alloué !" << endl;
            return;
        }

        for (int i = 0; i < longueur; i++) {
            P[i] = 'A' + (i % 26); // lettres de A à Z
        }

        cout << "Zone mémoire remplie avec des données." << endl;
    }

    // 🔹 Méthode Affiche : affiche le contenu de la mémoire
    void Affiche() {
        if (P == nullptr) {
            cout << "Erreur : aucune donnée à afficher !" << endl;
            return;
        }

        cout << "Contenu du fichier : ";
        for (int i = 0; i < longueur; i++) {
            cout << P[i];
        }
        cout << endl;
    }

    // 🔹 Destructeur : libère la mémoire
    ~Fichier() {
        delete[] P; // libération de la mémoire
        cout << "Destructeur : mémoire libérée." << endl;
    }
};

// 🔹 Programme principal
int main() {
    cout << "=== Début du programme ===" << endl;

    // Création d'un objet Fichier dynamiquement
    Fichier* f = new Fichier();

    // Appel des méthodes
    f->Creation(20);   // Allouer 20 octets
    f->Remplit();       // Remplir la zone mémoire
    f->Affiche();       // Afficher le contenu

    // Suppression de l’objet
    delete f; // Appel automatique du destructeur

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
