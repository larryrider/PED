#include <iostream>

using namespace std;

#include "tabbporo.h"

int main() {
	
	TListaPoro a;
	TABBPoro b;

	TPoro p1(1,1,68,(char *) "rojo");
	TPoro p2(2,2,71,(char *) "verde");
	TPoro p3(3,3,82,(char *) "verde");
	TPoro p4(4,4,92,(char *) "verde");
	TPoro p5(5,5,98,(char *) "verde");
	TPoro p6(5,5,60,(char *) "verde");
	TPoro p7(5,5,50,(char *) "verde");
	TPoro p8(5,5,62,(char *) "verde");
	TPoro p9(5,5,3,(char *) "verde");


	b.Insertar(p1);
	b.Insertar(p2);
	b.Insertar(p3);
	b.Insertar(p4);	
	b.Insertar(p5);
	b.Insertar(p6);
	b.Insertar(p7);	
	b.Insertar(p8);
	b.Insertar(p9);
	
	a.Insertar(p1); //68--2
	a.Insertar(p9);	//3--0
	a.Insertar(p6); //60--2
	a.Insertar(p7); //50--1
	a.Insertar(p8); //62--0
	a.Insertar(p3); //82--1

	//3,50,60,62,68,82
	//0,1,  2,0,  2,1
	
	cout<<endl<<a<<endl;
	
	int* examen = b.examen(a);

	for (int i=0; i<a.Longitud(); i++){
		cout<<examen[i];
	}
	cout<<endl;
}
