#ifndef LISTEEQUIPE_H
#define LISTEEQUIPE_H
#include "Equipe.h"

/*
* ListeEquipe est un tableau dynamique qui va contenir chacune des équipes
* Accesseurs, méthodes pour pouvoir manipuler le tableau dynamique d'équipes
*/

class ListeEquipe {
public:
	
	//Constructeur par défaut
	ListeEquipe();

	//Destructeur
	~ListeEquipe();

	//Operateur =, pour copier la liste d'équipe lj
	const ListeEquipe& operator=(const ListeEquipe& lj);

	//Inserer une nouvelle équipe à la fin de la liste d'équipe
	void insererFin(const Equipe& equipe);

	//Obtenir une équipe dans la liste d'équipes selon son indice (constant)
	const Equipe& obtenirEquipe(int indice) const;

	//Obtenir une équipe dans la liste d'équipes selon son indice
	Equipe& obtenirEquipe(int indice);

	//Retourne la taille de la liste d'équipes (du tableau dynamique)
	int getTaille() const;

private:
	void doublerMaximum();//Doubler la capacité si le maximum a été atteint
	int maximum; //Taille maximale que le tableau peut avoir (capacité maximale)
	int taille; //Taille actuelle du tableau, selon le nombre d'équipes
	Equipe *lesEquipes; //Equipe de la liste d'équipes
};
#endif
