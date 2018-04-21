#include "tabbporo.h"

TNodoABB::TNodoABB(): item(), iz(), de(){
	
}

TNodoABB::TNodoABB(const TNodoABB &tnodo): item(tnodo.item), iz(tnodo.iz), de(tnodo.de){
	
}

TNodoABB::~TNodoABB(){
	
}

TNodoABB & TNodoABB::operator=(const TNodoABB &tnodo){
	if(this != &tnodo){
		(*this).~TNodoABB();
		iz = tnodo.iz;
		de = tnodo.de;
		item = tnodo.item;
	}
	return (*this);
}

//////////////////////////////////////////////////////////////

TABBPoro::TABBPoro(){
	nodo = NULL;
}

TABBPoro::TABBPoro(const TABBPoro &tabb){
	Copiar(tabb);
}

TABBPoro::~TABBPoro(){
	if(nodo != NULL){
		delete nodo;
		nodo = NULL;
	}
}

void TABBPoro::Copiar(const TABBPoro &tabb){
	if (tabb.nodo != NULL){
		TNodoABB *tnodo = new TNodoABB();
		tnodo->item = tabb.nodo->item;
		
		nodo = tnodo;
		
		(nodo->iz).Copiar(tabb.nodo->iz);
		(nodo->de).Copiar(tabb.nodo->de);
	} else{
		nodo=NULL;
	}
}

TABBPoro & TABBPoro::operator=(const TABBPoro &tabb){
	if(this != &tabb){
		(*this).~TABBPoro();
		Copiar(tabb);
	}
	return (*this);
}

bool TABBPoro::operator==(const TABBPoro &tabb) const{
	TVectorPoro nodos(Inorden());
	TVectorPoro tabbNodos(tabb.Inorden());
	
	bool encontrado = false;
	
	if(nodos.Cantidad() == tabbNodos.Cantidad()){
		for(int i=0; i<nodos.Cantidad(); i++){
			for(int j=0; j<tabbNodos.Cantidad() && !encontrado; j++){
				if (nodos[i] == tabbNodos[j]){
					encontrado = true;
				}
			}
			if (!encontrado){
				return false;
			} else{
				encontrado = false;
			}
		}
		return true;
	}
	return encontrado;
}

bool TABBPoro::Insertar(const TPoro &tporo){
	bool insertar = false;

	if (nodo == NULL){
		nodo = new TNodoABB();
		nodo->item = tporo;

		insertar = true;
	} else if(!Buscar(tporo)){
		if (tporo.Volumen() < nodo->item.Volumen()){
			insertar = nodo->iz.Insertar(tporo);
		} else if(tporo.Volumen() > nodo->item.Volumen()){
			insertar = nodo->de.Insertar(tporo);
		}
	} else{
		return false;
	}
	return insertar;
}

bool TABBPoro::Borrar(const TPoro &tporo){
	bool borrar;

	if (Buscar(tporo)){
		if (nodo->item == tporo){
			if(nodo->iz.nodo==NULL && nodo->de.nodo==NULL){
				delete nodo;
				nodo = NULL;
			} else if(nodo->iz.nodo==NULL){
				TNodoABB *derecha = nodo->de.nodo;
				TNodoABB *nodoAux = nodo;
				
				nodo = derecha;
				
				nodoAux->iz.nodo = nodoAux->de.nodo = NULL;
				delete nodoAux;
			} else if(nodo->de.nodo==NULL){
				TNodoABB *izquierda = nodo->iz.nodo;
				TNodoABB *nodoAux = nodo;
				
				nodo = izquierda;

				nodoAux->iz.nodo = nodoAux->de.nodo = NULL;
				delete nodoAux;
			} else{ //Sustituir por mayor de la izquierda
				TPoro mayorIzquierda = nodo->iz.mayorNodo();
				Borrar(mayorIzquierda);
				nodo->item = mayorIzquierda;
			}
			borrar = true;
		} else if(tporo.Volumen() < nodo->item.Volumen()){
			borrar = (nodo->iz).Borrar(tporo);
		} else if(tporo.Volumen() > nodo->item.Volumen()){
			borrar = (nodo->de).Borrar(tporo);
		} else{
			borrar = false; //(?) por si algun error extraño
		}
	} else{
		borrar = false;
	}
	return borrar;
}

TPoro TABBPoro::mayorNodo(){
	TNodoABB *recorrer = nodo;
	while(recorrer->de.nodo!=NULL){
		recorrer = recorrer->de.nodo;
	}

	TPoro mayor(recorrer->item);
	return mayor;
}

bool TABBPoro::Buscar(const TPoro &tporo) const{
	bool encontrado = false;

	if (nodo == NULL){
		encontrado = false;
	} else if (nodo->item == tporo){
		encontrado = true;
	} else if(tporo.Volumen() < nodo->item.Volumen()){
		encontrado = (nodo->iz).Buscar(tporo);
	} else if(tporo.Volumen() > nodo->item.Volumen()){
		encontrado = (nodo->de).Buscar(tporo);
	} else{
		encontrado = false;
	}
	return encontrado;
}

TPoro TABBPoro::Raiz() const{
	TPoro tporo;

	if(nodo != NULL){
		tporo = nodo->item;
	}
	return tporo;
}

int TABBPoro::Altura() const{
	int izquierda=0, derecha=0, total=0;

	if(nodo!= NULL){
		izquierda = (nodo->iz).Altura();
		derecha = (nodo->de).Altura();
		if(izquierda > derecha){
			total = 1 + izquierda;
		} else{
			total = 1 + derecha;
		}
	}
	return total;
}

int TABBPoro::Nodos() const{
	int nodos = 0;

	if (nodo != NULL){
		nodos = 1 + (nodo->iz).Nodos() + (nodo->de).Nodos();
	}
	return nodos;
}

int TABBPoro::NodosHoja() const{
	int nodos = 0;
	
	if (nodo != NULL){
		if((nodo->iz).nodo == NULL && (nodo->de).nodo == NULL){
			nodos = 1;
		} else{
			nodos = (nodo->iz).NodosHoja() + (nodo->de).NodosHoja();
		}
	}
	return nodos;
}

TVectorPoro TABBPoro::Inorden() const{
	int pos = 1;
	TVectorPoro tvector(Nodos());
	InordenAux(tvector, pos);

	return tvector;
}

TVectorPoro TABBPoro::Preorden() const{
	int pos = 1;
	TVectorPoro tvector(Nodos());
	PreordenAux(tvector, pos);

	return tvector;
}

TVectorPoro TABBPoro::Postorden() const{
	int pos = 1;
	TVectorPoro tvector(Nodos());
	PostordenAux(tvector, pos);

	return tvector;
}

void TABBPoro::InordenAux(TVectorPoro &tvector, int &pos) const{
	if (nodo != NULL){
		(nodo->iz).InordenAux(tvector, pos);
		tvector[pos] = Raiz();
		pos++;
		(nodo->de).InordenAux(tvector,pos);
	}
}

void TABBPoro::PreordenAux(TVectorPoro &tvector, int &pos) const{
	if (nodo != NULL){
		tvector[pos] = Raiz();
		pos++;
		(nodo->iz).PreordenAux(tvector, pos);
		(nodo->de).PreordenAux(tvector,pos);
	}
}

void TABBPoro::PostordenAux(TVectorPoro &tvector, int &pos) const{
	if (nodo != NULL){
		(nodo->iz).PostordenAux(tvector, pos);
		(nodo->de).PostordenAux(tvector,pos);
		tvector[pos] = Raiz();
		pos++;
	}
}

TVectorPoro TABBPoro::Niveles() const{
	/*algoritmo niveles ( a : arbin )
		var c: cola de arbin; aux: arbin; fvar
		encolar(c, a)
		mientras no esvacia(c) hacer
		aux := cabeza(c)
		escribe (raiz(aux))
		desencolar(c)
		si no esvacio(hijoiz(aux)) entonces encolar(c, hijoiz(aux))
		si no esvacio(hijode(aux)) entonces encolar(c, hijode(aux))
		fmientras
		falgoritmo*/
	int i = 1;
	TVectorPoro tvector(Nodos());
	queue<TABBPoro> cola;
	TABBPoro tabbporo = *this;

	if(!EsVacio()){
		cola.push(tabbporo);
	}

	while(!cola.empty()){
		tabbporo = cola.front();
		cola.pop();
		
		tvector[i] = tabbporo.Raiz();
		i++;

		if(!tabbporo.nodo->iz.EsVacio()){
			cola.push(tabbporo.nodo->iz);
		}
		if(!tabbporo.nodo->de.EsVacio()){
			cola.push(tabbporo.nodo->de);
		}
	}
	return tvector;	
}

TABBPoro TABBPoro::operator+(const TABBPoro &tabb){
	TABBPoro copia(*this);
	TVectorPoro tvector(tabb.Inorden());

	for(int i=1; i<tvector.Longitud(); i++){ //longitud o cantidad
		copia.Insertar(tvector[i]);
	}
	return copia;
}

TABBPoro TABBPoro::operator-(const TABBPoro &tabb){
	TABBPoro result;
	TVectorPoro tvector(Inorden());

	for(int i=1; i<tvector.Longitud(); i++){
		if(!tabb.Buscar(tvector[i])){
			result.Insertar(tvector[i]);
		}
	}
	return result;
}

ostream & operator <<(ostream &os, const TABBPoro &tabb){
	os << tabb.Niveles();
	return os;
}


int* TABBPoro::examen(const TListaPoro &tlista){
	int* vector;
	
	if(EsVacio()){
		vector = new int[tlista.Longitud()];
		
		for(int i=0; i<tlista.Longitud(); i++){
			vector[i] = 0;
		}
	} else if(tlista.EsVacia()){
		vector = NULL;
	} else{
		TListaPosicion posActual = tlista.Primera();
		vector = new int[tlista.Longitud()];
		int i = 0;
		while(!posActual.EsVacia()){
			TPoro obtenido = tlista.Obtener(posActual);
			if(tlista.Buscar(obtenido)){
				TNodoABB* nodo = getNodo(obtenido);
				vector[i] = getCantidadHijos(nodo);
			} else{
				vector[i] = 0;
			}
			
			posActual = posActual.Siguiente();
			i++;
		}
	}
	return vector;
}

TNodoABB* TABBPoro::getNodo(const TPoro &tporo) {
	if(!EsVacio()) {
		if(tporo.Volumen() == nodo->item.Volumen()){
			return nodo;
		} else if(tporo.Volumen() < nodo->item.Volumen()){
			nodo->iz.getNodo(tporo);
		} else {
			nodo->de.getNodo(tporo);
		}
	} else{
		return NULL;
	}
}

int TABBPoro::getCantidadHijos(const TNodoABB* tnodo){
	int cantidad = 0;
	if(tnodo != NULL){
		if(tnodo->iz.nodo != NULL){
			cantidad++;
		}
		
		if(tnodo->de.nodo != NULL){
			cantidad++;
		}
	}
	return cantidad;
}