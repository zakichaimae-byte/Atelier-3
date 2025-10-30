#include <iostream>
using namespace std;

// 🔹 Structure représentant un élément de la liste
struct Element {
    int valeur;       // Donnée stockée
    Element* suivant; // Pointeur vers l'élément suivant
};

// 🔹 Classe Liste
class Liste {
private:
    Element* tete; // Pointeur sur le premier élément

public:
    // Constructeur : initialise la liste vide
    Liste() {
        tete = nullptr;
        cout << "Liste initialisée (vide)" << endl;
    }

    // Méthode pour ajouter un élément au début
    void ajouterDebut(int val) {
        Element* nouveau = new Element; // alloue un nouvel élément
        nouveau->valeur = val;
        nouveau->suivant = tete; // l'ancien début devient le suivant
        tete = nouveau;          // la tête devient le nouvel élément
        cout << "Ajouté au début : " << val << endl;
    }

    // Méthode pour supprimer l'élément au début
    void supprimerDebut() {
        if (tete == nullptr) {
            cout << "La liste est vide, rien à supprimer." << endl;
            return;
        }
        Element* temp = tete;      // sauvegarde du premier élément
        tete = tete->suivant;      // avance la tête
        cout << "Supprimé : " << temp->valeur << endl;
        delete temp;               // libère la mémoire
    }

    // Méthode pour afficher toute la liste
    void afficher() {
        if (tete == nullptr) {
            cout << "Liste vide." << endl;
            return;
        }
        cout << "Contenu de la liste : ";
        Element* courant = tete;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    // Destructeur : libère toute la mémoire
    ~Liste() {
        cout << "Destruction de la liste..." << endl;
        while (tete != nullptr) {
            supprimerDebut(); // supprime un par un tous les éléments
        }
        cout << "Mémoire libérée." << endl;
    }
};

// 🔹 Programme principal
int main() {
    Liste L;

    L.ajouterDebut(10);
    L.ajouterDebut(20);
    L.ajouterDebut(30);
    L.afficher();

    L.supprimerDebut();
    L.afficher();

    cout << "Fin du programme (le destructeur sera appelé automatiquement)." << endl;
    return 0;
}
