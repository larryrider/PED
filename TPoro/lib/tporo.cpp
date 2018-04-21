/*
 * TPoro.cpp
 *
 *  Created on: 03/02/2016
 *      Author: Lawrence Rider Garcia
 */

#include "tporo.h"

ostream& operator<<(ostream &os, const TPoro &tporo) {
	if(!tporo.EsVacio()){
		os.setf(ios::fixed);
		os.precision(2);

		os << "(" << tporo.x << ", " << tporo.y << ") " << tporo.volumen << " ";
		if(tporo.color != NULL){
			os << tporo.color;
		} else{
			os << "-";
		}
	} else{
		os << "()";
	}
	return os;
}

TPoro::TPoro() {
	x = 0;
	y = 0;
	volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, const char* color) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	this->color = NULL;
	Color(color);
}

TPoro::TPoro(const TPoro &tporo) {
	x = tporo.x;
	y = tporo.y;
	volumen = tporo.volumen;
	this->color = NULL;
	Color(tporo.color);
}

TPoro::~TPoro() {
	x = 0;
	y = 0;
	volumen = 0;

	if(color != NULL){
		delete[] color;
		color = NULL;
	}
}

TPoro& TPoro::operator=(const TPoro &tporo) {
	if (this != &tporo){
		(*this).~TPoro();
		x = tporo.x;
		y = tporo.y;
		volumen = tporo.volumen;
		Color(tporo.color);
	}
	return *this;
}

bool TPoro::operator==(const TPoro &tporo){
	bool iguales=true;

	if (this!=&tporo){
		if (tporo.x!=x || tporo.y!=y || tporo.volumen!=volumen){
			iguales= false;
		} else if (color==NULL && tporo.color==NULL){
			iguales= true;
		} else if (color!=NULL && tporo.color!=NULL){
			if (strlen(tporo.color) == strlen(color)){
				for (unsigned int i=0; i < strlen(color) && iguales; i++){
					if (color[i]!=tporo.color[i]){
						iguales= false;
					}
				}
			} else{
				iguales=false;
			}
		} else{
			iguales= false;
		}
	}
	return iguales;
}

bool TPoro::operator!=(const TPoro &tporo){
	return !(*this==tporo);
}

void TPoro::Posicion(int x, int y){
	this->x = x;
	this->y = y;
}

void TPoro::Volumen(double volumen){
	this->volumen = volumen;
}

void TPoro::Color(const char* col) {
	if (color != NULL) {
		delete[] color;
		color = NULL;
	}

	if (col != NULL) {
		color = new char[strlen(col) + 1];
		strcpy(color, col);
		for (unsigned int i=0; i< strlen(color); i++){
			if(color[i]>= 'A' && color[i]<='Z'){
				color[i] = MayusToMinus(color[i]);
			}
		}
	}
}

char TPoro::MayusToMinus(char mayus){
	return mayus-= 'A' - 'a';
}

bool TPoro::EsVacio() const{
	return (x == 0 && y == 0 && volumen == 0 && color == NULL);
}
