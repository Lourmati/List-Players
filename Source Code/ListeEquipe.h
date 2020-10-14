#ifndef LISTEEQUIPE_H
#define LISTEEQUIPE_H
#include "Equipe.h"

/*
* ListeEquipe est un tableau dynamique qui va contenir chacune des �quipes
* Accesseurs, m�thodes pour pouvoir manipuler le tableau dynamique d'�quipes
*/

class ListeEquipe {
public:
	
	//Constructeur par d�faut
	ListeEquipe();

	//Destructeur
	~ListeEquipe();

	//Operateur =, pour copier la liste d'�quipe lj
	const ListeEquipe& operator=(const ListeEquipe& lj);

	//Inserer une nouvelle �quipe � la fin de la liste d'�quipe
	void insererFin(const Equipe& equipe);

	//Obtenir une �quipe dans la liste d'�quipes selon son indice (constant)
	const Equipe& obtenirEquipe(int indice) const;

	//Obtenir une �quipe dans la liste d'�quipes selon son indice
	Equipe& obtenirEquipe(int indice);

	//Retourne la taille de la liste d'�quipes (du tableau dynamique)
	int getTaille() const;

private:
	void doublerMaximum();//Doubler la capacit� si le maximum a �t� atteint
	int maximum; //Taille maximale que le tableau peut avoir (capacit� maximale)
	int taille; //Taille actuelle du tableau, selon le nombre d'�quipes
	Equipe *lesEquipes; //Equipe de la liste d'�quipes
};
#endif
