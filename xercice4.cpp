#include <iostream>
#include <string>
using namespace std;

class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    // 🔸 Constructeur par défaut
    Client() : id(0), nom(""), prenom("") {
        cout << "Client vide créé." << endl;
    }

    // 🔸 Constructeur avec paramètres
    Client(int i, string n, string p) : id(i), nom(n), prenom(p) {
        cout << "Client créé : " << nom << " " << prenom << endl;
    }

    // 🔸 Constructeur de copie
    Client(const Client& c) {
        id = c.id;
        nom = c.nom;
        prenom = c.prenom;
        cout << "Client copié : " << nom << " " << prenom << endl;
    }

    // 🔸 Destructeur
    ~Client() {
        cout << "Client détruit : " << nom << " " << prenom << endl;
    }

    // 🔸 Méthode d’affichage
    void afficher() const {
        cout << "Client [ID=" << id << "] : " << nom << " " << prenom << endl;
    }
};
class Compte {
private:
    int numero;
    float solde;
    Client* client; // pointeur vers le client associé
    static int nbComptes; // compteur global des comptes

public:
    // 🔸 Constructeur par défaut
    Compte() : numero(0), solde(0.0), client(nullptr) {
        nbComptes++;
        cout << "Compte vide créé. Total comptes: " << nbComptes << endl;
    }

    // 🔸 Constructeur avec paramètres
    Compte(int num, float s, const Client& c) : numero(num), solde(s) {
        client = new Client(c); // copie du client (copie profonde)
        nbComptes++;
        cout << "Compte créé (numéro " << numero << "). Total comptes: " << nbComptes << endl;
    }

    // 🔸 Constructeur de copie
    Compte(const Compte& autre) {
        numero = autre.numero;
        solde = autre.solde;
        client = new Client(*(autre.client)); // copie profonde
        nbComptes++;
        cout << "Compte copié (numéro " << numero << "). Total comptes: " << nbComptes << endl;
    }

    // 🔸 Destructeur
    ~Compte() {
        delete client; // libère la mémoire du client
        nbComptes--;
        cout << "Compte détruit (numéro " << numero << "). Restants: " << nbComptes << endl;
    }

    // 🔸 Méthode d’affichage
    void afficher() const {
        cout << "\n=== Compte N°" << numero << " ===" << endl;
        cout << "Solde : " << solde << " €" << endl;
        if (client != nullptr) {
            client->afficher();
        } else {
            cout << "Aucun client associé." << endl;
        }
    }

    // 🔸 Méthode statique pour afficher le nombre total
    static void afficherNbComptes() {
        cout << "Nombre total de comptes existants : " << nbComptes << endl;
    }

    // 🔸 Accès au solde (pour les intérêts)
    float getSolde() const { return solde; }
    void setSolde(float s) { solde = s; }
};

// ⚠️ Initialisation de la variable statique
int Compte::nbComptes = 0;
// 🔹 Fonction globale pour calculer les intérêts
inline float calculInteret(float solde, float taux) {
    return solde + (solde * taux / 100);
}
int main() {
    cout << "=== DÉBUT DU PROGRAMME ===" << endl;

    // Création de clients
    Client c1(1, "Dupont", "Jean");
    Client c2(2, "Martin", "Claire");

    // Création de comptes
    Compte cp1(1001, 2500.0, c1);
    Compte cp2(1002, 4800.0, c2);

    Compte::afficherNbComptes();

    // Copie d’un compte
    Compte cp3 = cp1; // constructeur de copie
    Compte::afficherNbComptes();

    // Afficher les comptes
    cp1.afficher();
    cp2.afficher();
    cp3.afficher();

    // Calcul des intérêts
    float nouveauSolde = calculInteret(cp1.getSolde(), 5.0);
    cp1.setSolde(nouveauSolde);
    cout << "\nAprès intérêts, solde du compte 1001 = " << cp1.getSolde() << " €" << endl;

    // Suppression de comptes (automatique à la fin)
    cout << "\n=== FIN DU PROGRAMME ===" << endl;
    return 0;
}
