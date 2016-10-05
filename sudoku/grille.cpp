#include "grille.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define nb_rand() ( (rand() % 4) + 1)
#define aff() for (int ind = 0; ind<TAILLE*2 ; ++ind) \
					{ cout<<"-"; } \
			cout<<"-"<<endl;

grille::grille() {
	//variable
		int s,t,u,v,w,x,y,z;
		srand (time(NULL));
	//début
		s = nb_rand();
		t = nb_rand();
		
		u = nb_rand();
		v = nb_rand();
		
		w = nb_rand();
		x = nb_rand();
		
		y = nb_rand();
		z = nb_rand();
		while (u == s) { u = nb_rand(); }
		while (t == v) { v = nb_rand(); }
		
		while ( (w == s) || (w == u) ) { w = nb_rand(); }
		while ( (x == t) || (x == v) ) { x = nb_rand(); }
		
		while ( (y == s) || (y == u) || (y == w) ) { y = nb_rand(); }
		while ( (z == t) || (z == v) || (z == x) ) { z = nb_rand(); }
		
		for (int i = 0; i<TAILLE; ++i) {
			for (int j = 0; j<TAILLE; ++j) {
				_valeur[i][j].val = 0;
				_valeur[i][j].modif = false;
			}
		}
		
		if (1 == s) { _valeur[0][0].val = t; _valeur[0][0].modif = true; }
		else if (2 == s) { _valeur[1][0].val = t; _valeur[1][0].modif = true; }
		else if (3 == s) { _valeur[0][1].val = t; _valeur[0][1].modif = true; }
		else if (4 == s) { _valeur[1][1].val = t; _valeur[1][1].modif = true; }
		if (1 == u) { _valeur[2][0].val = v; _valeur[2][0].modif = true; }
		else if (2 == u) { _valeur[3][0].val = v; _valeur[3][0].modif = true; }
		else if (3 == u) { _valeur[2][1].val = v; _valeur[2][1].modif = true; }
		else if (4 == u) { _valeur[3][1].val = v; _valeur[3][1].modif = true; }
		if (1 == w) { _valeur[2][2].val = x; _valeur[2][2].modif = true; }
		else if (2 == w) { _valeur[3][2].val = x; _valeur[3][2].modif = true; }
		else if (3 == w) { _valeur[2][3].val = x; _valeur[2][3].modif = true; }
		else if (4 == w) { _valeur[3][3].val = x; _valeur[3][3].modif = true; }
		if (1 == y) { _valeur[0][2].val = z; _valeur[0][2].modif = true; }
		else if (2 == y) { _valeur[1][2].val = z; _valeur[1][2].modif = true; }
		else if (3 == y) { _valeur[0][3].val = z; _valeur[0][3].modif = true; }
		else if (4 == y) { _valeur[1][3].val = z; _valeur[1][3].modif = true; }	
	//fin
}

grille::~grille() {
	//il n'y a pas d'allocation dynamique donc rien à faire
}

bool grille::gagne() {
	//variable 
		bool res = true;
		int i = 0;
	//début
		while ((i<TAILLE) && res ) {
			res = res && ( ( _valeur[0][i].val + _valeur[1][i].val + 
				_valeur[2][i].val + _valeur[3][i].val ) == 10);
			++i;
		}
		i = 0;
		while ((i<TAILLE) && res ) {
			res = res && ( ( _valeur[i][0].val + _valeur[i][1].val + 
				_valeur[i][2].val + _valeur[i][3].val ) == 10 );
			++i;
		}
	//fin
return res;
}

void grille::afficher() {
	aff()
	for (int i = 0; i<TAILLE; ++i) {
		cout<<"|";
		for (int j = 0; j<TAILLE ; ++j) {
			cout<< _valeur[j][i].val << "|";
		}
		cout << "\n";
		aff()
	}
}

bool grille::jouer (int x, int y, int val) {
	//variable
		bool pos = true;
		int i = 0;
	//début
	if ( (_valeur[x][y].modif) || (val > 4 ) || (val < 0 ) 
			|| (x<0) || (x>3) || (y<0) || (y>3) ) {
		return false;
	} else {
		while ((i<TAILLE) && pos) {
			pos = pos && ( ( _valeur[x][i].val != val ) || ( i == y) );
			++i;
		}
		i = 0;
		while ((i<TAILLE) && pos) {
			pos = pos && ( ( _valeur[i][y].val != val ) || ( i == x) );
			++i;
		}
		if (pos) {
			_valeur[x][y].val = val;
		}
		return pos;
	}
	//fin
}
