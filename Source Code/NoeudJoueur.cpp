#include "NoeudJoueur.h"

/*
* Implementation .cpp de NoeudJoueur.h
*/
NoeudJoueur::NoeudJoueur() {

}

NoeudJoueur::NoeudJoueur(const NoeudJoueur& ne) {
	*this = ne;//J'utilise l'opérateur = dans ce constructeur de copie
}

NoeudJoueur::~NoeudJoueur() {

}

const NoeudJoueur& NoeudJoueur::operator=(const NoeudJoueur& noeud)
{
	setJoueur(noeud.getJoueur());
	setSuivant(noeud.getSuivant());
	return *this;//On retourne le this, déjà existant
}

void NoeudJoueur::setJoueur(const Joueur& joueur) {
	this->leJoueur = joueur;
}

void NoeudJoueur::setSuivant(NoeudJoueur* n) {
	suivant = n;
}

NoeudJoueur* NoeudJoueur::getSuivant() const {
	return suivant;
}

const Joueur& NoeudJoueur::getJoueur() const {
	return leJoueur;
}

Joueur& NoeudJoueur::getJoueur() {
	return leJoueur;
}