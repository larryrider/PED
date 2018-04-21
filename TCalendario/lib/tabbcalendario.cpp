#include "tabbcalendario.h"


/******************************************************/
/******************************************************/
/*******************EXAMEN*****************************/
/******************************************************/


TListaCalendario TABBCalendario::examen(const TListaCalendario &l) {

	TListaCalendario lista;
	bool salir = false;

	if(l.EsVacia()) {
		//devolver todos los elementos del arbol
		lista = InordenLista();
	} else if(!EsVacio()){
		TListaPos aux = l.Primera();
		lista=InordenLista();//inicializamos lista con el orden total

		for(int i=0; i<l.Longitud() && !salir; i++){
			TCalendario elemento = l.Obtener(aux);

			if(Buscar(elemento)) {
				TNodoABB *nodo = obtenerNodo(elemento);
				
				if(comprobarHijoNodo(nodo->iz.raiz,elemento) || comprobarHijoNodo(nodo->de.raiz,elemento)){
					aux = aux.Siguiente();
					lista.Borrar(elemento); //vamos borrando los calendarios que encontremos por el camino
				} else{
					//devolver todos los elementos del arbol, no se encuentra el camino a traves de los hijos
					salir=true;
				}
			} else{
				//devolver todos los elementos del arbol, no se encuentra el camino a traves de la raiz
				salir=true;
			}
		}
		if (salir==true){ //por si acaso se ha borrado algun calendario de la lista, y al final no ha habido camino, inicializamos la lista de nuevo
			lista = InordenLista();
		}
	}
	
	return lista;
}

bool TABBCalendario::comprobarHijoNodo(TNodoABB *nodo, TCalendario elemento){
	return (nodo->item==elemento);
}

TListaCalendario TABBCalendario::InordenLista(){
	TListaCalendario tlista;
	InordenListaAux(tlista);

	return tlista;
}

void TABBCalendario::InordenListaAux(TListaCalendario &tlista){
	if(raiz!=NULL){
		raiz->iz.InordenListaAux(tlista);
		tlista.Insertar(Raiz());
		raiz->de.InordenListaAux(tlista);
	}
}

TNodoABB* TABBCalendario::obtenerNodo(const TCalendario &tcal){
	TNodoABB* nodo = raiz;

	while(nodo != NULL && nodo->item != tcal){
		if(nodo->item > tcal){
			nodo = nodo->iz.raiz;
		} else{
			nodo = nodo->de.raiz;
		}
	}
	return nodo;
}


/******************************************************/
/******************************************************/
/**********************TNODO***************************/
/******************************************************/

TNodoABB::TNodoABB(): item(),iz(), de(){

}

TNodoABB::TNodoABB(const TNodoABB &tnodo): item(tnodo.item),iz(tnodo.iz), de(tnodo.de){

}

TNodoABB::~TNodoABB(){

}

TNodoABB & TNodoABB::operator=(const TNodoABB &tnodo){
	if (this != &tnodo){
		(*this).~TNodoABB();
		de = tnodo.de;
		iz = tnodo.iz;
		item = tnodo.item;		
	}
	return *this;
}



/******************************************************/
/******************************************************/
/**********************TABB****************************/
/******************************************************/


TABBCalendario::TABBCalendario(){
	raiz = NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &tabb){
	if (tabb.raiz != NULL && this!=&tabb){
		CopiarAbb(tabb);
	} else{
		raiz = NULL;
	}
}

TABBCalendario::~TABBCalendario(){
	if (raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

void TABBCalendario::CopiarAbb(const TABBCalendario &tabb){
	if (tabb.raiz != NULL){
		TNodoABB *tnodo = new TNodoABB();
		tnodo->item = tabb.raiz->item;

		raiz = tnodo;

		(raiz->iz).CopiarAbb(tabb.raiz->iz);
		(raiz->de).CopiarAbb(tabb.raiz->de);
	} else{
		raiz=NULL;
	}
}

TABBCalendario & TABBCalendario::operator=(const TABBCalendario &tabb){
	if (this != &tabb && tabb.raiz != NULL){
		(*this).~TABBCalendario();
		(*this).CopiarAbb(tabb);
	}
	return (*this);
}

TABBCalendario TABBCalendario::operator+(const TABBCalendario &tabb) const{
	TABBCalendario arbol(*this);
	TVectorCalendario vector = tabb.Inorden();

	for (int i=1;i<=vector.Tamano(); i++){
		arbol.Insertar(vector[i]);
	}
	return arbol;
}

TABBCalendario TABBCalendario::operator-(const TABBCalendario &tabb) const{
	TABBCalendario arbol;
	TVectorCalendario vector = Inorden();

	for (int i=1;i<=vector.Tamano(); i++){
		if (!tabb.Buscar(vector[i])){
			arbol.Insertar(vector[i]);
		}
	}
	return arbol;
}

bool TABBCalendario::operator==(const TABBCalendario &tabb) const{
	TVectorCalendario nodos(Nodos());
	TVectorCalendario tabbNodos(tabb.Nodos());

	bool iguales = true;

	if (nodos.Tamano() == tabbNodos.Tamano()){
		for (int i=0; i<nodos.Tamano() && iguales;i++){
			for (int j=0; j<tabbNodos.Tamano() && iguales;j++){
				if (nodos[i]!=tabbNodos[j]){
					iguales = false;
				}
			}
		}
	} else{
		iguales = false;
	}
	return iguales;
}



bool TABBCalendario::EsVacio() const{
	return (raiz==NULL);
}

bool TABBCalendario::Insertar(TCalendario &tcal){
	bool insertado = false;

	if (raiz==NULL){
		raiz = new TNodoABB();
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


bool TABBCalendario::Buscar(TCalendario &tcal) const{
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

TCalendario TABBCalendario::Raiz() const{
	TCalendario tcalaux;

	if (!EsVacio()){
		tcalaux=raiz->item;
	}
	return tcalaux;
}

int TABBCalendario::Altura() const{
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

int TABBCalendario::Nodos() const{
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

int TABBCalendario::NodosHoja() const{
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


TVectorCalendario TABBCalendario::Inorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	InordenAux(tvector,pos);

	return tvector;
}

TVectorCalendario TABBCalendario::Preorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	PreordenAux(tvector,pos);

	return tvector;
}

TVectorCalendario TABBCalendario::Postorden() const{
	int pos = 1;
	TVectorCalendario tvector(Nodos());
	PostordenAux(tvector,pos);

	return tvector;
}

TVectorCalendario TABBCalendario::Niveles(){

}

bool TABBCalendario::Borrar(const TCalendario &tcal){

}

void TABBCalendario::InordenAux(TVectorCalendario &tvector, int &pos) const{
	if(raiz!=NULL){
		raiz->iz.InordenAux(tvector, pos);
		tvector[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(tvector,pos);
	}
}

void TABBCalendario::PreordenAux(TVectorCalendario &tvector, int &pos) const{
	if (raiz!=NULL){
		tvector[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(tvector,pos);
		raiz->de.PreordenAux(tvector,pos);
	}
}

void TABBCalendario::PostordenAux(TVectorCalendario &tvector, int &pos) const{
	if (raiz!=NULL){
		raiz->iz.PostordenAux(tvector,pos);
		raiz->de.PostordenAux(tvector,pos);
		tvector[pos]=Raiz();
		pos++;
	}
}


ostream & operator<<(ostream &os, const TABBCalendario &tabb){
	os << tabb.Inorden();
	return os;
}
