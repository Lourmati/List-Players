#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H
#include "NoeudJoueur.h"

/*
* Classe contenant le tout par rapport à la liste chainée de joueur
* (accesseurs, mutateurs, constructeurs, méthode pour manipuler la liste de joueurs)
*/

class ListeJoueur {
public:
public:

	//Constructeur par défaut
	ListeJoueur();

	//Constructeur de copie
	ListeJoueur(const ListeJoueur& uneListeJoueur);

	//Destructeur
	~ListeJoueur();

	//Opérateur =, je copie uneListeJoueur
	const ListeJoueur& operator=(const ListeJoueur& uneListeJoueur);

	// Fonctions d'utilisation du curseur
	void deplacerCurseurDebut() const; //Deplacer le curseur au début (tete)

	void deplacerCurseurSuivant() const; //Deplacer le curseur au noeud suivant

	void retirerCurseurElement(); //Retirer l'element sur lequel le curseur pointe

	bool elementCurseurValide() const; //Verifier si l'element sur lequel le cuseur pointe est valide

	void insererAvantCurseur(const Joueur& unJoueur); //Inserer un element avant le curseur

	const Joueur& obtenirCurseurElement() const; //Obtenir (get) l'element sur lequel le curseur pointe

	const Joueur& obtenirElement(int element) const; //Obtenir un element selon l'indice correspondant à l'element

	void insererFin(const Joueur& unJoueur); //Inserer un nouveau noeud de joueur à la fin de la liste chainée

	bool estVide() const; // Verifie si la liste est vide

	int getTaille() const; //Retourne la taille de la liste chainée

private:
	void viderListe(); //Vide la liste chainée de joueur
	mutable NoeudJoueur* curseur; //Pointeur curseur, qui sera utile pour pouvoir faire traitements
	NoeudJoueur* tete; //Pointeur qui pointe au debut de la liste chainée
	NoeudJoueur* fin; //Pointeur qui pointe à la fin de la liste chainée
	int taille; //Taille de la liste chainée
};
#endif