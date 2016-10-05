#ifndef GRILLE
#define GRILLE

#include "nombre.hpp"
#include <vector>

class Grille {
	private:
		unsigned short int _sudoku [9][9]; //les coordonnées utiliseent dans les nombres vont de 1 à 9 mais dans le tableau elles vont de 0 à 8
		int _score;
		std::vector<Grille *> _fils;

	public:

		#ifdef ASSERTION
			/**
			* @brief constructeur de base du sudoku
			* @param base la liste des chiffres de la grille de départ
			*
			* @pre la grille de départ est valide
			* @post tous les chiffre du vecteur sont dans le tableau sudoku
			*
			* @b complexité : Θ(base.size())
			**/
			Grille ( std::vector<Nombre> base);
		#endif

		/**
		* @brief constructeur de sudoku avec demande a l'utilisateur de la base
		**/
		Grille();

		/**
		* @brief constructeur pour remplir la grille
		* @param pere la grille don est issu celle a construire
		* @param modif le chiffre à ajouter dans la grille
		* 
		* @pre la modification doit etre valide
		* @post la grille est valide
		* 
		* @b complexité : Θ(1) 
		**/
		Grille ( const Grille * const pere, const Nombre & modif);

		/**
		* @brief destructeur de grille, s'appelle recursivement sur ses fils
		*
		* @b complexité : O(nombre d'élément dans l'arborescence de ses fils)
		**/
		~Grille();

		/**
		* @brief accesseur de score
		**/
		int getScore() const;

		/**
		* @brief accesseur du vecteur de fils
		**/
		std::vector<Grille *> getFils () const;

		/**
		* @brief accesseur des numeros dans le sudoku
		* @param x abscisse de la case
		* @param y ordonnée de la case
		* 
		* @pre 0<x<10 && 0<y<10
		* @post retourne la valeur de la case et 0 si elle n'a pas été remplie 
		*
		* @complexité Θ(1)
		**/
		unsigned short int getNombre (int x, int y) const;


		/**
		* @brief affiche la grille dans le terminal
		**/
		void afficher () const;


		/**
		* @brief calcule le score de cette grille
		* @b le score est une valeur approché du nombre de fils possible
		* @b plus le score est petit plus la grille est a privilégié (heuristique éreur d'abord)
		*
		* @pre la grille est valide
		* @post -
		*
		* @b complexité : Θ(1)
		**/
		void genererFils();


	private:
		/**
		* @brief fonction utlisé dans les assertion pour verifier la validité de la grille
		**/
		bool grilleCorecte() const;

		/**
		* @brief calcul le score de la grille
		* @b le score est une valeur aproché du nombre de fils possible
		* @b le score est -2 si la grille est cul-de-sac (case avec aucune possibilité valide)
		* 
		* @pre la grille est valide
		* @post -
		*
		* @b complexité
		**/
		int calculScore() const;

		/**
		* @brief ajaoute des valeurs dans les cases avec une seule possibilité
		*
		* @pre la grille est valide
		* @post la grille est valide
		**/
		void avanceAuto();

};

/**
* @brief opérateur de comparaison des grille 
* @b compare les scores
*
* @pre le score des deux grilles a deja du etre calculé
* @post -
* 
* @b complexité : Θ(1)
**/
bool operator<(const Grille & p, const Grille & q);

/**
* @brief opérateur d'égalité sur les grille
* @b compare si le sudoku est identique
* 
* @pre -
* @post -
* 
* @b complexité : Θ(1)
**/
bool operator==(const Grille & p, const Grille & q);

#endif