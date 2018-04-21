#include "tvectorcalendario.h"

TVectorCalendario::TVectorCalendario(){
	tamano = 0;
	c = NULL;
}

TVectorCalendario::TVectorCalendario(const int tam){
	if (tam<=0){
		tamano = 0;
		c = NULL;
	} else{
		tamano=tam;
		c = new TCalendario[tam];
	}
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario &vector){
	if (this!=&vector){	
		tamano=0;
		c=NULL;
		CopiarVector(vector);
	}
}

TVectorCalendario::~TVectorCalendario(){
	tamano = 0;
	if (c!=NULL){
		delete[] c;
		c=NULL;
	}
}
		
TVectorCalendario & TVectorCalendario::operator=(const TVectorCalendario &vector){
	if (this != &vector){
		(*this).~TVectorCalendario();

		CopiarVector(vector);
	}
	return *this;
}
		
bool TVectorCalendario::operator==(const TVectorCalendario &vector){
	bool iguales = true;
	if (this!=&vector){
		if (tamano==vector.tamano){
			for (int i=0;i<tamano && iguales==true;i++){
				if (vector.c[i]!=c[i]){
					iguales=false;
				}
			}
		} else{
			iguales=false;
		}
	}
	return iguales;
}

bool TVectorCalendario::operator!=(const TVectorCalendario &vector){
	return !(*this==vector);
}

TCalendario & TVectorCalendario::operator[](int indice){
	if (indice>0 && indice<=tamano){
		return c[indice-1];
	} else{
		error = TCalendario();
		return error;
	}
}

TCalendario TVectorCalendario::operator[](int indice) const{
	if (indice>0 && indice<=tamano){
		return c[indice-1];
	} else{
		TCalendario aux;
		return aux;
	}
}

int TVectorCalendario::Ocupadas(){
	int cantidad=0;

	for (int i=0;i<tamano;i++){
		if (!c[i].EsVacio()){
			cantidad++;
		}
	}
	return cantidad;
}

bool TVectorCalendario::ExisteCal(const TCalendario &cal){
	bool existe = false;

	for (int i=0;i<tamano && existe==false;i++){
		if (c[i]==cal){
			existe = true;
		}
	}
	return existe;
}

void TVectorCalendario::MostrarMensajes(const int dia, const int mes, const int anyo){
	char mensaje[] =" ";
	TCalendario aux(dia,mes,anyo,mensaje);
	cout<<"[";
	if (aux.Mensaje()!=NULL){
		for (int i=0;i<tamano;i++){
			if (c[i].Anyo()>=anyo && c[i].Mes()>=mes && c[i].Dia()>=dia){
				cout<<c[i];
				if (i!=tamano-1){
					cout<<", ";
				}
			}
		}
	}
	cout<<"]";
}

void TVectorCalendario::CopiarVector(const TVectorCalendario &vector){
	tamano=vector.tamano;
	if (c!=NULL){
		delete[] c;
		c=NULL;
	}
	if (tamano>0 && vector.c!=NULL){
		c = new TCalendario[tamano];
		for (int i=0;i<tamano;i++){
			c[i]=vector.c[i];
		}
	} else{
		c=NULL;
	}
}

bool TVectorCalendario::Redimensionar(const int redimension){
	bool realizado=false;
	
	if (redimension>0 && redimension!=tamano){
		TVectorCalendario aux(redimension);

		if (redimension<tamano){ //acortar vector
			for (int i=0;i<redimension;i++){
				aux.c[i]=c[i];
			}
		} else{      //alargar vector
			for (int i=0;i<tamano;i++){
				aux.c[i]=c[i];
			}

			for (int i=tamano;i<redimension;i++){
				TCalendario vacio;
				aux.c[i] = vacio;
			}
		}
		
		CopiarVector(aux);
		realizado=true;
	}
	return realizado;
}


ostream& operator<<(ostream &os, const TVectorCalendario &vector){
	os<<"[";
	for (int i=0;i<vector.tamano;i++){
		os<<"("<< i+1 <<") ";

		os<<vector.c[i];

		if (i!=vector.tamano-1){
			os<<", ";
		}
	}
	os<<"]";
}
