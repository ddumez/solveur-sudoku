#ifndef GRILLE
#define GRILLE

#define TAILLE 4

class grille {
	private :
		struct Case {
			int val;
			bool modif;
		};
		Case _valeur [TAILLE][TAILLE];
		
	public :
		grille();
		~grille();
		bool gagne ();
		void afficher();
		bool jouer (int x, int y, int val);

};

#endif
