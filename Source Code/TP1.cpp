#include <iostream>
#include <fstream>
#include <Windows.h>
#include <clocale>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include "UtilitairesES.h"
#include "NoeudJoueur.h"
#include "Joueur.h"
#include "Equipe.h"
#include "ListeEquipe.h"
#include "ListeJoueur.h"

using namespace std;

/**
 * TP1: le main, dans lequel le menu sera affiché et l'utilisateur fera son choix
 * Auteur: Oussama Lourhmati
 * Date  : 27 octobre 2018
 */

void afficherMenu();
int determinerChoix();
void afficherMasseSalariale(const ListeEquipe& tabEquipes);
void afficherEquipe(const ListeEquipe& tabEquipes);
void ajouterJoueur(ListeEquipe& tabEquipes);
void retirerJoueur(ListeEquipe& tabEquipes);
Equipe creerBoston();
Equipe creerVegas();
void setNomFichiers(ListeEquipe& tabEquipes);

int main() {

	int choix;
	bool quitter = false;
	setlocale(LC_ALL, "");

	//Création des 2 équipes
	Equipe equipeBoston = creerBoston();
	Equipe equipeVegas = creerVegas();

	//Création liste d'équipes, et insertions des 2 équipes
	ListeEquipe tabEquipes;
	tabEquipes.insererFin(equipeBoston);
	tabEquipes.insererFin(equipeVegas);

	//Ajout d'une troisieme équipe pour voir si le programme ne plante pas
	//et pour vérifier si le tableau (liste d'équipes) va doubler son maixmum
	/*Equipe equipe3copieBoston = creerBoston();
	tabEquipes.insererFin(equipe3copieBoston);*/

	//Attribuer les noms de fichier aux 2 équipes
	setNomFichiers(tabEquipes);

	//Menu
	while (!quitter)
	{
		afficherMenu();
		choix = determinerChoix();
		switch (choix)
		{
		case 1:
			afficherMasseSalariale(tabEquipes);
			break;
		case 2:
			afficherEquipe(tabEquipes);
			break;
		case 3:
			ajouterJoueur(tabEquipes);
			break;
		case 4:
			retirerJoueur(tabEquipes);
			break;
		case 5:
			quitter = true;
		}
	}

	system("pause");
	return(0);
}


/**
* Fonction qui affiche le menu
* Entrée/Sortie: Aucun
*/
void afficherMenu() {

	cout << "Veuillez choisir parmis les options suivantes:\n"
		<< "1) Afficher la masse salariale des équipes\n"
		<< "2) Afficher une équipe\n"
		<< "3) Ajouter un joueur\n"
		<< "4) Retirer un joueur\n"
		<< "5) Quitter"
		<< endl;
}

/**
* Fonction qui determine le choix de l'utilisateur
* Sortie: Un choix entre 1 et 5
*/
int determinerChoix() {
	int choix = lireEntier("Entrez votre choix (entre 1 et 5)", 1, 5);
	return choix;
}

/**
* Fonction qui affiche la masse salariale des équipes
* Avec l'aide d'une boucle, calculer masse salariale pour chaque équipe
* Entrée: la liste d'équipes
*/
void afficherMasseSalariale(const ListeEquipe& tabEquipes) {

	// Pour formater l'affichage
	cout.setf(ios::showpoint);
	cout << setiosflags(ios::fixed);
	cout.precision(2);

	float masseSalariale = 0;

	//Calcul et affichage de la masse salariale (avec boucle)
	cout << left << setw(12) << "\nÉquipe" << " " << right << setw(9) << "Salaire\n" << endl;
	for (int i = 0; i < tabEquipes.getTaille(); i++) {
		masseSalariale = 0;
		for (int j = 0; j < tabEquipes.obtenirEquipe(i).getListeJoueurs().getTaille(); j++) {
			masseSalariale += tabEquipes.obtenirEquipe(i).getListeJoueurs()
				.obtenirElement(j).getSalaire();
		}

		//Pour bien afficher en colonne propre (formater)
		cout << left << setw(12) << tabEquipes.obtenirEquipe(i).getNomEquipe() << " "
			<< right << setw(10) << masseSalariale << " $" << endl;
	}
	cout << "\n";
}

/**
* Fonction qui affiche les joueurs de l'équipe choisi par l'utilisateur avec leurs salaires
* Entrée: la liste d'équipes
*/
void afficherEquipe(const ListeEquipe& tabEquipes) {

	// Pour formater l'affichage
	cout.setf(ios::showpoint);
	cout << setiosflags(ios::fixed);
	cout.precision(2);

	//Afficher les équipes
	cout << "\n";
	for (int i = 0; i < tabEquipes.getTaille(); i++) {
		cout << i+1 << ")" << tabEquipes.obtenirEquipe(i).getNomEquipe() << endl;
	}
	int choix = lireEntier("Choisissez votre équipe", 1, tabEquipes.getTaille());

	//Affichage
	cout << "Nom de l'équipe: " << tabEquipes.obtenirEquipe(choix - 1).getNomEquipe() << "\n" << endl;
	cout << left << setw(28) << "Nom du joueur" << " " << right << setw(9) << "Salaire" << endl;

	//Afficher chacun des joueurs avec une boucle
	for (int i = 0; i < tabEquipes.obtenirEquipe(choix - 1).getListeJoueurs().getTaille(); i++) {
		cout << left << setw(30) << tabEquipes.obtenirEquipe(choix - 1)
			.getListeJoueurs().obtenirElement(i).getNom() << " " << right << setw(9) <<
			tabEquipes.obtenirEquipe(choix - 1).getListeJoueurs().obtenirElement(i)
			.getSalaire() << " $" << endl;
	}
	cout << "\n";
}

/**
* Fonction qui ajoute un nouveau joueur à la fin de la liste de joueurs
* Entrée: la liste d'équipes
*/
void ajouterJoueur(ListeEquipe& tabEquipes) {

	string nomJoueur = "";
	float salaire = 0;

	//Afficher les équipes
	cout << "\n";
	for (int i = 0; i < tabEquipes.getTaille(); i++) {
		cout << i + 1 << ")" << tabEquipes.obtenirEquipe(i).getNomEquipe() << endl;
	}

	//Demander à l'utilisateur l'équipe, le nom et le salaire du nouveau joueur
	int choix = lireEntier("Choisissez votre équipe", 1, tabEquipes.getTaille());
	nomJoueur = lireString("Entrez le nom du joueur");
	salaire = lireReel("Entrez le salaire du joueur", 0, FLT_MAX);

	//Ajouter le joueur
	tabEquipes.obtenirEquipe(choix - 1).ajouterJoueur(Joueur(nomJoueur, salaire));
	tabEquipes.obtenirEquipe(choix - 1).sauvegarder();
	cout << "\n";
}

/**
* Fonction qui retire un joueur d'une des équipes selon le choix de l'utilisateur
* Entrée: la liste d'équipes
*/
void retirerJoueur(ListeEquipe& tabEquipes) {

	//Afficher les équipes
	cout << "\nEntrez l'équipe d'origine du joueur" << endl;
	for (int i = 0; i < tabEquipes.getTaille(); i++) {
		cout << i + 1 << ")" << tabEquipes.obtenirEquipe(i).getNomEquipe() << endl;
	}
	cout << "\n";

	int choix = lireEntier("Choisissez votre équipe", 1, tabEquipes.getTaille());

	//Afficher les joueurs de l'équipe choisi
	for (int i = 0; i < tabEquipes.obtenirEquipe(choix - 1).getListeJoueurs().getTaille(); i++)
	{
		cout << i + 1 << ")" << tabEquipes.obtenirEquipe(choix - 1)
			.getListeJoueurs().obtenirElement(i).getNom() << endl;
	}

	int joueurRetirer = lireEntier("Quel joueur voulez-vous retirer?", 1,
		tabEquipes.obtenirEquipe(choix - 1).getListeJoueurs().getTaille());

	//Retirer le joueur de l'équipe
	tabEquipes.obtenirEquipe(choix - 1).retirerJoueur
	(tabEquipes.obtenirEquipe(choix - 1).getListeJoueurs().obtenirElement(joueurRetirer - 1));

	tabEquipes.obtenirEquipe(choix - 1).sauvegarder();// On sauvegarde
	cout << "\n";
}

/**
* Fonction qui crée l'équipe de Boston à partir du fichier txt
* Sortie: l'équipe créé
*/
Equipe creerBoston() {
	string nom, tmp, nomEquipe, line;
	int i = 0;
	Equipe *equipe = new Equipe("Boston");//Nouvelle équipe Boston
	ifstream lecture;
	lecture.open("boston.txt", ios::in);//J'ouvre le fichier

	while (getline(lecture, line)) {//Boucle qui va traverser chaque ligne du fichier txt
		istringstream linein{ line };//Utilisation du istringstream
		if (i == 0) { //Premiere ligne qui contient le nom de l'équipe
			getline(linein, nomEquipe);// Je stocke le nom dans nomEquipe
		}
		else {
			getline(linein, nom, ';');//Avant le ;, je le stocke dans le nom du joueur
			getline(linein, tmp);//Apres le;, je stocke dans le salaire du joueur
			float salaire = strtof((tmp).c_str(), 0);// Je converti le salaire string en float
			Joueur *joueur = new Joueur(nom, salaire);// Je cree un joueur (de la ligne) à partir de nom et salaire
			equipe->ajouterJoueur(*joueur);// J'ajoute le nouveau joueur (la ligne) à l'équipe
		}
		i++;// Instancie i, le numero de la ligne
	}
	lecture.close();// Je ferme le fichier
	return *equipe; //Je retourne l'équipe créé dans la boucle while
}

/**
* Fonction qui crée l'équipe de Las Vegas à partir du fichier txt,
* meme principe que creerBoston().
* Sortie: l'équipe créé
*/
Equipe creerVegas() {
	string nom, tmp, nomEquipe, line;
	int i = 0;
	Equipe *equipe = new Equipe("Las Vegas");
	ifstream lecture;
	lecture.open("lasvegas.txt", ios::in);

	while (getline(lecture, line)) {
		istringstream linein{ line };
		if (i == 0) { //Premiere ligne
			getline(linein, nomEquipe);
		}
		else {
			getline(linein, nom, ';');
			getline(linein, tmp);
			float salaire = strtof((tmp).c_str(), 0);
			Joueur *joueur = new Joueur(nom, salaire);
			equipe->ajouterJoueur(*joueur);
		}
		i++;
	}
	lecture.close();
	return *equipe;
}

/**
* Fonction qui attribue à chacune des équipes leurs nom de fichier
* Entrée: la liste d'équipes
*/
void setNomFichiers(ListeEquipe& tabEquipes) {
	int i = 0;
	string line, nomFichier, nomFichier2;
	ifstream lecture;
	lecture.open("equipes.txt", ios::in);// J'ouvre equipe.txt

	while (getline(lecture, line)) {
		istringstream linein{ line };
		if (i == 0) { //Premiere ligne
			getline(linein, nomFichier);
		}
		if (i == 1) { //Deuxieme ligne
			getline(linein, nomFichier2);
		}
		i++; //Instancier i, le numero de ligne
	}
	lecture.close();//Je ferme le fichier

	//J'attribue le nom de fichier au différentes équipes
	tabEquipes.obtenirEquipe(0).setNomfichier(nomFichier);
	tabEquipes.obtenirEquipe(1).setNomfichier(nomFichier2);
}

