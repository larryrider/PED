#include <iostream>

using namespace std;

#include "tcalendario.h"

void tad01(){
	char fi[] = "Fecha incorrecta";
   	char fc[] = "Fecha correcta";
   
	TCalendario cal1(29,2,2006, fi);
	TCalendario cal2(20,11,1880, fi);
	TCalendario cal3(1,12,2006, fc);
	 
	cout<<cal1<<endl;
	cout<<cal2<<endl;
	cout<<cal3<<endl;
}

void tad02(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";

	TCalendario cal1(29,2,2006, fi);
	TCalendario cal2(cal1);
	TCalendario cal3(1,12,2006, fc);
	 
	cout<<cal1<<endl;
	cout<<cal2<<endl;
	cal2=cal3;
	cout<<cal2<<endl;
	cout<<cal3<<endl;
}

void tad03(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
	      
	TCalendario cal1(12,12,2006, fc);
	TCalendario cal2(cal1);
	 
	cout<<cal1<<endl;
	cout<<cal2<<endl;
	cal1.~TCalendario();
	cout<<cal1<<endl;
	cout<<cal2<<endl;
}

void tad04(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
	      
	TCalendario cal1(12,12,2006, fc);
	TCalendario cal2(05,01,1900, fc);
	TCalendario cal4;
	 
	cout<<cal1<<endl;
	cout<<cal2<<endl;
	cout<<cal1+79<<endl;
	cal4=cal2-10;
	cout<<cal2-10<<endl;
	cout<<cal2<<endl;
	cout<<cal4<<endl;
}

void tad05(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
	      
	TCalendario cal1(12,12,2006, fc);
	TCalendario cal2(05,01,1900, fc);
	   
	cal2=cal1++;
	cout<<cal2<<endl;
	cout<<cal1<<endl;
	   
	cal2=++cal1;
	cout<<cal2<<endl;
	cout<<cal1<<endl;
}

void tad06(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
	      
	TCalendario c1(14,12,1966, fc);
	TCalendario c2(19,11,1994, fc);
	TCalendario c3(01,01,1900, fc);
	c2=c1--;
	cout<<c2<<endl;
	cout<<c1<<endl;
	   
	c2=--c1;
	cout<<c2<<endl;
	cout<<c1<<endl;
	   
	c2=--c3;
	cout<<c2<<endl;
}

void tad07(){
	TCalendario c1;

	if (c1.ModFecha(29,02,2006))  
		cout<<"Procedimiento ModFecha correcto"<<endl;
	else
		cout<<"Procedimiento ModFecha incorrecto"<<endl;

	if (c1.ModFecha(1,1,1900))
		cout<<"Procedimiento ModFecha correcto"<<endl;
	else
		cout<<"Procedimiento ModFecha incorrecto"<<endl;

	if (c1.ModFecha(20,10,1800))
		cout<<"Procedimiento ModFecha correcto"<<endl;
	else
		cout<<"Procedimiento ModFecha incorrecto"<<endl;

	if (c1.ModFecha(40,10,1900))
		cout<<"Procedimiento ModFecha correcto"<<endl;
	else
		cout<<"Procedimiento ModFecha incorrecto"<<endl;
}

void tad08(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
		
	TCalendario c1(14,12,1966, fc);
	TCalendario c2(19,11,1994, fc);
	TCalendario c3(01,01,1900, fc);
	TCalendario c4(14,12,1966, fc);

	if (c1==c4)
		cout<<"operador == funciona"<<endl;
	else
		cout<<"operador == no funciona1"<<endl;
	
	if (c2==c3)
		cout<<"operador == no funciona2"<<endl;
	else
		cout<<"operador == funciona"<<endl;

	
	if (c1>c2)
		cout<<"operador > no funciona3"<<endl;
	else 
		cout<<"operador > funciona"<<endl;

	if (c3<c4)
		cout<<"operador < funciona"<<endl;
	else
		cout<<"operador < no funciona4"<<endl;

	if (c1<c4)
		cout<<"operador < no funciona5"<<endl;
	else
		cout<<"operador < funciona"<<endl;

	if (c1>c4)
		cout<<"operador > no funciona6"<<endl;
	else
		cout<<"operador > funciona"<< endl;
	}

	void tad09(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
	char men[] = "Otra fecha correcta";
		
	TCalendario c1(14,12,1966, fc);
	cout << c1 << endl;
	
	c1.ModMensaje(men);
	cout << c1 << endl;
	
	c1.ModMensaje(NULL);
	cout << c1 << endl;
}

void tad10(){
	char fi[] = "Fecha incorrecta";
	char fc[] = "Fecha correcta";
		
	TCalendario c1(14,12,1966, fc);
	
	if (c1.Dia()==14) 
		cout<<"Funcion Dia correcta"<<endl;
	if (c1.Mes()==12) 
		cout<<"Funcion Mes correcta"<<endl;
	if (c1.Anyo()==1966) 
		cout<<"Funcion Anyo correcta"<<endl;     
}

void pruebasTad(){
	cout<<"EMPIEZA EL TAD01:\n";
	tad01();
	cout<<"EMPIEZA EL TAD02:\n";
	tad02();
	cout<<"EMPIEZA EL TAD03:\n";
	tad03();
	cout<<"EMPIEZA EL TAD04:\n";
	tad04();	
	cout<<"EMPIEZA EL TAD05:\n";
	tad05();	
	cout<<"EMPIEZA EL TAD06:\n";
	tad06();	
	cout<<"EMPIEZA EL TAD07:\n";
	tad07();	
	cout<<"EMPIEZA EL TAD08:\n";
	tad08();	
	cout<<"EMPIEZA EL TAD09:\n";
	tad09();	
	cout<<"EMPIEZA EL TAD10:\n";
	tad10();
}

void pruebasMiasRestar(){
	TCalendario pruebo;
	TCalendario prueba1(1,1,2015,NULL);
	cout<<prueba1<<endl;
	prueba1--;
	pruebo=prueba1;
	cout<<pruebo<<endl;

	TCalendario prueba2(1,2,2015,NULL);
	cout<<prueba2<<endl;
	prueba2=prueba2-1;
	cout<<prueba2<<endl;

	TCalendario prueba3(1,3,2015,NULL);
	cout<<prueba3<<endl;
	prueba3=prueba3-1;
	cout<<prueba3<<endl;

	TCalendario prueba4(1,4,2015,NULL);
	cout<<prueba4<<endl;
	prueba4=prueba4-1;
	cout<<prueba4<<endl;

	TCalendario prueba5(1,5,2015,NULL);
	cout<<prueba5<<endl;
	prueba5=prueba5-1;
	cout<<prueba5<<endl;

	TCalendario prueba6(1,6,2015,NULL);
	cout<<prueba6<<endl;
	prueba6=prueba6-1;
	cout<<prueba6<<endl;

	TCalendario prueba7(1,7,2015,NULL);
	cout<<prueba7<<endl;
	prueba7=prueba7-1;
	cout<<prueba7<<endl;

	TCalendario prueba8(1,8,2015,NULL);
	cout<<prueba8<<endl;
	prueba8=prueba8-1;
	cout<<prueba8<<endl;

	TCalendario prueba9(1,9,2015,NULL);
	cout<<prueba9<<endl;
	prueba9=prueba9-1;
	cout<<prueba9<<endl;

	TCalendario prueba10(1,10,2015,NULL);
	cout<<prueba10<<endl;
	prueba10=prueba10-1;
	cout<<prueba10<<endl;

	TCalendario prueba11(1,11,2015,NULL);
	cout<<prueba11<<endl;
	prueba11=prueba11-1;
	cout<<prueba11<<endl;

	TCalendario prueba12(1,12,2015,NULL);
	cout<<prueba12<<endl;
	prueba12=prueba12-1;
	cout<<prueba12<<endl;
}

void pruebasMiasSumar(){
	TCalendario prueba1(31,12,2014,NULL);
	cout<<prueba1<<endl;
	prueba1=prueba1+1;
	cout<<prueba1<<endl;

	TCalendario prueba2(31,1,2015,NULL);
	cout<<prueba2<<endl;
	prueba2=prueba2+1;
	cout<<prueba2<<endl;

	TCalendario prueba3(28,2,2015,NULL);
	cout<<prueba3<<endl;
	prueba3=prueba3+1;
	cout<<prueba3<<endl;

	TCalendario prueba4(31,3,2015,NULL);
	cout<<prueba4<<endl;
	prueba4=prueba4+1;
	cout<<prueba4<<endl;

	TCalendario prueba5(30,4,2015,NULL);
	cout<<prueba5<<endl;
	prueba5=prueba5+1;
	cout<<prueba5<<endl;

	TCalendario prueba6(31,5,2015,NULL);
	cout<<prueba6<<endl;
	prueba6=prueba6+1;
	cout<<prueba6<<endl;

	TCalendario prueba7(30,6,2015,NULL);
	cout<<prueba7<<endl;
	prueba7=prueba7+1;
	cout<<prueba7<<endl;

	TCalendario prueba8(31,7,2015,NULL);
	cout<<prueba8<<endl;
	prueba8=prueba8+1;
	cout<<prueba8<<endl;

	TCalendario prueba9(31,8,2015,NULL);
	cout<<prueba9<<endl;
	prueba9=prueba9+1;
	cout<<prueba9<<endl;

	TCalendario prueba10(30,9,2015,NULL);
	cout<<prueba10<<endl;
	prueba10=prueba10+1;
	cout<<prueba10<<endl;

	TCalendario prueba11(31,10,2015,NULL);
	cout<<prueba11<<endl;
	prueba11=prueba11+1;
	cout<<prueba11<<endl;

	TCalendario prueba12(30,11,2015,NULL);
	cout<<prueba12<<endl;
	prueba12=prueba12+1;
	cout<<prueba12<<endl;
}

void pruebaMayor(){
	char fi[] = " ";
	char fo[] = "";

	TCalendario rafael(1,1,2015,fo);
	TCalendario pepis(1,1,2015,NULL);

	if (pepis<rafael){
		cout<<"\nES MENOR!\n";
	}
	else{
		cout<<"\nES MAYOR!\n";
	}
}

void mostrarCalendario(){
	TCalendario c(1,1,2012,NULL);

	for (int i=0;i<365;i++){
		c++;
		cout<<c;
	}
}

int main() {

	//pruebasMiasRestar();
	//pruebasMiasSumar();
	pruebasTad();
	//pruebaMayor();
	//mostrarCalendario();
}
