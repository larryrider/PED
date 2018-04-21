#ifndef _TCALENDARIO_H_
#define _TCALENDARIO_H_

#include <iostream>
#include <string.h>

using namespace std;

class TCalendario{
	
	friend ostream & operator<<(ostream &, const TCalendario &);
	
	private:
		int dia, mes, anyo;
		char* mensaje;
		
		bool EsBisiesto();
		void CorregirFecha();
		void FechaPorDefecto();
		int DiasMes(const int);
		
	public:
		TCalendario ();
		TCalendario(const int, const int, const int, const char*);
		TCalendario (const TCalendario &); 
		~TCalendario();
		
		TCalendario & operator=(const TCalendario &);

		TCalendario operator+(const int);
		TCalendario & operator++(); //preincremento
		TCalendario operator++(int); //postincremento
		TCalendario operator-(const int);
		TCalendario & operator--(); //preincremento
		TCalendario operator--(int); //postincremento
		
		bool operator ==(const TCalendario &);
		bool operator !=(const TCalendario &);
		bool operator >(const TCalendario &);
		bool operator <(const TCalendario &);
		
		bool ModFecha (const int, const int, const int);
		bool ModMensaje(const char *);
		bool EsVacio();
		int Dia() {return dia;};
		int Mes() {return mes;};
		int Anyo() {return anyo;};
		char *Mensaje() {return mensaje;};

		bool EsCorrecta();
};

#endif