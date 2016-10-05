#include <iostream>

#include "nombre.hpp"
#include "grille.hpp"
#include "FPtab.hpp"

using namespace std;

int main () {
	//variable
		Grille * cour, * depart;
		FP aVoir;
		vector<Grille *> dejaFait;
		Nombre * tmp;
		vector<Grille *> fils;
		int taille, i;
		vector<Nombre> base;
	//début

		//initialisation	
			depart = new Grille();

			aVoir.enfiler(depart);


		//recherche
		while (!(aVoir.premier()->getScore() == 0)) {
			cour = aVoir.premier();
			aVoir.defiler();
			dejaFait.push_back(cour);
			cour->genererFils();
			fils = cour->getFils();
			taille = dejaFait.size();
			for(Grille * copie : fils) {
				i = 0;

				while ( i<taille && ( !( (*copie) == (*(dejaFait[i])) ) ) )  { ++i; }

				if (i == taille) {	aVoir.enfiler(copie); }
			}
		}
		aVoir.premier()->afficher();

		delete(depart);
	//fin

}