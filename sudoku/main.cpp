#include <iostream>
#include "grille.hpp"

using namespace std;

int main () {
	//variable
	 grille test;
	 int x,y,v;
	//début
		test.afficher();
		while (! test.gagne() ){
			cout << "jouer à l'abscisse : ";
			cin >> x;
			cout <<" et à l'ordonnée : ";
			cin >> y;
			cout << " la valeur : ";
			cin >> v;
			cout << "\n" <<endl;
			if ( test.jouer(x-1,y-1,v) ) {
				cout << "fait" << endl;
			} else {
				cout << "ceci n'est pas posible" << endl;
			}
			test.afficher();
		}
	//fin
return 0;
}
