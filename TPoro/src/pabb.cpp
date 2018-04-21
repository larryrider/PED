#include <iostream>

using namespace std;

#include "tabbporo.h"

void tad01(){
  	TABBPoro a;

  	TPoro p1(1,2,1,(char *) "rojo");
  	TPoro p2(1,2,2,(char *) "verde");

  	a.Insertar(p1);

	TABBPoro b(a), c;
	c=b;

	a.Insertar(p2);
	if( a.Inorden() == b.Inorden() )
		cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
	else
		cout << "CORRECTO CONSTRUCTOR DE COPIA" << endl;


	b.Insertar(p2);
	if( b.Inorden() == c.Inorden() )
		cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
	else
		cout << "CORRECTA ASIGNACION" << endl;
}

void tad02(){
	TABBPoro a,b,c;

	TPoro p1(1,2,1,(char *) "rojo");

	b.Insertar(p1);


	cout << (a = b).Inorden() << endl;

	cout << (a = c).Inorden() << endl;
}

void tad03(){
	TABBPoro a ;

	if( a.EsVacio() )
		cout << "VACIO" << endl;
	else
		cout << "INCORRECTO EsVacio()" << endl;

	TPoro p1(1,2,1,(char *) "rojo");

	a.Insertar(p1);
	if( a.EsVacio() )
		cout << "INCORRECTO EsVacio()" << endl;
	else
		cout << "NO VACIO" << endl;

	a.Borrar(p1);
	if( a.EsVacio() )
		cout << "VACIO" << endl;
	else
		cout << "INCORRECTO Borrar()" << endl;
}

void tad04(){
	TABBPoro a;

	TPoro p1(1,2,1,(char *) "rojo");
	TPoro p2(1,2,2,(char *) "rojo");
	TPoro p3(1,2,3,(char *) "rojo");
	TPoro p4(1,2,4,(char *) "rojo");
	TPoro p5(1,2,5,(char *) "rojo");
	TPoro p6(1,2,6,(char *) "rojo");
	TPoro p7(1,2,7,(char *) "rojo");

	a.Insertar(p5);
	a.Insertar(p2);
	a.Insertar(p1);
	a.Insertar(p3);
	a.Insertar(p6);

	if(a.Insertar(p7))
		cout << "Insertado" << endl;
	else
		cout << "Error NO INSERCION" << endl;

	if(a.Insertar(p7))
		cout << "Error INSERCION" << endl;
	else
		cout << "No insertado" << endl;

	if(a.Borrar(p7))
		cout << "Borrado" << endl;
	else
		cout << "Error NO BORRADO" << endl;

	if(a.Borrar(p7))
		cout << "Error BORRADO" << endl;
	else
		cout << "No borrado" << endl;

	if(a.Insertar(p7))
		cout << "Insertado" << endl;
	else
		cout << "Error NO INSERCION" << endl;
}

void tad05(){
	TABBPoro a;

	for(int i=1; i<=2; i++){
	//for(int i=1; i<=100; i++){
		for( int num=1; num<=5; num++){
		//  for( int num=1; num<=1000; num++){
			TPoro p1(1,2,(double) num,(char *) "rojo");
			if(!a.Insertar(p1))
				cout << "Error NO INSERCION" << endl;
			p1.~TPoro();
		}
		a.~TABBPoro();
	}

	cout << "CORRECTA INSERCION MULTIPLE" << endl;
}

void tad06(){
	TABBPoro a;

	for(int i=1; i<=100; i++){
		int num;
		for(num=1; num<=10; num++){
		//  for(num=1; num<=1000; num++){
			TPoro p1(1,2,(double) num,(char *) "rojo");
			if(!a.Insertar(p1))
				cout << "Error NO INSERCION" << endl;
			p1.~TPoro();
		}
		
		for(num=1; num<=10; num++){
		//  for(num=1; num<=1000; num++){
			TPoro p1(1,2,(double) num,(char *) "rojo");
			if(!a.Borrar(p1))
				cout << "Error NO BORRADO" << endl;
			p1.~TPoro();
		}
	}
	cout << "CORRECTA INSERCION MULTIPLE" << endl;
}

void tad07(){
	TABBPoro a;

	TPoro p1(1,2,20,(char *) "rojo");
	TPoro p2(1,2,10,(char *) "rojo");
	TPoro p3(1,2,24,(char *) "rojo");
	TPoro p4(1,2,8,(char *) "rojo");
	TPoro p5(1,2,12,(char *) "rojo");
	TPoro p6(1,2,26,(char *) "rojo");
	TPoro p7(1,2,28,(char *) "rojo");

	a.Insertar(p1);
	a.Insertar(p2);
	a.Insertar(p3);
	a.Insertar(p4);
	a.Insertar(p5);
	a.Insertar(p6);
	a.Insertar(p7);

	if(!a.Borrar(p7))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p6))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p3))
		cout << "Error NO BORRADO" << endl;

	cout << a.Inorden() << endl;

	if(!a.Borrar(p5))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p4))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p2))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p1))
		cout << "Error NO BORRADO" << endl;

	cout << a.Inorden() << endl;
}

void tad08(){
	TABBPoro a;

	TPoro p1(1,2,20,(char *) "rojo");
	TPoro p2(1,2,10,(char *) "rojo");
	TPoro p3(1,2,24,(char *) "rojo");
	TPoro p4(1,2,8,(char *) "rojo");
	TPoro p5(1,2,12,(char *) "rojo");
	TPoro p6(1,2,26,(char *) "rojo");
	TPoro p7(1,2,28,(char *) "rojo");

	a.Insertar(p1);
	a.Insertar(p2);
	a.Insertar(p3);
	a.Insertar(p4);
	a.Insertar(p5);
	a.Insertar(p6);
	a.Insertar(p7);

	if(!a.Borrar(p3))
		cout << "Error NO BORRADO" << endl;
	if(!a.Borrar(p6))
		cout << "Error NO BORRADO" << endl;

	cout << a.Inorden() << endl;
}

void tad09(){
	TABBPoro a;

	TPoro p1(1,2,20,(char *) "rojo");
	TPoro p2(1,2,10,(char *) "rojo");
	TPoro p3(1,2,24,(char *) "rojo");
	TPoro p4(1,2,8,(char *) "rojo");
	TPoro p5(1,2,12,(char *) "rojo");
	TPoro p6(1,2,26,(char *) "rojo");
	TPoro p7(1,2,28,(char *) "rojo");
	TPoro p8(1,2,11,(char *) "rojo");

	a.Insertar(p1);
	a.Insertar(p2);
	a.Insertar(p3);
	a.Insertar(p4);
	a.Insertar(p5);
	a.Insertar(p6);
	a.Insertar(p7);

	if(!a.Borrar(p1))
		cout << "Error NO BORRADO" << endl;

	if(!a.Borrar(p5))
		cout << "Error NO BORRADO" << endl;

	if(!a.Borrar(p8))
		cout << "Error NO BORRADO" << endl;

	if(!a.Borrar(p2))
		cout << "Error NO BORRADO" << endl;

	if(!a.Borrar(p4))
		cout << "Error NO BORRADO" << endl;

	cout << a.Inorden() << endl;

}

void tad10(){
	TABBPoro a;

	TPoro p1(1,2,1,(char *) "rojo");
	TPoro p2(1,2,2,(char *) "rojo");
	TPoro p3(1,2,3,(char *) "rojo");
	TPoro p4(1,2,4,(char *) "rojo");
	TPoro p5(1,2,5,(char *) "rojo");
	TPoro p6(1,2,6,(char *) "rojo");
	TPoro p7(1,2,7,(char *) "rojo");

	a.Insertar(p5);
	a.Insertar(p2);
	a.Insertar(p1);
	a.Insertar(p3);
	a.Insertar(p6);

	bool busc = a.Buscar(p7);
	cout <<"Encontrado = "<<busc<<endl;
	bool ins = a.Insertar(p7);
	cout <<"Insertado = "<<ins<<endl;
	busc = a.Buscar(p7);
	cout <<"Encontrado = "<<busc<<endl;


	bool busc2 = a.Buscar(p1);
	cout <<"Encontrado = "<<busc2<<endl;
	bool ins2 = a.Insertar(p1);
	cout <<"Insertado = "<<ins2<<endl;
	bool bor2 = a.Borrar(p1);
	cout <<"Borrado = "<<bor2<<endl;
	busc2 = a.Buscar(p1);
	cout <<"Encontrado = "<<busc2<<endl;
}

void tad11(){
	TABBPoro a;

	TPoro p100(1,2,100,(char *) "rojo");
	TPoro p50(1,2,50,(char *) "rojo");
	TPoro p20(1,2,20,(char *) "rojo");
	TPoro p110(1,2,110,(char *) "rojo");

	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;

	a.Insertar(p100);
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;

	a.Insertar(p50);
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;

	a.Insertar(p20);
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;

	a.Insertar(p110);
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;

	a.Borrar(p20);
	cout <<"Altura: "<<a.Altura()<<endl;
	cout <<"Nodos: "<<a.Nodos()<<endl;
	cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
	cout <<"Raiz: "<<a.Raiz()<<endl;
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
	cout<<"EMPIEZA EL TAD11:\n";
	tad11();
}

int main() {
	pruebasTad();
}
