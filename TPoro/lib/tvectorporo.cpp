/*
 * TVectorPoro.cpp
 *
 *  Created on: 02/03/2016
 *      Author: Lawrence Rider Garcia
 */

#include "tvectorporo.h"

ostream& operator<<(ostream &os, const TVectorPoro &tvector){
	os << "[";
	for (int i = 1; i <= tvector.dimension; i++){
		os << i << " " <<tvector[i];

		if (i!=tvector.dimension){
			os << " ";
		}
	}
	os << "]";
}

TVectorPoro::TVectorPoro(): error(){
	datos = NULL;
	dimension = 0;
}

TVectorPoro::TVectorPoro(int dimension): error(){
	if (dimension<=0){
		this->dimension = 0;
		datos = NULL;
	} else{
		this->dimension = dimension;
		datos = new TPoro[dimension];
	}	
}

TVectorPoro::TVectorPoro(const TVectorPoro &tvector): error(tvector.error){
	dimension = tvector.dimension;
	datos = NULL;
	CopiarVector(tvector);
}

TVectorPoro::~TVectorPoro(){
	dimension = 0;
	
	if(datos!=NULL){
		delete[] datos;
		datos = NULL;
	}
}

TVectorPoro & TVectorPoro::operator=(const TVectorPoro &tvector){
	if (this != &tvector){
		(*this).~TVectorPoro();
		CopiarVector(tvector);
	}
	return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &tvector){
	bool iguales = true;

	if (this!=&tvector){
		if (dimension==tvector.dimension){
			for (int i=0;i<dimension && iguales==true;i++){
				if (tvector.datos[i]!=datos[i]){
					iguales=false;
				}
			}
		} else{
			iguales=false;
		}
	}
	return iguales;
}

bool TVectorPoro::operator!=(const TVectorPoro &tvector){
	return !(*this==tvector);
}

TPoro & TVectorPoro::operator[](int posicion){
	if (posicion<=0 || posicion > dimension){
		return error;
	} else{
		return datos[posicion-1];
	}
}

TPoro TVectorPoro::operator[](int posicion) const{
	if (posicion<=0 || posicion > dimension){
		return error;
	} else{
		return datos[posicion-1];
	}
}

int TVectorPoro::Cantidad(){
	int cant = 0;
	
	for (int i = 0; i < dimension; i++){
		if(!datos[i].EsVacio()){
			cant++;
		}
	}
	return cant;
}

bool TVectorPoro::Redimensionar(int redimension){
	bool redimensionado = false;
	if (redimension>0 && redimension != dimension){
		TVectorPoro aux(redimension);

		if(redimension<dimension){
			for (int i = 0; i < redimension; i++){
				aux.datos[i] = datos[i];
			}
		} else{
			for (int i = 0; i < dimension; i++){
				aux.datos[i] = datos[i];
			}
		}
		CopiarVector(aux);
		redimensionado = true;
	}
	return redimensionado;
}

void TVectorPoro::CopiarVector(const TVectorPoro &tvector){
	dimension = tvector.dimension;
	if (datos!=NULL){
		delete[] datos;
		datos = NULL;
	}

	if (dimension>0 && tvector.datos!=NULL){
		datos = new TPoro[dimension];
		for (int i=0; i<dimension; i++){
			datos[i]=tvector.datos[i];
		}
	} else{
		datos = NULL;
	}
}
