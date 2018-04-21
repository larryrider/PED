#ifndef _TABBCALENDARIO_H_
#define _TABBCALENDARIO_H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"


using namespace std;

class TNodoABB;

class TABBCalendario{

	friend class TNodoABB;
	friend ostream & operator<<(ostream &, const TABBCalendario &);

	private:
		TNodoABB *raiz;
		void InordenAux(TVectorCalendario &, int &) const;
		void PreordenAux(TVectorCalendario &, int &) const;
		void PostordenAux(TVectorCalendario &, int &) const;
		void CopiarAbb(const TABBCalendario &);

	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario &);
		~TABBCalendario();
		
		TABBCalendario & operator=(const TABBCalendario &);
		TABBCalendario operator+(const TABBCalendario &) const;
		TABBCalendario operator-(const TABBCalendario &) const;

		bool operator==(const TABBCalendario &) const;
		
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
		TVectorCalendario Niveles();
		TNodoABB* obtenerNodo(const TCalendario &);

		TListaCalendario examen(const TListaCalendario &);
		bool comprobarHijosNodo(TNodoABB *, TCalendario);
		TListaCalendario InordenLista();
		void InordenListaAux(TListaCalendario &);
};

class TNodoABB{

	friend class TABBCalendario;

	private:
		TCalendario item;
		TABBCalendario iz, de;

	public:
		TNodoABB();
		TNodoABB(const TNodoABB &);
		~TNodoABB();
		TNodoABB & operator=(const TNodoABB &);
};

#endif