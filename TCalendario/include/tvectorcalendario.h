#ifndef _TVECTORCALENDARIO_H_
#define _TVECTORCALENDARIO_H_

#include <iostream>
#include <string.h>
#include "tcalendario.h"

using namespace std;

class TVectorCalendario{
	
	friend ostream & operator<<(ostream &,const TVectorCalendario &);
	
	private:
		TCalendario *c;
		int tamano;
		TCalendario error;
		void CopiarVector(const TVectorCalendario &);

	public:
		TVectorCalendario();
		TVectorCalendario(const int);
		TVectorCalendario(const TVectorCalendario &);
		~TVectorCalendario();
		
		TVectorCalendario & operator=(const TVectorCalendario &);
		
		bool operator==(const TVectorCalendario &);
		bool operator!=(const TVectorCalendario &);

		TCalendario & operator[](int); //izquierda, modificar
		TCalendario operator[](int) const; //derecha (consultar)

		int Tamano(){return tamano;};
		int Ocupadas();
		bool ExisteCal(const TCalendario &);
		void MostrarMensajes(const int,const int,const int);
		bool Redimensionar(const int);
};

#endif