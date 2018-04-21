#ifndef _TLISTACALENDARIO_H_
#define _TLISTACALENDARIO_H_

#include <iostream>
#include "tvectorcalendario.h"

using namespace std;


class TNodoCalendario{

	friend class TListaPos;
	friend class TListaCalendario;

	private:
		TCalendario c;
		TNodoCalendario *siguiente;

	public:
		TNodoCalendario ();
		TNodoCalendario (const TNodoCalendario &);
		~ TNodoCalendario ();
		TNodoCalendario & operator=(const TNodoCalendario &);
};

class TListaPos{
	
	friend class TListaCalendario;

	private:
		TNodoCalendario *pos;

	public:
		TListaPos();
		TListaPos(const TListaPos &);
		~TListaPos();

		TListaPos & operator=(const TListaPos &);
		
		bool operator==(const TListaPos &) const;
		bool operator!=(const TListaPos &) const;
		TListaPos Siguiente() const;
		bool EsVacia() const;
};

class TListaCalendario{

	friend ostream & operator<<(ostream &, const TListaCalendario &);

	private:
		TNodoCalendario *primero;

	public:	
		TListaCalendario();
		TListaCalendario(const TListaCalendario &);
		~TListaCalendario();
		TListaCalendario & operator=(const TListaCalendario &);

		bool operator==(const TListaCalendario &);
		TListaCalendario operator+ (const TListaCalendario &);
		TListaCalendario operator-(const TListaCalendario &);

		bool Insertar(const TCalendario &);
		bool Borrar(const TCalendario &);
		bool Borrar (const TListaPos &);
		bool Borrar(const int, const int, const int);

		bool EsVacia() const;
		TCalendario Obtener(const TListaPos &) const;
		bool Buscar(const TCalendario &) const;
		int Longitud() const;
		TListaPos Primera() const;
		TListaPos Ultima() const;
		TListaCalendario SumarSubl (const int,const int,const TListaCalendario &,const int,const int );
		TListaCalendario ExtraerRango (const int, const int);
};

#endif