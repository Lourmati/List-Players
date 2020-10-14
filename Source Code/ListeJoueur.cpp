#include "ListeJoueur.h"
#include <iostream>

/*
*Implementation�.cpp de ListeJoueur.h
*/

//Constructeur par d�faut, le tout est initalis� � null ou 0
ListeJoueur::ListeJoueur() {
	tete = nullptr;
	fin = nullptr;
	curseur = nullptr;
	taille = 0;
}

ListeJoueur::ListeJoueur(const ListeJoueur& uneListeJoueur) {
	*this = uneListeJoueur;//J'utilise l'op�rateur =
}

ListeJoueur::~ListeJoueur() {
	viderListe();//J'utilise viderListe() pour vider la liste chain�e
}

/*
* Code similaire � celui de la file, op�rateur =
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
	//La tete correspond au d�but de la file
	curseur = tete;
}

void ListeJoueur::deplacerCurseurSuivant() const {
	curseur = curseur->getSuivant();//Deplace le curseur au suivant
}


void ListeJoueur::retirerCurseurElement() {

	//Si le curseur pointe vers le premier �lement de la liste
	if (curseur == tete) {
		tete = curseur->getSuivant();
		delete curseur;
		taille--;
	}

	//Sinon
	//On utilise un pointeur pr�cedant pour pouvoir ajuster la liste une fois l'�lement supprim�
	else {
		NoeudJoueur *precedant = tete;

		//Boucle pour positionner le pointeur pr�cedant, avant le curseur
		while (precedant != nullptr) {
			// Si le nom du suivant du pr�cedant correspond au nom du curseur, on sort de la boucle
			if (precedant->getSuivant()->getJoueur().getNom() == curseur->getJoueur().getNom()) {
				break;
			}
			precedant = precedant->getSuivant();
		}

		//Le pointeur pr�cedant est maintenant bien plac�
		//Il est important de relier le pr�cedant au noeud suivant le curseur
		precedant->setSuivant(curseur->getSuivant());
		delete curseur;
		taille--;//Reduire la taille
	}
}


bool ListeJoueur::elementCurseurValide() const {
	if (curseur != nullptr) {//Si le curseur pointe � nullptr, ce n'est pas valide
		return true;
	}
	return false;
}

void ListeJoueur::insererAvantCurseur(const Joueur& unJoueur) {
	NoeudJoueur *precedant = tete;
	NoeudJoueur *nouveau = new NoeudJoueur();
	nouveau->setJoueur(unJoueur);
	taille++;

	//Boucle pour positionner le pointeur pr�cedant, avant le curseur
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
		compteur++;// � chaque fois qu'on d�place le curseur, on instancie le compteur
	}
	return obtenirCurseurElement();
}

/*
* Code similaire � celui de la file, on ajoute un �lement � la fin de la liste chain�e
*/
void ListeJoueur::insererFin(const Joueur& unJoueur) {
	NoeudJoueur *nouveau = new NoeudJoueur();
	nouveau->setJoueur(unJoueur); //Set le joueur au noeud nouveau

	if (tete == nullptr) {//Si la tete pointe � nullptr, on fait instancie tete 
		tete = nouveau;
	}
	else {
		fin->setSuivant(nouveau);
	}
	fin = nouveau;
	taille++; //Instancier la taille car nouveau noeud ajout�
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
* Code similaire � celui de la file, on vide la liste chain�e
* Et on remet les pointeurs � null et la taille � 0
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
