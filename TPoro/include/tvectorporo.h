/*
 * TVectorPoro.h
 *
 *  Created on: 02/03/2016
 *      Author: Lawrence Rider Garcia
 */

#ifndef TVECTORPORO_H_
#define TVECTORPORO_H_

#include <iostream>
#include "tporo.h"

using namespace std;

class TVectorPoro{
	
	friend ostream & operator<<(ostream &, const TVectorPoro &);
	
	private: 
		int dimension;
		TPoro *datos;
		TPoro error;

		void CopiarVector(const TVectorPoro &);
	
	public:
		TVectorPoro();
		TVectorPoro(int);
		TVectorPoro(const TVectorPoro &);
		~TVectorPoro();
		
		TVectorPoro & operator=(const TVectorPoro &);
		
		bool operator==(const TVectorPoro &);
		bool operator!=(const TVectorPoro &);
		
		TPoro & operator[](int);
		TPoro operator[](int) const;
		
		int Longitud(){ return dimension; }
		int Cantidad();
		bool Redimensionar(int);
};

#endif /* TVECTORPORO_H_ */