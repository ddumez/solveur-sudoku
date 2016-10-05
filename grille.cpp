#ifdef ASSERTION
	#include <cassert>
#endif

#include "grille.hpp"
#include <string>

using namespace std;

#ifdef ASSERTION
	Grille::Grille ( std::vector<Nombre> base) {
		//début

			for (int i = 0; i<9; ++i) {
				for (int j = 0; j<9; ++j) {
					_sudoku[i][j] = 0;
				}
			}
			for (Nombre tmp : base) {
				_sudoku[tmp.getX()][tmp.getY()] = tmp.getCont();
			}

			//avancé automatique pour les cases avec un unique choix
				avanceAuto();

			//calcul du score
				_score = calculScore();


			#ifdef ASSERTION
				assert(grilleCorecte());
			#endif
		//fin
	}
#endif

Grille::Grille () {
	//variable
		string ligne;
	//début
		cout<<"écrivez la grille de sudoku avec des 0 pour les cases a remplir \n"<<endl;
		for(int j = 0; j<9; ++j) {
			cin>>ligne;
			for(int i = 0; i<9; ++i) {
				_sudoku[i][j] = (int)(ligne.at(i)) - 48;
			}
			ligne.clear();
		}

			#ifdef ASSERTION
				assert(grilleCorecte());
			#endif

			//avancé automatique pour les cases avec un unique choix
				avanceAuto();

			//calcul du score
				_score = calculScore();


			#ifdef ASSERTION
				assert(grilleCorecte());
			#endif
	//fin
}


Grille::Grille ( const Grille * const pere, const Nombre & modif) {
#ifdef ASSERTION
	assert(pere->_sudoku[modif.getX()][modif.getY()] == 0);
#endif
	//début
		//recopie du sudoku
		for (int i = 0; i<9; ++i) {
			for (int j = 0; j<9; ++j) {
				_sudoku[i][j] = pere->_sudoku[i][j];
			}
		}

		//ajout du nouveau coup
		_sudoku[modif.getX()][modif.getY()] = modif.getCont();

		
		//avancé automatique pour les cases avec un unique choix
			avanceAuto();

		//calcul du score
		_score = calculScore();
	//fin

#ifdef ASSERTION	
	assert(grilleCorecte());
#endif
}


Grille::~Grille() {
	for (Grille * parc : _fils) {
		delete(parc);
	}
}

int Grille::getScore() const {return _score;}


std::vector<Grille *> Grille::getFils() const {return _fils;}


unsigned short int Grille::getNombre (int x, int y) const {
	#ifdef ASSERTION
		assert (x>-1 && x<9 && y>-1 && y<9);
	#endif

	return _sudoku[x][y];
}


void Grille::afficher() const {
	//début
		for (int j = 0; j<9; ++j) {
			for (int i = 0; i<9; ++i) {
				cout<<_sudoku[i][j]<<" ";
			}
			cout<<"\n";
		}
	//fin
}


void Grille::genererFils() {
	//variable
		bool possible [9];
		int ifin, jfin;
		Nombre * tmpN;
		Grille * Nfils;
	//début
		for(int x = 0; x<9; ++x) {
			for(int y = 0; y<9; ++y) {
				if (_sudoku[x][y] == 0) { //cette case est vide
					//reinitialisation du tableau des chiffres possibles
						for (int i = 0; i<9; ++i) {possible[i] = true;}

					//enlever les  numero non possible dans cette case
						//trouver les numero non present dans la ligne
							for(int i = 0; i<9; ++i) {
								if (_sudoku[i][y] != 0) {
									possible[_sudoku[i][y] - 1] = false;
								}
							}
						//trouver les numero non present dans la colone
							for(int j = 0; j<9; ++j) {
								if (_sudoku[x][j] != 0) {
									possible[_sudoku[x][j] - 1] = false;	
								}
							}
						//trouver les numero non present dans le bloc
							ifin = 3*(int)(x/3) + 3;
							jfin = 3*(int)(y/3) + 3;
							for(int i = ifin - 3; i<ifin; ++i) {
								for(int j = jfin - 3; j<jfin; ++j) {
									if (_sudoku[i][j] != 0) {
										possible[_sudoku[i][j] - 1] = false;
									}
								}
							}

					//générer les fils en conséquence
						for(int i = 0; i<9; ++i) {
							if (possible[i]) {
								tmpN = new Nombre(i+1, x, y);
								Nfils = new Grille(this, *tmpN);
								delete(tmpN);
								if (Nfils->getScore() < 0) {
									//cul-de-sac à ne pas traiter
									delete(Nfils);
								} else {
									_fils.push_back(Nfils);
								}
							}
						}
				}
			}
		}
	//fin
}


bool operator<(const Grille & p, const Grille & q) {
	return p.getScore() < q.getScore();
}


bool operator==(const Grille & p, const Grille & q) {
	//variable
		bool flag = true;
		int i,j;
	//début
		i = 0;
		while (flag && (i<9) ) {
			j = 0;
			while (flag && (j<9) ) {
				flag = flag && ( p.getNombre(i,j) == q.getNombre(i,j) );
				++j;
			}
			++i;
		}
	//fin
	return flag;
}


bool Grille::grilleCorecte () const {
	//variable
		bool flag = true;
		int x,y,i,j,ifin,jfin;
	//début
		x = 0;
		while (flag && (x<9)) {
			y = 0;
			while (flag && (y<9)) {
				if (_sudoku[x][y] != 0) {
					//verifier si le numero n'est pas present dans la ligne
						i = 0;
						while (flag && (i<9)) {
							if (i != x) {
								flag = ( flag && (_sudoku[x][y] != _sudoku[i][y]) );
							}
							++i;
						}
					//verifier si le numero n'est pas present dans la colone
						j = 0;
						while (flag && (j<9)) {
							if (j != y) {
								flag = ( flag && (_sudoku[x][y] != _sudoku[x][j]) );
							}
							++j;
						}
					//verifier si le numero n'est pas present dans le bloc
						i = 3*(int)(x/3);
						ifin = i + 3;
						jfin = 3*(int)(y/3) + 3;
						while (flag && i<ifin) {
							j = jfin - 3;
							while (flag && j<jfin) {
								if (i != x && j != y) {
									flag = ( flag && (_sudoku[x][y] != _sudoku[i][j]));
								}
								++j;
							}
							++i;
						}
				}
				++y;
			}
			++x;
		}
	//fin
	return flag;
}

int Grille::calculScore () const {
	//variable
		bool possible [9];
		int ifin, jfin;
		int score = 0;
		bool flag = true;
		int x,y;
	//début
		x = 0;
		while(x<9 && flag) {
			y = 0;
			while(y<9 && flag) {
				if (_sudoku[x][y] == 0) { //cette case est vide
					//reinitialisation du tableau des possible
						for (int i = 0; i<9; ++i) {possible[i] = true;}

					//enlever les  numero non possible dans cette case
						//trouver les numero non present dans la ligne
							for(int i = 0; i<9; ++i) {
								if (_sudoku[i][y] != 0) {
									possible[_sudoku[i][y] - 1] = false;
								}
							}
						//trouver les numero non present dans la colone
							for(int j = 0; j<9; ++j) {
								if (_sudoku[x][j] != 0) {
									possible[_sudoku[x][j] - 1] = false;	
								}
							}
						//trouver les numero non present dans le bloc
							ifin = 3*(int)(x/3) + 3;
							jfin = 3*(int)(y/3) + 3;
							for(int i = ifin - 3; i<ifin; ++i) {
								for(int j = jfin - 3; j<jfin; ++j) {
									if (_sudoku[i][j] != 0) {
										possible[_sudoku[i][j] - 1] = false;
									}
								}
							}

					//incrementation du nombre de possibilité
						flag = false;
						for (int i = 0; i<9; ++i) {
							flag = flag || possible[i]; //verification si la case n'a aucune possibilité
							if (possible[i]) { ++score;}
						}
						
				}
				++y;
			}
			++x;
		}

		if (!flag) {score = -2;} //une case n'a aucune possibilité

	//fin
	return score;
}

void Grille::avanceAuto() {
	#ifdef ASSERTION
		assert(grilleCorecte());
	#endif
		//variable
			bool possible[9];
			int NBpossibilite;
			int cont;
			bool flag, dejaPresent;
			int ifin, jfin;

		//début
		do {
			flag = false;

			for(int x = 0; x<9; ++x) {
				for(int y = 0; y<9; ++y) {
					if (_sudoku[x][y] == 0) { //cette case est vide
						//reinitialisation du tableau des chiffres possibles
							for (int i = 0; i<9; ++i) {possible[i] = true;}

						//enlever les  numero non possible dans cette case
							//trouver les numero present dans la ligne
								for(int i = 0; i<9; ++i) {
									if (_sudoku[i][y] != 0) {
										possible[_sudoku[i][y] - 1] = false;
									}
								}
							//trouver les numero present dans la colone
								for(int j = 0; j<9; ++j) {
									if (_sudoku[x][j] != 0) {
										possible[_sudoku[x][j] - 1] = false;	
									}
								}
							//trouver les numero present dans le bloc
								ifin = 3*(int)(x/3) + 3;
								jfin = 3*(int)(y/3) + 3;
								for(int i = ifin - 3; i<ifin; ++i) {
									for(int j = jfin - 3; j<jfin; ++j) {
										if (_sudoku[i][j] != 0) {
											possible[_sudoku[i][j] - 1] = false;
										}
									}
								}

						//voir si il n'y a que une seule possibilité
							NBpossibilite = 0;
							for (int i = 0; i<9; ++i) {
								if (possible[i]) {++NBpossibilite;}
							}

						//si c'est le cas on l'applique
							if (NBpossibilite == 1) {
								cont = 0;
								while (!possible[cont]) {++cont;}
								_sudoku[x][y] = cont+1;
								flag = true; //il faudra refaire une passe
							}
					}
				}
			}

			//completion de la grille par bloc
			for(int ibloc = 0; ibloc<3; ++ibloc) { //parcour des ligne de bloc
				for(int jbloc = 0; jbloc<3; ++jbloc){ //parcour des colones de bloc
					for(int nb = 1; nb<10; ++nb) { //parcour des numero
						//test si le numero est deja dans le bloc
							dejaPresent = false;
							for (int i = 3*ibloc; i < 3*ibloc +3; ++i) {
								for(int j = 3*jbloc; j<3*jbloc +3; ++j ) {
									dejaPresent = ((_sudoku[i][j] == nb) || dejaPresent) ;
								}
							}

						//si il n'y est pas recherche des cases ou il peut etre
							if (! dejaPresent) {
								for(int ind =0; ind<9; ++ind) {possible[ind] = true;}

								for(int i = 0; i<3 ; ++i) {
									for(int j = 0; j<3 ; ++j) {
										//trouver les numero present dans la ligne
											for(int ii = 0; ii<9; ++ii) {
												if (_sudoku[ii][j+3*jbloc] == nb) {
													possible[i+j] = false;
												}
											}
										//trouver les numero present dans la colone
											for(int jj = 0; jj<9; ++jj) {
												if (_sudoku[i + 3*ibloc][jj] == nb) {
													possible[i+j] = false;	
												}
											}
									}
								}

							//voir si il n'y a que une seule possibilité
								NBpossibilite = 0;
								for (int ii = 0; ii<9; ++ii) {
									if (possible[ii]) {++NBpossibilite;}
								}

							//si il n'y a que une seule possibilité on l'applique
								if (NBpossibilite == 1) {
									for(int i = 3*ibloc; i<3*ibloc +3; ++i) {
										for(int j = 3*jbloc; j<3*jbloc +3; ++j) {
											if (possible[i+j -3*ibloc -3*jbloc]) {
												_sudoku[i][j] = nb;
												flag = true;//il faudra refaire une passe
											}
										}
									}
								}

							}
					}
				}
			}


		} while(flag);
		//fin
	#ifdef ASSERTION
		assert(grilleCorecte());
	#endif
}