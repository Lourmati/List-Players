#ifndef NOEUDJOUEUR_H
#define NOEUDJOUEUR_H

#include "Joueur.h"

/*
* Classe NoeudJoueur dans laquelle se trouve le nécessaire (constructeur, accesseurs,mutateurs)
* Pour pouvoir créer et manipuler mes noeuds (nécessaire pour la liste de joueurs)
*/
class NoeudJoueur {
public:
	//Constructeur par défaut
	NoeudJoueur();

	//Constructeur de copie
	NoeudJoueur(const NoeudJoueur& ne);

	//Destructeur
	~NoeudJoueur();

	//Operateur = (copier le noeud)
	const NoeudJoueur& operator=(const NoeudJoueur& noeud);

	//Set le joueur au noeud
	void setJoueur(const Joueur& joueur);

	//Set le suivant du noeud
	void setSuivant(NoeudJoueur* n);

	//Retourne le suivant du noeud
	NoeudJoueur* getSuivant() const;

	//Retourne le joueur du noeud (constant)
	const Joueur& getJoueur() const;

	//Retourne le joueur du noeud
	Joueur& getJoueur();

private:
	NoeudJoueur* suivant;//Pointe sur le suivant du noeud courant
	Joueur leJoueur;//joueur pour noeud
};
#endif