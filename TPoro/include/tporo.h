/*
 * TPoro.h
 *
 *  Created on: 03/02/2016
 *      Author: larg1
 */

#ifndef TPORO_H_
#define TPORO_H_

#include <iostream>
#include <string.h>

using namespace std;

class TPoro {

	friend ostream & operator<<(ostream &, const TPoro &);

	private:
		int x, y;
		char* color;
		double volumen;

		char MayusToMinus(char);

	public:
		TPoro();
		TPoro(int, int, double);
		TPoro(int, int, double, const char*);
		TPoro(const TPoro &);
		~TPoro();

		TPoro & operator=(const TPoro &);

		bool operator==(const TPoro &);
		bool operator!=(const TPoro &);

		void Posicion(int, int);
		void Volumen(double);
		void Color(const char *);

		int PosicionX() const {return x;};
		int PosicionY() const {return y;};
		double Volumen() const {return volumen;};
		char* Color() const {return color;};

		bool EsVacio() const;
};

#endif /* TPORO_H_ */