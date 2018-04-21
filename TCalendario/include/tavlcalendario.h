#ifndef _TAVLCALENDARIO_H_
#define _TAVLCALENDARIO_H_


#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoAVL;


class TAVLCalendario{

	friend class TNodoAVL;
	friend ostream & operator<<(ostream &, const TAVLCalendario &);

	private:
		TNodoAVL *raiz;
		void PreordenAux(TVectorCalendario &, int &) const;
		void PostordenAux(TVectorCalendario &, int &) const;
		void InordenAux(TVectorCalendario &, int &) const;
		void CopiarAVL(const TAVLCalendario &);

	public:
		TAVLCalendario ();
		TAVLCalendario (const TAVLCalendario &);
		~TAVLCalendario ();
		
		TAVLCalendario & operator=(const TAVLCalendario &);
		
		bool operator==(const TAVLCalendario &) const;
		bool operator!=(const TAVLCalendario &) const;
		
		bool EsVacio() const;
		bool Insertar(TCalendario &);
		bool Borrar(const TCalendario &);


		bool Buscar(TCalendario &) const;
		TCalendario Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;

		TVectorCalendario Inorden() const;
		TVectorCalendario Preorden() const;
		TVectorCalendario Postorden() const;
};


class TNodoAVL{

	friend class TAVLCalendario;

	private:
		TCalendario item;
		TAVLCalendario iz, de;
		int fe;

	public:
		TNodoAVL();
		TNodoAVL(const TNodoAVL &);
		~TNodoAVL();
		TNodoAVL & operator=(const TNodoAVL &);
};

#endif