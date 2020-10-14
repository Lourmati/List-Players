#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H
#include "NoeudJoueur.h"

/*
* Classe contenant le tout par rapport � la liste chain�e de joueur
* (accesseurs, mutateurs, constructeurs, m�thode pour manipuler la liste de joueurs)
*/

class ListeJoueur {
public:
public:

	//Constructeur par d�faut
	ListeJoueur();

	//Constructeur de copie
	ListeJoueur(const ListeJoueur& uneListeJoueur);

	//Destructeur
	~ListeJoueur();

	//Op�rateur =, je copie uneListeJoueur
	const ListeJoueur& operator=(const ListeJoueur& uneListeJoueur);

	// Fonctions d'utilisation du curseur
	void deplacerCurseurDebut() const; //Deplacer le curseur au d�but (tete)

	void deplacerCurseurSuivant() const; //Deplacer le curseur au noeud suivant

	void retirerCurseurElement(); //Retirer l'element sur lequel le curseur pointe

	bool elementCurseurValide() const; //Verifier si l'element sur lequel le cuseur pointe est valide

	void insererAvantCurseur(const Joueur& unJoueur); //Inserer un element avant le curseur

	const Joueur& obtenirCurseurElement() const; //Obtenir (get) l'element sur lequel le curseur pointe

	const Joueur& obtenirElement(int element) const; //Obtenir un element selon l'indice correspondant � l'element

	void insererFin(const Joueur& unJoueur); //Inserer un nouveau noeud de joueur � la fin de la liste chain�e

	bool estVide() const; // Verifie si la liste est vide

	int getTaille() const; //Retourne la taille de la liste chain�e

private:
	void viderListe(); //Vide la liste chain�e de joueur
	mutable NoeudJoueur* curseur; //Pointeur curseur, qui sera utile pour pouvoir faire traitements
	NoeudJoueur* tete; //Pointeur qui pointe au debut de la liste chain�e
	NoeudJoueur* fin; //Pointeur qui pointe � la fin de la liste chain�e
	int taille; //Taille de la liste chain�e
};
#endif