#include "Equipe.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
* Implementation .cpp de Equipe.h
*/
Equipe::Equipe(const string& nom) {
	this->nomEquipe = nom;
}

Equipe::~Equipe() {
	//Vide
}

const Equipe& Equipe::operator=(const Equipe& equipe) {
	//Je copie chaque attributs et je retourne *this (la copie)
	setNomfichier(equipe.getNomEquipe());
	nomEquipe = equipe.getNomEquipe();
	joueurs = equipe.getListeJoueurs();
	return *this;
}

const string& Equipe::getNomEquipe() const {
	return nomEquipe;
}

const ListeJoueur& Equipe::getListeJoueurs() const {
	return joueurs;
}

void Equipe::setNomfichier(const string& nomfichier) {
	this->nomFichier = nomFichier;
}

const string& Equipe::getNomfichier() const {
	return nomFichier;
}

/*
* On fait appel à insererFin() pour insérer le joueur à la fin de la liste
*/
void Equipe::ajouterJoueur(const Joueur& unJoueur) {
	joueurs.insererFin(unJoueur);
}

/*
* On commence par vérifier si la liste est vide, si oui, j'affiche message et on quitte
* Sinon, on positionne le curseur à l'endroit voulu (au joueur à retirer)
* Finalement, appel à retirerCurseurElement, pour retirer l'élemenent du curseur
*/
void Equipe::retirerJoueur(const Joueur& unJoueur) {
	if (joueurs.estVide()) {
		cout << "Aucun élement à retirer!!" << endl;
	}

	joueurs.deplacerCurseurDebut();

	for (int i = 0; i <= joueurs.getTaille(); i++) {
		if (joueurs.obtenirElement(i).getNom() == unJoueur.getNom()) {
			break;// On quitte la boucle for, si le curseur correspond au joueur (nom)
		}
		joueurs.deplacerCurseurSuivant();
	}

	//Le curseur est maintenant bien placé et on peut retirer l'element pointé par le curseur
	joueurs.retirerCurseurElement();
}

/*
* Sauvegarde de la liste dans le fichier txt correpondant à l'équipe
*/
void Equipe::sauvegarder() {
	ofstream fichier;
	fichier.open(nomFichier);// J'ouvre le fichier

	for (int i = 0; i < joueurs.getTaille(); i++) {
		if (i == 0) {// Premiere ligne pour écrire le nom de l'équipe
			fichier << nomEquipe << endl;
		}
		else {
			//Pour le reste des lignes, afficher les joueurs et leurs salaires
			//Utilisation de setw, pour pouvoir bien formater en colonne le tout
			fichier << left << setw(30) << joueurs.obtenirElement(i).getNom() << ";" <<
				right << setw(9) << joueurs.obtenirElement(i).getSalaire() << endl;
		}
	}
	fichier.close();//Fermer le fichier
}
