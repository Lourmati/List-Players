#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include "ListeJoueur.h"
using namespace std;

/*
* Classe Equipe, qui contient la liste de joueurs, le nom d'�quipe et le nom du fichier de l'�quipe
* Accesseurs, constructeurs, mutateurs, m�thode pour pouvoir manipuler l'�quipe
*/
class Equipe {
public:

	//Constructeur par d�faut
	Equipe(const string& nom = "");

	//Destructeur
	~Equipe();

	//Operateur =, copier une �quipe
	const Equipe& operator=(const Equipe& equipe);

	//Retourne le nom de l'�quipe
	const string& getNomEquipe() const;

	//Retoune la liste de joueurs de l'�qui�
	const ListeJoueur& getListeJoueurs() const;

	//Set le nom de fichier de l'�quipe
	void setNomfichier(const string& nomfichier);

	//Retourne le nom de fichier de l'�quipe
	const string& getNomfichier() const;

	//Ajoute un joueur dans la liste de joueurs de l'�quipe (avec insererFin)
	void ajouterJoueur(const Joueur& unJoueur);

	/*
	*La m�thode va placer le curseur au joueur qu'il faut retirer,
	*Par la suite, elle fait appel a retirerCurseurElement qui va retirer
	*L'element point� par le curseur
	*/
	void retirerJoueur(const Joueur& unJoueur);

	//Sauvegarde la liste de joueurs dans le fichier texte correspondant (en �criture)
	void sauvegarder();

private:
	string nomFichier;// Nom du fichier txt de l'�quipe
	string nomEquipe;// Nom de l'�quipe
	ListeJoueur joueurs;// La liste de joueurs de l'�quipe
};
#endif
