#include "ListeEquipe.h"

/*
* Implementation .cpp de ListeEquipe.h
*/

ListeEquipe::ListeEquipe() :maximum(2), taille(0) {
	lesEquipes = new Equipe[maximum];//Initialiser le tableau à 2
}

ListeEquipe::~ListeEquipe() {
	delete[] lesEquipes;//Supprimer la liste avec delete
}

const ListeEquipe& ListeEquipe::operator=(const ListeEquipe& lj) {
	for (int i = 0; i < taille; i++) {
		//Inserer a la fin de la liste copie, l'équipe (i) de lj
		insererFin(lj.obtenirEquipe(i));//Utiliser les autres méthodes
	}
	return *this; //Retourner la copie
}

void ListeEquipe::insererFin(const Equipe& equipe) {
	//Si le maximum est atteint, on double la capacité
	if (taille == maximum) {
		doublerMaximum();
	}
	lesEquipes[taille] = equipe;//On ajoute equipe à la fin (taille)
	taille++;
}

const Equipe& ListeEquipe::obtenirEquipe(int indice) const {
	return lesEquipes[indice];//Retourne l'équipe selon indice
}

Equipe& ListeEquipe::obtenirEquipe(int indice) {
	return lesEquipes[indice];
}

int ListeEquipe::getTaille() const {
	return taille;//Retourne la taille
}

/*
* On utilise une équipe ancien, pour pouvoir y stocker l'ancienne équipe
* Par la suite, on double la capacité de lesÉquipes et on y insère ancien
*/
void ListeEquipe::doublerMaximum() {
	Equipe* ancien = lesEquipes;
	maximum *= 2;
	lesEquipes = new Equipe[maximum];
	for (int i = 0; i < taille; i++) {
		lesEquipes[i] = ancien[i];
	}
	delete[] ancien;// On peut supprimer ancien maintenant
}
