#include "tlistacalendario.h"


TNodoCalendario::TNodoCalendario(){
	siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nodo){
	if (this != &nodo){
		siguiente = NULL;
		c = nodo.c;
		siguiente = nodo.siguiente;
	}
}

TNodoCalendario::~TNodoCalendario (){
	siguiente = NULL;
}

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &nodo){
	if (this != &nodo){
		(*this).~TNodoCalendario();
		c = nodo.c;
		siguiente = nodo.siguiente;
	}
	return *this;
}

/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/

TListaCalendario::TListaCalendario(){
	primero=NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &list){
	if (this != &list){
		TListaPos next;
		TListaPos prev;

		primero= new TNodoCalendario(*list.primero);
		prev= list.Primera();
		next= (list.Primera()).Siguiente();

		while (next.pos != NULL){
			prev.Siguiente();
			prev.pos= new TNodoCalendario(*next.pos);
			prev=next;
			next=next.Siguiente();
		}
	}
}

TListaCalendario::~TListaCalendario(){
	TNodoCalendario *aux=NULL;

	while(!EsVacia()){
		aux=primero;
		primero= primero->siguiente;
		if (aux!=NULL){
			delete aux;
			aux=NULL;
		}
	}
}

TListaCalendario & TListaCalendario::operator=(const TListaCalendario &list){
	TListaPos prev;

	if(this != &list){
		(*this).~TListaCalendario();
		prev= list.Primera();
		while(!prev.EsVacia()){
			Insertar(Obtener(prev));
			prev= prev.Siguiente();
		}
	}
}

bool TListaCalendario::operator==(const TListaCalendario &list){
	TListaPos listPrim = list.Primera();
	TListaPos prim = Primera();

	bool salir = false;

	if (list.Longitud()!=Longitud()){
		salir=true;
	}

	while (!salir && !listPrim.EsVacia() && !prim.EsVacia()){
		if (Obtener(listPrim) == Obtener(prim)){
			listPrim = listPrim.Siguiente();
			prim = prim.Siguiente();
		} else{
			salir=true;
		}
	}
	return salir;
}

TListaCalendario TListaCalendario::operator+ (const TListaCalendario &list){
	TListaPos p;
	TListaCalendario tlista;
	
	tlista=*this;
	if (!list.EsVacia()){
		p= list.Primera();
		while (!p.EsVacia()){
			tlista.Insertar(Obtener(p));
			p=p.Siguiente();
		}
	}
	return tlista;
}

TListaCalendario TListaCalendario::operator- (const TListaCalendario &list){
	TListaCalendario tlista(*this);
	TListaPos p;

	while(!p.EsVacia()){
		tlista.Borrar(Obtener(p));
		p = p.Siguiente();
	}
	
	return tlista;
}

bool TListaCalendario::Insertar(const TCalendario &cal){
	bool correcto=false;
	bool encontrado=false;

	if(EsVacia()) {
		TNodoCalendario *nodo=new TNodoCalendario();
		nodo->c=cal;
		primero=nodo;
		correcto=true;
	} else if(!Buscar(cal)){
		TListaPos aux;
		TListaPos prev;
		aux=Primera();

		while(!encontrado && !aux.EsVacia()) {
			if(Obtener(aux)>cal) {
				encontrado=true;
			} else {
				prev=aux;
				aux=aux.Siguiente();
			}
		}
		if(encontrado || prev==Ultima()) {
			if(prev.EsVacia()) {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=aux.pos;
				primero=nodo;
				correcto=true;
			} else if(prev==Ultima()) {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=NULL;
				prev.pos->siguiente=nodo;
				correcto=true;
			} else {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=aux.pos;
				prev.pos->siguiente=nodo;
				correcto=true;
			}
		}
	}
	return correcto;
}

bool TListaCalendario::Borrar(const TCalendario &cal){
	bool correcto=false;
	TListaPos prev=Primera();
	TListaPos aux=Primera();

	if(!EsVacia() && Buscar(cal)) {
		if(Obtener(aux)==cal) {
			primero=primero->siguiente;
			delete aux.pos;
			correcto=true;
		} else {
			aux=aux.Siguiente();
			while(aux.pos!=NULL && !correcto) {
				if(Obtener(aux)==cal) {
					prev.pos->siguiente=aux.pos->siguiente;
					delete aux.pos;
					correcto=true;
				} else {
					aux=aux.Siguiente();
					prev=aux;
				}
			}
		}
	}
	return correcto;
}

bool TListaCalendario::Borrar(const TListaPos &p){
	bool corecto = false;
	
	TListaPos prev, next;
	next= Primera();
	
	if(!EsVacia()){
		if(p==next){
			primero = primero->siguiente;
			delete next.pos;
		} else{
			prev = next;
			next = next.Siguiente();
			
			while(!corecto && !next.EsVacia()){
				if(p==next){
					prev.pos->siguiente = next.pos->siguiente;
					delete next.pos;
					corecto = true;
				} else{
					prev = next;
					next.pos = next.pos->siguiente;
				}
			}
		}
	}
	return corecto;
}

bool TListaCalendario::Borrar(const int dia,const int mes,const int anyo){

	TCalendario c(dia,mes,anyo,"");

	bool salir = false;
	bool correcto = false;
	
	TListaPos prev,next;
	next.pos = primero;
	
	if(!EsVacia()){
		if(c > primero->c){
			primero = primero->siguiente;
			delete next.pos;
			correcto = true;
		} else{
			prev = next;
			next = next.Siguiente();
			
			while(next.pos != NULL){
				if(!salir && c>next.pos->c){
					correcto = true;
					prev.pos->siguiente = next.pos->siguiente;
					delete next.pos;
					prev = next;
					next.pos = next.pos->siguiente;
				} else{
					salir = true;
				}
			}
		}
	}
	return correcto;
}


bool TListaCalendario::EsVacia() const{
	return (primero==NULL);
}

TCalendario TListaCalendario::Obtener(const TListaPos &listapos) const{
	if(!listapos.EsVacia()) {
		return listapos.pos->c;
	}
}

bool TListaCalendario::Buscar(const TCalendario &cal) const{
	bool correcto  = false;

	if (!EsVacia()){
		TListaPos p;
		p.pos=primero;

		while(!correcto && p.pos!=NULL){
			if (p.pos->c == cal){
				correcto=true;
			} else{
				p.pos = p.pos->siguiente;
			}
		}
		/*for (p.pos=primero;p.pos!=NULL && !correcto;p.pos->siguiente){
			if (p.pos->c==c){
				correcto=true;
			}
		}*/
	}
	return correcto;
}

int TListaCalendario::Longitud() const{
	int tamano=0;

	TListaPos lp;
	lp.pos=primero;

	while(lp.pos!=NULL) {
		tamano++;
		lp.pos=lp.pos->siguiente;
	}
	return tamano;
}

TListaPos TListaCalendario::Primera() const{
	TListaPos listapos;

	if(!EsVacia()) {
		listapos.pos=primero;
	}
	return listapos;
}

TListaPos TListaCalendario::Ultima() const{
	TListaPos prev;
	TListaPos aux;
	aux.pos=primero;

	if(!EsVacia()) {
		while(aux.pos!=NULL) {
			prev=aux;
			aux.pos=aux.pos->siguiente;
		}
	}
	return prev;
}

TListaCalendario TListaCalendario::SumarSubl (const int I_L1, const int F_L1, const TListaCalendario &L2, const int I_L2, const int F_L2) {}

TListaCalendario TListaCalendario::ExtraerRango (const int n1, const int n2){}

ostream & operator<<(ostream &os, const TListaCalendario &lista){
	TListaPos aux=lista.Primera();
	
	os<<"<";
	while(!aux.EsVacia()) {
		os << lista.Obtener(aux);
		aux=aux.Siguiente();

		if(!aux.EsVacia()) {
			os << " ";
		}
	}
	os<<">";
	return os;
}

/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/


TListaPos::TListaPos() {
	pos=NULL;
}

TListaPos::TListaPos(const TListaPos &tlistapos) {
	if (this != &tlistapos){
		pos = tlistapos.pos;
	}
}

TListaPos::~TListaPos() {
	pos = NULL;
}

TListaPos & TListaPos::operator=(const TListaPos &tlistapos){
	if (this != &tlistapos){
		pos = tlistapos.pos;
	}
	return *this;
}

bool TListaPos::operator==(const TListaPos &tlistapos) const{
	return (pos == tlistapos.pos);
}

bool TListaPos::operator!=(const TListaPos &tlistapos) const{
	return !(pos == tlistapos.pos);
}

TListaPos TListaPos::Siguiente() const{
	TListaPos aux;

	if (pos!=NULL){
		aux.pos = pos->siguiente;	
	}
	return aux;
}

bool TListaPos::EsVacia() const{
	return (pos == NULL);
}
