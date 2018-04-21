#include <iostream>

using namespace std;

#include "tabbcalendario.h"


void tad01(){
	TABBCalendario a, b;
	
	cout << "No hace nada" << endl;
}

void tad02(){
	TABBCalendario a,c;

	TABBCalendario b(a);
	
	c=b;
	
	cout << "No hace nada" << endl;
}

void tad03(){
	TABBCalendario a,c;

	TCalendario c1(1,1,2011,"Fecha 1");
	TCalendario c2(2,1,2011,"Fecha 2");
	TCalendario c3(3,1,2011,"Fecha 3");

	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	TABBCalendario b(a);
	c=b;
	
	if ( a==b )
		cout << "IGUALES" << endl;
	else 
		cout << "DISTINTOS" << endl;

	if ( c==b )
		cout << "IGUALES" << endl;
	else 
		cout << "DISTINTOS" << endl;
}

void tad04(){
	TABBCalendario a;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");
	TCalendario c6(6,1,2011,"Fecha6");

	a.Insertar(c5);
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	a.Insertar(c6);
	
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
}

void tad05(){
	TABBCalendario a;
	TVectorCalendario vec1, vec2, vec3;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");
	TCalendario c6(6,1,2011,"Fecha6");

	a.Insertar(c5);
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	a.Insertar(c6);

	vec1 = a.Inorden();
	vec2 = a.Preorden();
	vec3 = a.Postorden();

	cout << "Inorden: " << vec1 << endl;
	cout << "Preorden: " << vec2 << endl;
	cout << "Postorden: " << vec3 << endl;
}

void tad06(){
    TABBCalendario a;

    TCalendario c1(1,1,2011,"Fecha1");
    TCalendario c2(2,1,2011,"Fecha2");
    TCalendario c3(3,1,2011,"Fecha3");
    TCalendario c4(4,1,2011,"Fecha4");
    TCalendario c5(5,1,2011,"Fecha5");
    TCalendario c6(6,1,2011,"Fecha6");
    TCalendario c7(7,1,2011,"Fecha7");

    a.Insertar(c5);
    a.Insertar(c2);
    a.Insertar(c1);
    a.Insertar(c3);
    a.Insertar(c6);

    bool busc = a.Buscar(c7);
    if (busc)
	    cout << "Encontrado" << endl;
    else 
	    cout << "No encontrado" << endl;

    bool busc2 = a.Buscar(c1);
    if (busc2)
	    cout << "Encontrado" << endl;
    else 
	    cout << "No encontrado" << endl;
}

void tad07(){
	TABBCalendario a,b;
	TVectorCalendario vec, vec2;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");
	TCalendario c6(6,1,2011,"Fecha6");

	a.Insertar(c5);
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	a.Insertar(c6);


	vec = a.Inorden();
	b = a;
	
	vec2 = b.Inorden();
	if ( vec == vec2 ) 
		{cout << "IGUALES"<< endl;}
	else 
		{cout << "NO IGUALES"<< endl;}

	vec2 = b.Preorden();
	if ( vec == vec2 ) {
		cout << "IGUALES"<< endl;
	} else{
		cout << "NO IGUALES"<< endl;
	}
}

void tad08(){
	TABBCalendario a;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");
	TCalendario c6(6,1,2011,"Fecha6");
	TCalendario c7(7,1,2011,"Fecha7");

	a.Insertar(c5);
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	a.Insertar(c6);

	if(a.Insertar(c7))
		cout << "Insertado" << endl;
	else
		cout << "No insertado" << endl;

	if(a.Insertar(c7))
		cout << "Insertado" << endl;
	else
		cout << "No insertado" << endl;
}

void tad09(){
	TABBCalendario a,b, suma;
	TVectorCalendario vec;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");

	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);

	b.Insertar(c4);
	b.Insertar(c5);

	suma = a+b;

	vec = suma.Inorden();

	cout <<"Inorden Suma: "<< vec << endl; 
}

void tad10(){
	TABBCalendario a,b, resta;
	TVectorCalendario vec;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");

	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);

	b.Insertar(c1);

	resta = a-b;

	vec = resta.Inorden();

	cout <<"Inorden Resta: "<< vec << endl;
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


int main(){
	pruebasTad();
	return 0;
}