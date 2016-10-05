#ifndef NOMBRE
#define NOMBRE

//#define ASSERTION


#ifdef ASSERTION
	#include <cassert>
#endif

class Nombre {
	private:
		unsigned short int _cont;
		unsigned short int _x;
		unsigned short int _y;

	public:
		/**
		* @brief constructeur de nombre
		*
		* @param cont la valeur de la case
		* @param x son abscisse 1 a gauche
		* @param y son ordonne 1 en haut
		* 
		* @pre ces nombres doivent etrent compris entre 1 et 9
		* @post -
		*
		* @b complexité : Θ(1)
		**/
		Nombre(unsigned short int cont, unsigned short int x, unsigned short int y) {
			#ifdef ASSERTION
				assert(cont > 0 && cont < 10 && x > -1 && x < 9 && y > -1 && y < 9); 
			#endif 

			_cont = cont; _x = x; _y = y;
		}

		/**
		* @brief accesseur de la valeur de la case
		**/
		unsigned short int getCont () const { return _cont;}

		/**
		* @brief accesseur de l'abscisse de la case
		**/
		unsigned short int getX () const { return _x;}

		/**
		* @brief accesseur de l'ordonne de la case
		**/
		unsigned short int getY () const { return _y;}
};

/**
* @brief opérateur d'égalité pour les nombres
* @b compare tous les champs
*
* @b complexité : Θ(1)
**/
bool operator==(const Nombre & p, const Nombre & q) {
	return (p.getCont() == q.getCont()) && (p.getX() == q.getX()) && (p.getY() == q.getY()) ;
}

#endif