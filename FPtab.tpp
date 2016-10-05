#include "FPtab.hpp"
#include "grille.cpp"


FP::FP() {}


FP::~FP() {}


void FP::enfiler(Grille * val) {
	//variable
		int ind = table_.size();
		int i = 0;
		bool flag = true;
	//début
		//recherche d'occurence
			while (i<ind && flag) {
				flag = flag && (!(*val == *(table_.at(i)) ) );
				++i;
			}
		//garanti d'unicité	
			if (flag) {
				table_.push_back(val);
				while ( (ind > 0) && ( *val < *table_[ (ind-1)/2 ]) ) {
					table_[ind] = table_[(ind-1)/2];
					ind = (ind-1)/2;			
				}
				table_[ind] = val;
			}
	//fin
}


void FP::defiler() {
	//variable
		int ind, indg, indd;
		Grille *tmpg, *tmpd;
		int nbElem = table_.size() - 1;
	//début
		table_[0] = table_[nbElem];
		ind = 0;
		indg = 2*ind+1;
		indd = 2*ind+2;
		while (  ( ( indg <= nbElem) && !( *table_[ind] < *table_[indg] ) ) || 
				 ( ( indd <= nbElem) && !( *table_[ind] < *table_[indd] ) ) ) {
			tmpg = table_[indg];
			if ( indd <= nbElem ) {tmpd = table_[indd]; }
			if ( indd > nbElem ) {
				table_[indg] = table_[ind];
				table_[ind] = tmpg;
				ind = indg;
			} else if ( *tmpg < *tmpd) {
				table_[indg] = table_[ind];
				table_[ind] = tmpg;
				ind = indg;
			} else {
				table_[indd] = table_[ind];
				table_[ind] = tmpd;
				ind = indd;
			}
			indg = 2*ind+1;
			indd = 2*ind+2;
		}
		table_.pop_back();
	//fin
}


Grille * FP::premier() {
	return table_[0];
}


bool FP::estVide() const {
	return 0 == table_.size();
}


unsigned int FP::taille() const {
	return table_.size();
}
