/*
 * TVectorPoro.h
 *
 *  Created on: 09/03/2016
 *      Author: Lawrence Rider Garcia
 */

#ifndef TLISTAPORO_H_
#define TLISTAPORO_H_

#include <iostream>
#include "tporo.h"

using namespace std;

class TListaNodo{

	friend class TListaPosicion;
	friend class TListaPoro;
	
	private:
		TPoro e;
		TListaNodo *anterior;
		TListaNodo *siguiente;

	public:
		TListaNodo();
		TListaNodo(const TListaNodo &);
		~TListaNodo();
		TListaNodo & operator=(const TListaNodo &);
};

class TListaPosicion{

	friend class TListaPoro;

	private: 
		TListaNodo *pos;

	public:
		TListaPosicion();
		TListaPosicion(const TListaPosicion &);
		~TListaPosicion();
		
		TListaPosicion& operator=(const TListaPosicion &);
		bool operator==(const TListaPosicion &) const;
		
		TListaPosicion Anterior() const;
		TListaPosicion Siguiente() const;
		bool EsVacia() const;
};

class TListaPoro{

	friend ostream & operator<<(ostream &, const TListaPoro &);
	    
	private:
		TListaNodo *primero;
		TListaNodo *ultimo;
		void CopiarLista(const TListaPoro &);

	public:
		TListaPoro();
		TListaPoro(const TListaPoro &);
		~TListaPoro();

		TListaPoro & operator=(const TListaPoro &);
		bool operator==(const TListaPoro &);
		TListaPoro operator+(const TListaPoro &);
		TListaPoro operator-(const TListaPoro &);

		bool Insertar(const TPoro &);
		bool Borrar(const TPoro &);
		bool Borrar(const TListaPosicion &);
		TPoro Obtener(const TListaPosicion &) const;
		bool Buscar(const TPoro &) const;
		int Longitud() const;
		bool EsVacia() const;
		TListaPosicion Primera() const;
		TListaPosicion Ultima() const;
		TListaPoro ExtraerRango (int n1, int n2);
};

#endif