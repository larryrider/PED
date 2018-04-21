#include <iostream>

using namespace std;

#include "tvectorcalendario.h"


void tad01(){
	TVectorCalendario a, b, c;
	cout << "No hace nada" << endl;
}

void tad02(){
	TVectorCalendario a, b(-3), c(4);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

void tad03(){
	TVectorCalendario a, b(-3), c(4);
	cout << a.Tamano() << endl;
	cout << b.Tamano() << endl;
	cout << c.Tamano() << endl;
	cout << c.Ocupadas() << endl;
}

void tad04(){
	TVectorCalendario a(3), b(3), c;
	TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
	a[1] = ca1;
	a[2] = ca2;
	a[3] = ca3;
	b[1] = ca1;
	b[2] = ca2;
	b[3] = ca3;
	cout << "a=" << a << endl;
	a = b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	a = c;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}

void tad05(){
	TVectorCalendario a(3), b(3), c;
	TCalendario ca1(1,1,2006,(char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
	a[3] = ca3;
	b[1] = ca1;
	b[3] = ca3;
	cout << "a=" << a << endl;
	cout << a.Ocupadas() << endl;
	cout << "b=" << b << endl;
	cout << b.Ocupadas() << endl;
	cout << "c=" << c << endl;
	cout << c.Ocupadas() << endl;
}

void tad06(){
	TVectorCalendario a(3), b(3);
	TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
	a[3] = ca3;
	b[1] = ca1;
	b[3] = ca3;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	if(a.ExisteCal(ca1))
		cout << "Existe" << endl;
	else
		cout << "No existe" << endl;
   
	if(b.ExisteCal(ca1))
		cout << "Existe" << endl;
	else
		cout << "No existe" << endl;
}

void tad07(){
	TVectorCalendario a(3), b(3);
	TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");   
	b[1] = ca1;
	b[2] = ca2;
	b[3] = ca3;   
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	a = b;  
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b.Redimensionar(1);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;   
}

void tad08(){
	TVectorCalendario a(3), b(3);
	TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
	b[1] = ca1;
	b[2] = ca2;
	b[3] = ca3;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	a = b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b.Redimensionar(5);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;  
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
}


int main(){
	pruebasTad();
	return 0;
}