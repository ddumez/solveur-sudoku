#include <iostream>

#include "grille.hpp"
#include "FPtab.hpp"

#define ASSERTION

using namespace std;

int main () {
	//variable
		vector<Nombre> base;
		Nombre *tmp;
		Grille * test;
		vector<Grille *> fils;

	//début
		tmp = new Nombre(7,2,0);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(8,4,0);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(9,6,0);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,8,0);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(4,1,1);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(5,3,1);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,5,1);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(7,6,1);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(1,8,1);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,0,2);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(7,3,2);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(9,5,2);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(6,7,2);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(7,4,3);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,7,3);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(9,8,3);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(1,3,4);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(4,5,4);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(4,0,5);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(2,1,5);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(9,4,5);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,1,6);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(2,3,6);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(7,5,6);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(8,8,6);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(6,0,7);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(2,2,7);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,3,7);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(8,5,7);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(1,7,7);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(8,0,8);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(5,2,8);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(6,4,8);
		base.push_back(*tmp);
		delete(tmp);
		tmp = new Nombre(3,6,8);
		base.push_back(*tmp);
		delete(tmp);


		test = new Grille();

		test->afficher();

		test->genererFils();

		cout<<"\n nombre de fils : "<<test->getFils().size()<<endl;

		fils = test->getFils();
		for(Grille * cour : fils) {
			cour->afficher();
			cout<<"\n"<<endl;
		}




	delete(test);
}