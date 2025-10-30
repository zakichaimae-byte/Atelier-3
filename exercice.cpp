#include <iostream>
using namespace std;

struct Noeud {
    int valeur;
    Noeud* suivant;
};

class Pile {
private:
    Noeud* sommet; // pointeur vers le dernier élément empilé

public:
    Pile() : sommet(nullptr) {
        cout << "Pile initialisée !" << endl;
    }

    void push(int val) {
        Noeud* nouveau = new Noeud;
        nouveau->valeur = val;
        nouveau->suivant = sommet;
        sommet = nouveau;
        cout << "Empilé: " << val << endl;
    }

    void pop() {
        if (sommet == nullptr) {
            cout << "Erreur: pile vide." << endl;
            return;
        }
        cout << "Dépilé: " << sommet->valeur << endl;
        Noeud* temp = sommet;
        sommet = sommet->suivant;
        delete temp;
    }

    void afficher() {
        if (!sommet) {
            cout << "Pile vide." << endl;
            return;
        }
        cout << "Contenu de la pile: ";
        Noeud* courant = sommet;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    ~Pile() { // destructeur pour libérer la mémoire
        while (sommet != nullptr) {
            pop();
        }
    }
};

int main() {
    Pile p1, p2;

    cout << "\n=== Test de la pile p1 ===" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.afficher();
    p1.pop();
    p1.afficher();

    cout << "\n=== Test de la pile p2 ===" << endl;
    p2.push(5);
    p2.push(15);
    p2.push(25);
    p2.pop();
    p2.afficher();

    return 0;
}
