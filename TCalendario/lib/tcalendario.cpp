#include "tcalendario.h"

void TCalendario::FechaPorDefecto(){
	dia=1;
	mes=1;
	anyo=1900;
}

TCalendario::TCalendario(){
	FechaPorDefecto();
	mensaje=NULL;
}

TCalendario::TCalendario(const int d,const int m,const int a,const char* mens){
	mensaje=NULL;

	if (ModFecha(d,m,a)){
		ModMensaje(mens);
	} else{
		FechaPorDefecto();
	}
}

TCalendario::TCalendario(const TCalendario &cal){
	dia=cal.dia;
	mes=cal.mes;
	anyo=cal.anyo;
	mensaje=NULL;
	ModMensaje(cal.mensaje);
}

TCalendario::~TCalendario(){
	FechaPorDefecto();
	
	if(mensaje!=NULL){
		delete[] mensaje;
		mensaje=NULL;
	}
}

bool TCalendario::EsVacio(){
	return (dia==1 && mes==1 && anyo==1900 && mensaje==NULL);
}

bool TCalendario::EsCorrecta(){
	bool correcto;
	if (dia<1 || dia>DiasMes(mes) || mes<1 || mes>12 || anyo<1900){ 
		correcto = false;
	} else{
		correcto = true;
	}
	return correcto;
}

bool TCalendario::EsBisiesto(){
	return (anyo%4==0 && (anyo%400==0 || anyo%100!=0));
}


bool TCalendario::ModFecha(const int d, const int m, const int a){
	bool modificado=false;
	
	TCalendario aux;
	aux.dia=d;
	aux.mes=m;
	aux.anyo=a;

	if (aux.EsCorrecta()){
		modificado=true;
		dia=d;
		mes=m;
		anyo=a;
	}
	return modificado;
}

bool TCalendario::ModMensaje(const char* mens){
	if (mensaje!=NULL){
		delete[] mensaje;
		mensaje=NULL;
	}

	if (mens!=NULL){
		mensaje = new char[strlen(mens)+1];
		strcpy(mensaje, mens);
	}
	return true;
}


TCalendario& TCalendario::operator=(const TCalendario &cal){
	if (this!= &cal){
		(*this).~TCalendario();
		
		dia=cal.dia;
		mes=cal.mes;
		anyo=cal.anyo;
	
		ModMensaje(cal.mensaje);
	}
	return *this;
}

TCalendario TCalendario::operator+(const int num){
	TCalendario auxCal(*this);
	
	if (num>0){
		auxCal.dia = dia + num;
		if (!auxCal.EsCorrecta()){
			auxCal.CorregirFecha();
		}
	}
	return auxCal;
}

TCalendario& TCalendario::operator++(){
	dia++;
	
	if (!EsCorrecta()){
		CorregirFecha();
	}
	return (*this);
}

TCalendario TCalendario::operator++(int postincremento){
	TCalendario auxCal(*this);
	
	dia++;
	
	if (!EsCorrecta()){
		CorregirFecha();
	}
	return auxCal;
}

TCalendario TCalendario::operator-(const int num){
	TCalendario auxCal(*this);
	
	if (num>0){
		auxCal.dia = dia - num;
		auxCal.CorregirFecha();
		if (!auxCal.EsCorrecta()){
			auxCal.~TCalendario();
		}
	}
	return auxCal;
}

TCalendario& TCalendario::operator--(){
	dia--;
	
	CorregirFecha();
	
	if (!EsCorrecta()){
		(*this).~TCalendario();
	}
	return (*this);
}

TCalendario TCalendario::operator--(int postincremento){
	TCalendario auxCal(*this);
	
	dia--;
	CorregirFecha();
	
	if (!EsCorrecta()){
		(*this).~TCalendario();
	}
	return auxCal;
}

int TCalendario::DiasMes(const int mes){
	int dias;
	switch (mes){
		//febrero
		case 2:
			if (EsBisiesto()){
				dias = 29;
			}
			else{
				dias = 28;
			}
			break;
		//30 dias
		case 4:
		case 6:
		case 9:
		case 11:
			dias = 30;
			break;
		//31 dias
		default:
			dias = 31;
			break;
	}
	return dias;
}

void TCalendario::CorregirFecha(){
	bool corregida=false;

	do{
		int diasMes = DiasMes(mes);

		if (dia>=1 && dia<=diasMes){ //fecha bien
			corregida=true;
		} else if (dia<1){ //fecha por debajo
			int diasMesAnt = DiasMes(mes-1);

			dia=dia+diasMesAnt;
			
			if (mes==1){
				mes=12;
				anyo--;
			}
			else{
				mes--;
			}
		} else if (dia>diasMes){ //fecha por arriba
			dia=dia-diasMes;
			if (mes==12){
				mes=1;
				anyo++;
			} else{
				mes++;
			}
		}
	}while (!corregida);
}


bool TCalendario::operator ==(const TCalendario &cal){
	bool iguales=true;

	if (this!=&cal){
		if (cal.dia!=dia || cal.mes!=mes || cal.anyo!=anyo){
			iguales= false;
		} else if (mensaje==NULL && cal.mensaje==NULL){
			iguales= true;
		} else if (mensaje!=NULL && cal.mensaje!=NULL){
			if (strlen(cal.mensaje)==strlen(mensaje)){
				for (unsigned int i=0;i<strlen(mensaje) && iguales;i++){
					if (mensaje[i]!=cal.mensaje[i]){
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

bool TCalendario::operator !=(const TCalendario &cal){
	return !(*this==cal);
}

bool TCalendario::operator<(const TCalendario &cal){
	bool menor;
	if (anyo>cal.anyo){
		menor = false;
	} else if(anyo<cal.anyo){
		menor = true;
	} else if (mes>cal.mes){
		menor = false;
	} else if (mes<cal.mes){
		menor = true;
	} else if (dia>cal.dia){
		menor = false;
	} else if (dia<cal.dia){
		menor = true;
	} else if (mensaje==NULL && cal.mensaje!=NULL){
		menor = true;
	} else if (mensaje==NULL || cal.mensaje==NULL){
		menor = false;
	} else if (strcmp(mensaje,cal.mensaje)>0){
		menor = false;
	} else if (strcmp(mensaje,cal.mensaje)<0){
		menor = true;
	} else {
		menor = false;
	}
	return menor;
}

bool TCalendario::operator>(const TCalendario &cal){
	return (*this!=cal && !(*this<cal));
}

ostream& operator<<(ostream &os, const TCalendario &cal){
	if (cal.dia<10){
		os<<"0";
	}
	os<<cal.dia<<"/";
	
	if (cal.mes<10){
		os<<"0";
	}
	os<<cal.mes<<"/"<<cal.anyo<<" \"";
	
	if (cal.mensaje!=NULL){
		os<<cal.mensaje;
	}
	os<<"\"";

	return os;
}