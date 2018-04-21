#ifndef TABBPORO_H_
#define TABBPORO_H_

#include <iostream>
#include <queue>
#include "tvectorporo.h"
#include "tlistaporo.h"

using namespace std;

class TNodoABB;

class TABBPoro{
	
	friend ostream & operator <<(ostream &, const TABBPoro &);
	
	private:
		TNodoABB *nodo;
		
		void InordenAux(TVectorPoro &, int &) const;
		void PreordenAux(TVectorPoro &, int &) const;
		void PostordenAux(TVectorPoro &, int &) const;
		
		void Copiar(const TABBPoro &);
		TPoro mayorNodo();
		TNodoABB* getNodo(const TPoro &);
		int getCantidadHijos(const TNodoABB*);
		
	public:
		TABBPoro();
		TABBPoro(const TABBPoro &);
		~TABBPoro();
		
		TABBPoro & operator=(const TABBPoro &);
		bool operator==(const TABBPoro &) const;
		
		bool EsVacio() const{return (nodo == NULL);};
		bool Insertar(const TPoro &);
		bool Borrar(const TPoro &);
		bool Buscar(const TPoro &) const;
		TPoro Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;
		
		TVectorPoro Inorden() const;
		TVectorPoro Preorden() const;
		TVectorPoro Postorden() const;
		TVectorPoro Niveles() const;
		
		TABBPoro operator+(const TABBPoro &);
		TABBPoro operator-(const TABBPoro &);
		
		int* examen(const TListaPoro &);
};

class TNodoABB{

	friend class TABBPoro;

	private:
		TPoro item;
		TABBPoro iz,de;
		
	public:
		TNodoABB();
		TNodoABB(const TNodoABB &);
		~TNodoABB();
		
		TNodoABB & operator=(const TNodoABB &);
};

#endif