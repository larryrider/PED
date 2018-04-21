#include "tavlcalendario.h"


TNodoAVL::TNodoAVL(): item(),iz(), de(){
	fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &tnodo): item(tnodo.item),iz(tnodo.iz), de(tnodo.de){
	fe = 0;
}

TNodoAVL::~TNodoAVL(){

}

TNodoAVL & TNodoAVL::operator=(const TNodoAVL &tnodo){
	if (this != &tnodo){
		(*this).~TNodoAVL();
		de = tnodo.de;
		iz = tnodo.iz;
		item = tnodo.item;		
	}
	return *this;
}

/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/

TAVLCalendario::TAVLCalendario(){
	raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &tavl){
	if (tavl.raiz != NULL && this!=&tavl){
		CopiarAVL(tavl);
	} else{
		raiz = NULL;
	}
}

TAVLCalendario::~TAVLCalendario(){
	if (raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

void TAVLCalendario::CopiarAVL(const TAVLCalendario &tavl){
	if (tavl.raiz != NULL){
		TNodoAVL *tnodo = new TNodoAVL();
		tnodo->item = tavl.raiz->item;

		raiz = tnodo;

		(raiz->iz).CopiarAVL(tavl.raiz->iz);
		(raiz->de).CopiarAVL(tavl.raiz->de);
	} else{
		raiz=NULL;
	}
}

TAVLCalendario & TAVLCalendario::operator=(const TAVLCalendario &tavl){
	if (this != &tavl && tavl.raiz != NULL){
		(*this).~TAVLCalendario();
		(*this).CopiarAVL(tavl);
	}
	return (*this);
}

bool TAVLCalendario::operator==(const TAVLCalendario &tavl) const{
	bool iguales = true;

	if (this!=&tavl){
		TVectorCalendario nodos(Nodos());
		TVectorCalendario tavlNodos(tavl.Nodos());

		if (nodos.Tamano() == tavlNodos.Tamano()){
			for (int i=0; i<nodos.Tamano() && iguales;i++){
				for (int j=0; j<tavlNodos.Tamano() && iguales;j++){
					if (nodos[i]!=tavlNodos[j]){
						iguales = false;
					}
				}
			}
		} else{
			iguales = false;
		}
	}
	return iguales;
}

bool TAVLCalendario::operator!=(const TAVLCalendario &tavl) const{
	return !(*this!=tavl);
}

bool TAVLCalendario::TAVLCalendario::EsVacio() const{
	return (raiz==NULL);
}

bool TAVLCalendario::Insertar(TCalendario &tcal){
	bool insertado = false;

	if (raiz==NULL){
		raiz = new TNodoAVL();
		raiz->item=tcal;

		insertado = true;
	} else if (tcal < raiz->item){
		insertado = raiz->iz.Insertar(tcal);
		//insertado = false;
	} else if (tcal > raiz->item){
		insertado = raiz->de.Insertar(tcal);
		//insertado = false;
	} else{
		//insertado = true;
	}
	return insertado;
}

bool TAVLCalendario::Buscar(TCalendario &tcal) const{
	bool encontrado;

	if (raiz==NULL){
		encontrado = false;
	} else if (tcal < raiz->item){
		encontrado = (raiz->iz).Buscar(tcal);
	} else if (tcal > raiz->item){
		encontrado = (raiz->de).Buscar(tcal);
	} else{
		encontrado = true;
	}
	return encontrado;
}

TCalendario TAVLCalendario::Raiz() const{
	TCalendario tcalaux;

	if (!EsVacio()){
		tcalaux=raiz->item;
	}
	return tcalaux;
}

int TAVLCalendario::Altura() const{
	int alturaIzq = 0;
	int alturaDer = 0;
	int altura=0;

	if (raiz!=NULL){
		alturaIzq = (raiz->iz).Altura();
		alturaDer = (raiz->de).Altura();
		if (alturaIzq > alturaDer){
			altura = 1+alturaIzq;
		} else{
			altura = 1+alturaDer;
		}
	}
	return altura;
}

int TAVLCalendario::Nodos() const{
	int nodos = 0;

	if (raiz!=NULL){
		if (raiz->iz.raiz==NULL && raiz->de.raiz==NULL){
			nodos = 1;
		} else{
			nodos = 1+raiz->iz.Nodos() + raiz->de.Nodos();
		}
	}
	return nodos;
}

int TAVLCalendario::NodosHoja() const{
	int nodos = 0;
	if (raiz!=NULL){
		if (raiz->iz.raiz==NULL && raiz->de.raiz==NULL){
			nodos=1;
		} else{
			nodos = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
		}
	}
	return nodos;
}


TVectorCalendario TAVLCalendario::Inorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	InordenAux(tvector,pos);

	return tvector;
}

TVectorCalendario TAVLCalendario::Preorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	PreordenAux(tvector,pos);

	return tvector;
}

TVectorCalendario TAVLCalendario::Postorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	PostordenAux(tvector,pos);

	return tvector;
}

/***PORHACER**/bool TAVLCalendario::Borrar(const TCalendario &){

}

void TAVLCalendario::InordenAux(TVectorCalendario &tvector, int &pos) const{
	if(raiz!=NULL){
		raiz->iz.InordenAux(tvector, pos);
		tvector[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(tvector,pos);
	}
}

void TAVLCalendario::PreordenAux(TVectorCalendario &tvector, int &pos) const{
	if (raiz!=NULL){
		tvector[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(tvector,pos);
		raiz->de.PreordenAux(tvector,pos);
	}
}

void TAVLCalendario::PostordenAux(TVectorCalendario &tvector, int &pos) const{
	if (raiz!=NULL){
		raiz->iz.PostordenAux(tvector,pos);
		raiz->de.PostordenAux(tvector,pos);
		tvector[pos]=Raiz();
		pos++;
	}
}

ostream & operator<<(ostream &os, const TAVLCalendario &tavl){
	
	os << tavl.Inorden();
	return os;
}
