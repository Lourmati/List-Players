#ifndef UTILITAIRES_ES
#define UTILITAIRES_ES

/**
* Fichier qui comporte des fonctions permettant de faciliter les
* entr�es/sorties
*/

#include <string>

using namespace std;

/**
* Permet de lire un entier entre limiteInferieure et limiteSuperieure
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Entr�e: limiteInferieure la limite inf�rieure
* Entr�e: limiteSuperieure la limite sup�rieure
* Sortie: la valeur enti�re lue entre limiteInferieure et limiteSuperieure
*/
int lireEntier(const string& message, int limiteInferieure,
	int limiteSuperieure);

/**
* Permet de lire un r�el entre limiteInferieure et limiteSuperieure
* exclusivement
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Entr�e: limiteInferieure la limite inf�rieure
* Entr�e: limiteSuperieure la limite sup�rieure
* Sortie: la valeur r�elle lue entre limiteInferieure et limiteSuperieure
*/
float lireReel(const string& message, float limiteInferieure,
	float limiteSuperieure);

/**
* Permet de lire un string
* Entr�e: message Le message qui sera affich� � chaque lecture
* Sortie: la valeur string que l'utilisateur a saisi
*/
string lireString(const string& message);

#endif
