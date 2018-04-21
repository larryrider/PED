#include <iostream>

using namespace std;

#include "tporo.h"

void tad01(){
	TPoro a, b, c;
  	cout << "No hace nada" << endl;
}

void tad02(){
	TPoro a;
  	cout << a << endl;
}

void tad03(){
	TPoro a(1, 2, 3, (char*)"rojo");
	cout << a << endl;
}

void tad04(){
	TPoro a;
 	a.Posicion(10, 20);
  	cout << a << endl;
}

void tad05(){
  	TPoro a(1, 2, 3, (char*)"rojo");
  	TPoro b;
  	b = a;
  	cout << a << endl;
  	cout << b << endl;
}

void tad06(){
  	TPoro a(1, 2, 3, (char*)"rojo");
  	cout << "PosicionX: " << a.PosicionX() << endl;
  	cout << "PosicionY: " << a.PosicionY() << endl;
  	cout << "Volumen: " << a.Volumen() << endl;
}

void tad07(){
  	TPoro a(1, 2, 3, (char*)"rojo");

  	if(a.PosicionX() == 1)
		cout << "SI" << endl;
  	else
		cout << "NO" << endl;

  	if(a.PosicionY() == 2)
		cout << "SI" << endl;
  	else
		cout << "NO" << endl;
}

void tad08(){
  	TPoro a;

  	if(a.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;

  	a.Color((char*)"rojo");

  	if(a.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;
}

void tad09(){
  	TPoro a;

  	if(a.EsVacio())
		cout << "VACIO" << endl;
 	else
		cout << "NO VACIO" << endl;

  	a.Color((char*)"rojo");

  	if(a.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;

  	a.~TPoro();

  	if(a.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;
}

void tad10(){
  	TPoro a, b(0, 0, 0, NULL);
  	TPoro c(a), d(b);

  	if(a.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;

  	if(b.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;

  	if(c.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;

  	if(d.EsVacio())
		cout << "VACIO" << endl;
  	else
		cout << "NO VACIO" << endl;
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

void pruebasMiasIgualdad(){
	TPoro a(1, 2, 3, (char*)"rojo");
	TPoro b(1, 2, 3, (char*)"rojos"); //#comunistas #humor
	if (a==b || b==a)
		cout<< "\nERROR1, los colores son distintos";
	TPoro c(1, 2, 3, NULL);
	TPoro d(1, 2, 3, NULL);
	if (!(c==d && d==c))
		cout<< "\nERROR2, los colores son iguales";
	if(a==c && c==a)
		cout<< "\nERROR3, los colores son distintos";
	TPoro porro(1, 2, 3, (char*)"ROJO");
	if(!(a==porro && porro==a))
		cout<< "\nERROR4, los colores son iguales";
	porro.Color((char*)"rOjO");
	if(!(a==porro && porro==a))
		cout<< "\nERROR5, los colores son iguales";
}

void pruebasMiasDistinto(){
	TPoro a(1, 2, 3, (char*)"rOjO");
	TPoro b(1, 2, 3, (char*)"RoJos");
	if (!(a!=b && b!=a))
		cout<< "\nERROR6, los colores son distintos";
	TPoro c(1, 2, 3, NULL);
	TPoro d(1, 2, 3, NULL);
	if (c!=d && d!=c)
		cout<< "\nERROR7, los colores son iguales";
	if(!(a!=c && c!=a))
		cout<< "\nERROR8, los colores son distintos";
	TPoro porro(1, 2, 3, (char*)"ROJO");
	if(a!=porro && porro!=a)
		cout<< "\nERROR9, los colores son iguales";
	porro.Color((char*)"rOjO");
	if(a!=porro && porro!=a)
		cout<< "\nERROR10, los colores son iguales";
}

void pruebasMiasColor(){
	TPoro a(1, 2, 3, (char*)"pero weno");
	TPoro b;
	
	a.Color(NULL);
	if (a.Color()!=b.Color())
		cout<< "\nERROR11, los dos colores deberian ser null";
	char* xdo = (char*) "PeRoWeNoooooo";
	a.Color(xdo);
	//if (xdo != NULL)
		//delete[] xdo;
	xdo = NULL;
	if(a.Color()==NULL)
		cout<< "\nERROR12, mal mal mal";
}


int main() {
	pruebasTad();
	pruebasMiasIgualdad();
	pruebasMiasDistinto();
	pruebasMiasColor();
}
