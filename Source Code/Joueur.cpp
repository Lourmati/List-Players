#include "Joueur.h"
#include <string>
using namespace std;

/*
* Implementation .cpp de Joueur.h
*/

Joueur::Joueur(const string& nom, float salaire) {
	this->nom = nom;
	this->salaire = salaire;
}

Joueur::~Joueur() {
	//Vide
}

const Joueur& Joueur::operator=(const Joueur& unJoueur)
{
	setNom(unJoueur.getNom());
	setSalaire(unJoueur.getSalaire());
	return *this;//On retourne le this, déjà existant
}

const string& Joueur::getNom() const {
	return nom;
}

float Joueur::getSalaire() const {
	return salaire;
}

void Joueur::setNom(const string& nom) {
	this->nom = nom;
}

void Joueur::setSalaire(float salaire) {
	this->salaire = salaire;
}