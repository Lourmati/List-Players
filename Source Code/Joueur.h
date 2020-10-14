#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

/*
* Classe joueur dans lequel se trouve les accesseurs et mutateurs concernant le joueur
*/
class Joueur {
public:
	//Constructeur par défaut
	Joueur(const string& nom = "", float salaire = 0.0f);

	//Destructeur
	~Joueur();

	//Operateur = (copier unJoueur)
	const Joueur& operator=(const Joueur& unJoueur);

	//Retourne le nom du joueur
	const string& getNom() const;

	//Retourne le salaire du joueur
	float getSalaire() const;

	//Attribue le nom au joueur
	void setNom(const string& nom);

	//Attribue le salaire au joueur
	void setSalaire(float salaire);

private:
	string nom;//nom du joueur
	float salaire;//salaire du joueur
};
#endif