/*
 * TListaPoro.cpp
 *
 *  Created on: 09/03/2016
 *      Author: Lawrence Rider Garcia
 */

#include "tlistaporo.h"


TListaNodo::TListaNodo(): e(){
	anterior = siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &tlistanodo): e(tlistanodo.e){
	anterior = siguiente = NULL;
}

TListaNodo::~TListaNodo(){
	anterior = siguiente = NULL;
}

TListaNodo & TListaNodo::operator=(const TListaNodo &tlistanodo){
	if (this != &tlistanodo){
		(*this).~TListaNodo();
		e = tlistanodo.e;
	}
	return *this;
}


/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/


TListaPosicion::TListaPosicion(){
	pos = NULL;
}

TListaPosicion::TListaPosicion(const TListaPosicion &tpos){
	pos = tpos.pos;
}

TListaPosicion::~TListaPosicion(){
	pos = NULL;
}

TListaPosicion& TListaPosicion::operator=(const TListaPosicion &tpos){
	if (this != &tpos){
		(*this).~TListaPosicion();
		pos = tpos.pos;
	}
	return *this;
}

bool TListaPosicion::operator==(const TListaPosicion &tpos) const{
	return (pos==tpos.pos);
}

TListaPosicion TListaPosicion::Anterior() const{
	TListaPosicion posAux;

	if (pos!=NULL){
		posAux.pos = pos->anterior;
	}
	return posAux;
}

TListaPosicion TListaPosicion::Siguiente() const{
	TListaPosicion posAux;

	if (pos!=NULL){
		posAux.pos = pos->siguiente;
	}
	return posAux;
}

bool TListaPosicion::EsVacia() const{
	return (pos==NULL);
}


/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/

ostream & operator<<(ostream &os, const TListaPoro &tlistaporo){
	os << "(";
	TListaPosicion posActual = tlistaporo.Primera();
	while(!posActual.EsVacia()){
		os << tlistaporo.Obtener(posActual);
		if(!posActual.Siguiente().EsVacia()){
			os << " ";
		}
		posActual = posActual.Siguiente();
	}
	os << ")";
	return os;
}

TListaPoro::TListaPoro(){
	primero = ultimo = NULL;
}

TListaPoro::TListaPoro(const TListaPoro &tlistaporo){
	primero = ultimo = NULL;
	CopiarLista(tlistaporo);
}

void TListaPoro::CopiarLista(const TListaPoro &tlistaporo){
	if (!tlistaporo.EsVacia()){
		TListaPosicion recorrer = tlistaporo.Primera();
		while (!recorrer.EsVacia()){
			Insertar(Obtener(recorrer));
			recorrer = recorrer.Siguiente();
		}
	} else{
		primero = ultimo = NULL;
	}
}

TListaPoro::~TListaPoro(){
	TListaNodo *aux = NULL;

	while (primero!=NULL){
		aux = primero;
		primero = primero->siguiente;
		if (aux!=NULL){
			delete aux;
			aux = NULL;
		}
	}
	primero = ultimo = NULL;
}

TListaPoro & TListaPoro::operator=(const TListaPoro &tlistaporo){
	if (this != &tlistaporo){
		(*this).~TListaPoro();
		CopiarLista(tlistaporo);
	}
	return *this;
}

bool TListaPoro::operator==(const TListaPoro &tlistaporo){
	if (Longitud() != tlistaporo.Longitud()){
		return false;
	} else{
		TListaPosicion recorrer = tlistaporo.Primera();
		TListaPosicion posActual = Primera();

		for (int i=0; i < Longitud(); i++){
			if (Obtener(recorrer) != Obtener(posActual)){
				return false;
			} else{
				recorrer = recorrer.Siguiente();
				posActual = posActual.Siguiente();
			}
		}
		return true;
	}
}

TListaPoro TListaPoro::operator+(const TListaPoro &tlistaporo){
	TListaPoro nueva(*this);

	if (!tlistaporo.EsVacia()){
		TListaPosicion recorrer = tlistaporo.Primera();
		while (!recorrer.EsVacia()){
			nueva.Insertar(Obtener(recorrer));
			recorrer = recorrer.Siguiente();
		}
	}
	return nueva;
}

TListaPoro TListaPoro::operator-(const TListaPoro &tlistaporo){
	TListaPoro nueva(*this);

	if (!tlistaporo.EsVacia()){
		TListaPosicion recorrer = tlistaporo.Primera();
		while (!recorrer.EsVacia()){
			if (Buscar(Obtener(recorrer))){
				nueva.Borrar(Obtener(recorrer));
			}
			recorrer = recorrer.Siguiente();
		}
	}
	return nueva;
}

bool TListaPoro::Insertar(const TPoro &tporo){
	TListaNodo *insertar;

	if (EsVacia()){
		insertar = new TListaNodo();
		insertar->e = tporo;
		primero = insertar;
		ultimo = insertar;
		
		return true;
	}
	else{
		if (!Buscar(tporo)){
			if (tporo.Volumen() < Obtener(Primera()).Volumen()){ //insertar en la primera posicion
				insertar = new TListaNodo();
				insertar->e = tporo;
				insertar->siguiente = Primera().pos;				
				Primera().pos->anterior = primero = insertar;

				return true;
			} else if(tporo.Volumen() >= Obtener(Ultima()).Volumen()){ //insertar en la última posicion
				insertar = new TListaNodo();
				insertar->e = tporo;
				insertar->anterior = Ultima().pos;
				Ultima().pos->siguiente = ultimo = insertar;

				return true;
			} else{
				TListaPosicion posActual, posAnterior;

				posActual = Primera();

				while (!posActual.EsVacia()){
					posAnterior = posActual;
					posActual = posActual.Siguiente();

					if(tporo.Volumen() < (Obtener(posActual)).Volumen()){
						insertar = new TListaNodo();
						insertar->e = tporo;
						insertar->anterior = posAnterior.pos;
						insertar->siguiente = posActual.pos;

						posAnterior.pos->siguiente = insertar;
						posActual.pos->anterior = insertar;
						
						return true;
					} 
				}
			}
		}
		return false;
	}
}

bool TListaPoro::Borrar(const TPoro &tporo){
	if (!EsVacia() && Buscar(tporo)){
		TListaPosicion posActual = Primera();
		
		if (Obtener(posActual) == tporo){ //si el primero de todos es el que hay que borrar
			if (Longitud()==1){
				primero = ultimo = NULL;
			} else{
				primero = primero->siguiente;
				primero->anterior = NULL;
			}
			
			delete posActual.pos;
			return true;
		} else if(Obtener(Ultima()) == tporo){ //si es el último el que hay que borrar
			posActual = Ultima();
			TListaPosicion posAnterior = posActual.Anterior();
			ultimo = posAnterior.pos;
			ultimo->siguiente = NULL;
			
			delete posActual.pos;
			return true;
		} else{
			TListaPosicion posAnterior;
			
			posAnterior = Primera();
			posActual = Primera().Siguiente();
			while(!posActual.EsVacia()){
				if (Obtener(posActual) == tporo){
					posAnterior.pos->siguiente = posActual.pos->siguiente;
					posActual.Siguiente().pos->anterior = posActual.pos->anterior;
					
					delete posActual.pos;
					return true;
				}
				posActual = posActual.Siguiente();
				posAnterior = posAnterior.Siguiente();
			}
		}
	}
	return false;
}

bool TListaPoro::Borrar(const TListaPosicion &tpos){
	return Borrar(Obtener(tpos));
}

TPoro TListaPoro::Obtener(const TListaPosicion &tpos) const{
	TPoro obtenido;

	if(!tpos.EsVacia()){
		obtenido = tpos.pos->e;
	}
	return obtenido;
}

bool TListaPoro::Buscar(const TPoro &tporo) const{
	if(!EsVacia()){
		TListaPosicion posActual = Primera();
		while(!posActual.EsVacia()){
			if (Obtener(posActual) == tporo){
				return true;
			}
			posActual = posActual.Siguiente();
		}
	}
	return false;
}

int TListaPoro::Longitud() const{
	int tamanyo = 0;
	
	TListaPosicion posActual= Primera();
	while(!posActual.EsVacia()){
		tamanyo++;
		posActual = posActual.Siguiente();
	}
	return tamanyo;
}

bool TListaPoro::EsVacia() const{
	return (primero==NULL && ultimo==NULL);
}

TListaPosicion TListaPoro::Primera() const{
	TListaPosicion posActual;

	if(!EsVacia()){
		posActual.pos = primero;
	}
	return posActual;
}

TListaPosicion TListaPoro::Ultima() const{
	TListaPosicion posActual;

	if(!EsVacia()){
		posActual.pos = ultimo;
	}
	return posActual;
}

TListaPoro TListaPoro::ExtraerRango (int n1, int n2){
	TListaPoro nueva;

	if(n1>n2){
		return nueva;
	} else{
		if(n2>Longitud()){
			n2 = Longitud();
		}
		if(n1<=0){
			n1 = 1;
		}

		TListaPosicion posActual= Primera();
		int posicion = 1;
		TListaPosicion aux;
		while(!posActual.EsVacia()){
			if(posicion>=n1 && posicion<=n2){
				aux = posActual.Siguiente();
				nueva.Insertar(Obtener(posActual));
				Borrar(Obtener(posActual));
				posActual = aux;
			} else{
				posActual = posActual.Siguiente();
			}
			posicion++;
		}
		return nueva;
	}
}
