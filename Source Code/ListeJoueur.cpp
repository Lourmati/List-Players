#include "ListeJoueur.h"
#include <iostream>

/*
*Implementation .cpp de ListeJoueur.h
*/

//Constructeur par défaut, le tout est initalisé à null ou 0
ListeJoueur::ListeJoueur() {
	tete = nullptr;
	fin = nullptr;
	curseur = nullptr;
	taille = 0;
}

ListeJoueur::ListeJoueur(const ListeJoueur& uneListeJoueur) {
	*this = uneListeJoueur;//J'utilise l'opérateur =
}

ListeJoueur::~ListeJoueur() {
	viderListe();//J'utilise viderListe() pour vider la liste chainée
}

/*
* Code similaire à celui de la file, opérateur =
* Utilisation d'un noeud temporaire pour pouvoir faire la copie
*/
const ListeJoueur& ListeJoueur::operator=(const ListeJoueur& uneListeJoueur)
{
	viderListe();//Je vide la liste avant de faire le traitement
	NoeudJoueur *tmp = uneListeJoueur.tete;
	while (tmp != nullptr)
	{
		insererFin(tmp->getJoueur());
		tmp = tmp->getSuivant();
	}
	return *this;
}


void ListeJoueur::deplacerCurseurDebut() const {
	//La tete correspond au début de la file
	curseur = tete;
}

void ListeJoueur::deplacerCurseurSuivant() const {
	curseur = curseur->getSuivant();//Deplace le curseur au suivant
}


void ListeJoueur::retirerCurseurElement() {

	//Si le curseur pointe vers le premier élement de la liste
	if (curseur == tete) {
		tete = curseur->getSuivant();
		delete curseur;
		taille--;
	}

	//Sinon
	//On utilise un pointeur précedant pour pouvoir ajuster la liste une fois l'élement supprimé
	else {
		NoeudJoueur *precedant = tete;

		//Boucle pour positionner le pointeur précedant, avant le curseur
		while (precedant != nullptr) {
			// Si le nom du suivant du précedant correspond au nom du curseur, on sort de la boucle
			if (precedant->getSuivant()->getJoueur().getNom() == curseur->getJoueur().getNom()) {
				break;
			}
			precedant = precedant->getSuivant();
		}

		//Le pointeur précedant est maintenant bien placé
		//Il est important de relier le précedant au noeud suivant le curseur
		precedant->setSuivant(curseur->getSuivant());
		delete curseur;
		taille--;//Reduire la taille
	}
}


bool ListeJoueur::elementCurseurValide() const {
	if (curseur != nullptr) {//Si le curseur pointe à nullptr, ce n'est pas valide
		return true;
	}
	return false;
}

void ListeJoueur::insererAvantCurseur(const Joueur& unJoueur) {
	NoeudJoueur *precedant = tete;
	NoeudJoueur *nouveau = new NoeudJoueur();
	nouveau->setJoueur(unJoueur);
	taille++;

	//Boucle pour positionner le pointeur précedant, avant le curseur
	while (precedant != nullptr) {
		if (precedant->getSuivant()->getJoueur().getNom() == curseur->getJoueur().getNom()) {
			break;
		}
		precedant = precedant->getSuivant();
	}

	precedant->setSuivant(nouveau);
	nouveau->setSuivant(curseur);
}

const Joueur& ListeJoueur::obtenirCurseurElement() const {
	return curseur->getJoueur();
}

const Joueur& ListeJoueur::obtenirElement(int element) const {
	int compteur = 0;//Compteur qui va suivre le curseur
	deplacerCurseurDebut();

	while (curseur != nullptr) {
		if (compteur == element) { //Si le compteur atteint l'indice de l'element
			break; //On quitte la boucle
		}
		curseur = curseur->getSuivant();
		compteur++;// À chaque fois qu'on déplace le curseur, on instancie le compteur
	}
	return obtenirCurseurElement();
}

/*
* Code similaire à celui de la file, on ajoute un élement à la fin de la liste chainée
*/
void ListeJoueur::insererFin(const Joueur& unJoueur) {
	NoeudJoueur *nouveau = new NoeudJoueur();
	nouveau->setJoueur(unJoueur); //Set le joueur au noeud nouveau

	if (tete == nullptr) {//Si la tete pointe à nullptr, on fait instancie tete 
		tete = nouveau;
	}
	else {
		fin->setSuivant(nouveau);
	}
	fin = nouveau;
	taille++; //Instancier la taille car nouveau noeud ajouté
}


bool ListeJoueur::estVide() const {
	// Si tete et fin pointe nullptr, cela veut dire que la liste est vide
	if (tete == nullptr && fin == nullptr) {
		return true;
	}
	return false;
}

int ListeJoueur::getTaille() const {
	return taille;
}

/*
* Code similaire à celui de la file, on vide la liste chainée
* Et on remet les pointeurs à null et la taille à 0
* On supprime (delete) chaque noeud dans la boucle
*/
void ListeJoueur::viderListe() {
	while (tete != nullptr)
	{
		NoeudJoueur* tmp = tete;
		tete = tete->getSuivant();
		delete tmp;
	}
	fin = nullptr;
	tete = nullptr;
	taille = 0;
}
