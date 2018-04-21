#include <iostream> 

using namespace std;

#include "tvectorporo.h"

void tad01(){
	TPoro a, b, c;
	TVectorPoro d, e, f;

  	cout << "No hace nada" << endl;	
}

void tad02(){
 	TPoro auxOK;
 	TVectorPoro a, b(5), c(10);

  	cout << a.Longitud() << endl;
  	cout << b.Longitud() << endl;
  	cout << c.Longitud() << endl;
}

void tad03(){
	TVectorPoro a;

  	cout << a << endl;
}

void tad04(){
  	TVectorPoro a(5);
  	TVectorPoro b;

  	if(a == b)
		cout << "SI"  << endl;
  	else
		cout << "NO" << endl;	
}

void tad05(){
	TPoro a(1, 2, 3, (char*)"rojo");
	TVectorPoro v(5);

	v[1] = a;
	v[2] = a;
	v[3] = a;
	v[4] = a;
	v[5] = a;

	cout << v << endl;	
}

void tad06(){
  	TPoro a(1, 2, 3, (char*)"rojo");
  	TVectorPoro v(5), w;

  	v[1] = a;
  	v[2] = a;
  	v[3] = a;
  	v[4] = a;
  	v[5] = a;

  	w = v;

  	cout << v << endl;
  	cout << w << endl;	
}

void tad07(){
  	TPoro a(1, 2, 3, (char*)"rojo");
  	TVectorPoro v(5);

  	cout << "Cantidad: " << v.Cantidad() << endl;

  	v[1] = a;
  	cout << "Cantidad: " << v.Cantidad() << endl;

  	v[2] = a;
  	cout << "Cantidad: " << v.Cantidad() << endl;

  	v[3] = a;
  	cout << "Cantidad: " << v.Cantidad() << endl;

 	v[4] = a;
  	cout << "Cantidad: " << v.Cantidad() << endl;

  	v[5] = a;
  	cout << "Cantidad: " << v.Cantidad() << endl;	
}

void tad08(){
  	TPoro a(1, 2, 3, (char*)"rojo");
  	TVectorPoro v(5), w;

  	cout << "Longitud: " << v.Longitud() << endl;
  	cout << "Longitud: " << w.Longitud() << endl;

  	w = v;

  	cout << "Longitud: " << v.Longitud() << endl;
  	cout << "Longitud: " << w.Longitud() << endl;	
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

void pruebasMias(){
	TPoro a(1, 2, 3, (char*)"rojo");
	TPoro vacio;
	TVectorPoro v(-1), w;
	
	if (!(v == w)){
		cout <<"\n\n1ERROR, v y w son iguales";
		
	}
	if (v != w){
		cout <<"\n\n2ERROR, v y w son iguales";
		
	}
	if (v.Longitud() != 0){
		cout <<"\n\n3ERROR, v tiene longitud 0";
	}

	TVectorPoro vectorsillo(3);

	w = vectorsillo;

	for (int i=1; i<=w.Longitud(); i++){
		w[i] = a;
	}

	for (int i=1; i<=w.Longitud(); i++){
		w[i] = w[i]; //para comprobar que funcionen los dos operadores []
	}

	if (w.Cantidad() != 3)
		cout <<"\n\n4ERROR, w tiene 3 poros";
	
	for (int i=1; i<=w.Longitud(); i++){
		if (w[i]!= a){
			cout <<"\n\n5ERROR, w[i] tiene que ser a";
		}
	}

	if (w.Redimensionar(0) || w.Redimensionar(-1)){
		cout<<"\n\n6ERROR, no se puede redimensionar";
	}
		
	bool jeje = w.Redimensionar(6);
	
	if (!jeje)
		cout<<"\n\n7ERROR, si se puede redimensionar";
	else{	
		if (w.Longitud()!=6)
			cout<<"\n\n8ERROR, la longitud es 6";

		if(w.Cantidad()!=3)
			cout<<"\n\n9ERROR, la cantidad deberia ser todavia 3";	
	}

	bool xd = w.Redimensionar(2);
		
	if (!xd)
		cout<<"\n\n10ERROR, si se puede redimensionar";

	else{
		if (w.Longitud()!=2)
			cout<<"\n\n11ERROR, la longitud es 6";

		if(w.Cantidad()!=2)
			cout<<"\n\n12ERROR, la cantidad deberia ser todavia 3";	
	}
}


int main() {
	pruebasTad();
	pruebasMias();
}
