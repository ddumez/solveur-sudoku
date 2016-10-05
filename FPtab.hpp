/**
 * @file FPtab.hpp
 * @author D.Dumez
 * @since 18/03/2015
 * @brief défini une SDC de file à prioritée
**/

#ifndef __FPtab_HPP__
#define __FPtab_HPP__

#include <vector>

/**
 * @class FP FPtab.hpp
 * @brief défini une SDC de file à prioritée
le sens de priorité est le plus petit d'abord
**/

class FP {
	private :
		std::vector<Grille *> table_ ;
	public :
		/**
		* @brief constructeur par defaut (FP par tas)
		* @pre -
		* @post this.taille() = 0
		*
		* @b complexitée : O(1)
		**/
		FP();
		
		/**
		* @brief destructeur par defaut (FP par tas)
		* @pre -
		* @post la file n'existe plus
		*
		* @b complexitée : O(1)
		**/
		~FP();
		
		/**
		* @brief ajoute un élément à la file de prioritée
		* @b (FP par tas)
		* @param val l'élément à ajouter
		* @pre -
		* @post Ancien.taille() = Après.taille() - 1
		*
		* @b complexitée : O( log(nbElem_) )
		**/
		void enfiler( Grille * val);
		
		/**
		* @brief reconaisseur de FP
		* @b (FP par tas)
		* @pre -
		* @post si la file ne contiend aucun élément alors renvois vrai 
		*
		* @b complexitée : O(1)
		* @return vrai si la file est vide, faux sinon
		**/
		bool estVide() const;
		
		/**
		* @brief renvois le premier élément de la file
		* @b (FP par tas)
		* @pre ! estVide()
		* @post la reponse est plus grande (ou égale, selon l'opérateur de comparaison associée)
		* a tous les élément de la file
		*
		* @b complexitée : O(1)
		* @return le premier (plus petit élément) de la file
		**/
		Grille * premier();
		
		/**
		* @brief retire le plus grand élémnt de la file (le plus grand)
		* @b (FP par tas)
		* @pre !estVide()
		* @post Ancien.taille() = Après.taille() + 1
		*
		* @b complexitée : O( log(nbElem_))
		**/	
		void defiler();
		
		/**
		* @brief renvois le nombre d'élément contenu dans la file
		* @b (FP par tas)
		* @pre -
		* @post -
		*
		* @b complexitée : O(1)
		* @return le nombre d'élément contenu dans la file
		**/
		unsigned int taille() const;
};

#include "FPtab.tpp"

#endif
