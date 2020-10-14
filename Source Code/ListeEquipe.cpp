#include "ListeEquipe.h"

/*
* Implementation .cpp de ListeEquipe.h
*/

ListeEquipe::ListeEquipe() :maximum(2), taille(0) {
	lesEquipes = new Equipe[maximum];//Initialiser le tableau � 2
}

ListeEquipe::~ListeEquipe() {
	delete[] lesEquipes;//Supprimer la liste avec delete
}

const ListeEquipe& ListeEquipe::operator=(const ListeEquipe& lj) {
	for (int i = 0; i < taille; i++) {
		//Inserer a la fin de la liste copie, l'�quipe (i) de lj
		insererFin(lj.obtenirEquipe(i));//Utiliser les autres m�thodes
	}
	return *this; //Retourner la copie
}

void ListeEquipe::insererFin(const Equipe& equipe) {
	//Si le maximum est atteint, on double la capacit�
	if (taille == maximum) {
		doublerMaximum();
	}
	lesEquipes[taille] = equipe;//On ajoute equipe � la fin (taille)
	taille++;
}

const Equipe& ListeEquipe::obtenirEquipe(int indice) const {
	return lesEquipes[indice];//Retourne l'�quipe selon indice
}

Equipe& ListeEquipe::obtenirEquipe(int indice) {
	return lesEquipes[indice];
}

int ListeEquipe::getTaille() const {
	return taille;//Retourne la taille
}

/*
* On utilise une �quipe ancien, pour pouvoir y stocker l'ancienne �quipe
* Par la suite, on double la capacit� de les�quipes et on y ins�re ancien
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
