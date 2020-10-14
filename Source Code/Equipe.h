#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include "ListeJoueur.h"
using namespace std;

/*
* Classe Equipe, qui contient la liste de joueurs, le nom d'équipe et le nom du fichier de l'équipe
* Accesseurs, constructeurs, mutateurs, méthode pour pouvoir manipuler l'équipe
*/
class Equipe {
public:

	//Constructeur par défaut
	Equipe(const string& nom = "");

	//Destructeur
	~Equipe();

	//Operateur =, copier une équipe
	const Equipe& operator=(const Equipe& equipe);

	//Retourne le nom de l'équipe
	const string& getNomEquipe() const;

	//Retoune la liste de joueurs de l'équiê
	const ListeJoueur& getListeJoueurs() const;

	//Set le nom de fichier de l'équipe
	void setNomfichier(const string& nomfichier);

	//Retourne le nom de fichier de l'équipe
	const string& getNomfichier() const;

	//Ajoute un joueur dans la liste de joueurs de l'équipe (avec insererFin)
	void ajouterJoueur(const Joueur& unJoueur);

	/*
	*La méthode va placer le curseur au joueur qu'il faut retirer,
	*Par la suite, elle fait appel a retirerCurseurElement qui va retirer
	*L'element pointé par le curseur
	*/
	void retirerJoueur(const Joueur& unJoueur);

	//Sauvegarde la liste de joueurs dans le fichier texte correspondant (en écriture)
	void sauvegarder();

private:
	string nomFichier;// Nom du fichier txt de l'équipe
	string nomEquipe;// Nom de l'équipe
	ListeJoueur joueurs;// La liste de joueurs de l'équipe
};
#endif
