#include <iostream>

using namespace std;

#include "tlistacalendario.h"

void tad01(){
	TListaCalendario a, b, c;
   	cout << "No hace nada" << endl;
}

void tad02(){
	TListaCalendario l1;
	TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
	TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");
	
	cout << l1 << endl;
	l1.Insertar(c1);
	cout << l1 << endl;
	l1.Insertar(c2);
	cout << l1 << endl;
}

void tad03(){
	TListaCalendario l1;
	TCalendario c;

	cout << l1.Longitud() << endl;

	l1.Insertar(c);
	cout << l1.Longitud() << endl;
}

void tad04(){
	TListaCalendario l1;
	TCalendario c1;
	TCalendario c2(1, 1, 2007, (char*) "Fecha2");

	cout << l1 << endl;

	l1.Insertar(c1);
	l1.Insertar(c2);
	cout << l1 << endl;

	l1.Borrar(c2);
	cout << l1 << endl;
}

void tad05(){
	TListaCalendario l1, l2, l3;
	TCalendario c1;
	TCalendario c2(1, 1, 2007, (char*) "Fecha2");

	l1.Insertar(c1);
	l2.Insertar(c2);
	l3 = l1 + l2;

	cout << l3 << endl;
	cout << l1 + l2 << endl;
}

void tad06(){
	TListaCalendario a, b, c;
	TListaPos p, q;
	TNodoCalendario n, m;

	cout << "No hace nada" << endl;
}

void tad07(){
	TListaCalendario l1;
  
	if((l1.Primera()).EsVacia())
		cout << "Direccion vacia" << endl;
	else
		cout << "Direccion no vacia" << endl;
		
	if((l1.Ultima()).EsVacia())
		cout << "Direccion vacia" << endl;
	else
		cout << "Direccion no vacia" << endl;

	cout << "l1 = " << l1 << endl;
}

void tad08(){
	TCalendario a(1, 1, 1977, (char*) "uno");
	TCalendario b(1, 1, 1980, (char*) "dos");
	TListaCalendario l1;
	
	l1.Insertar(a);   
	l1.Insertar(b);
	l1.Insertar(a + 3);

	TListaCalendario l2(l1);
	cout << "l2 = " << l2 << endl;
	cout << "l1 = " << l1 << endl;
}

void tad09(){
	TCalendario a(1, 1, 1977, (char*) "uno");
	TCalendario b(1, 1, 1980, (char*) "dos");
	TListaCalendario l1;

	if(l1.EsVacia())
		cout << "Lista vacia" << endl;
	else
		cout << "Lista no vacia" << endl;
	
	l1.Insertar(a);   
	l1.Insertar(b);

	if(l1.EsVacia())
		cout << "Lista vacia" << endl;
	else
		cout << "Lista no vacia" << endl;
	}

void tad10(){
	TCalendario a(1, 1, 1977, (char*) "uno");
	TCalendario b(1, 1, 1980, (char*) "dos");
	TListaCalendario l1;

	if(l1.EsVacia())
		cout << "Lista vacia" << endl;
	else
		cout << "Lista no vacia" << endl;
	
	l1.Insertar(b);
	cout << l1.Obtener(l1.Primera()) << endl;
	
	l1.Insertar(a);
	cout << l1.Obtener(l1.Primera()) << endl;

	cout << "l1 = " << l1 << endl;
	
	if(l1.EsVacia())
		cout << "Lista vacia" << endl;
	else
		cout << "Lista no vacia" << endl;    
}

void tad16(){
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	TCalendario b(11,10,2006, (char*) "mensaje 2");
	TCalendario c(12,10,2006, (char*) "mensaje 3");
	TCalendario d(13,10,2006, (char*) "mensaje 4");
	TCalendario e(14,10,2006, (char*) "mensaje 5");
	TCalendario f(15,10,2006, (char*) "mensaje 6");
	TCalendario g(16,10,2006, (char*) "mensaje 7");
	TCalendario h(17,10,2006, (char*) "mensaje 8");
	TCalendario i(18,10,2006, (char*) "mensaje 9");
	TCalendario j(19,10,2006, (char*) "mensaje 10");
	TCalendario k(20,10,2006, (char*) "mensaje 11");
	TCalendario l(21,10,2006, (char*) "mensaje 12");


	TListaCalendario lista;
	TListaCalendario lista2;
	TListaCalendario lista3;

	lista.Insertar(a);
	lista.Insertar(b);
	lista.Insertar(c);
	lista.Insertar(d);
	//lista.Insertar(e);

	/*lista2.Insertar(f);
	lista2.Insertar(g);
	lista2.Insertar(h);
	lista2.Insertar(i);
	lista2.Insertar(j);

	lista3=lista.SumarSubl(4,2,lista2,0,1);
	
	cout<<lista3<<endl;*/
}

void tad17(){
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	TCalendario b(11,10,2006, (char*) "mensaje 2");
	TCalendario c(12,10,2006, (char*) "mensaje 3");
	TCalendario d(13,10,2006, (char*) "mensaje 4");
	TCalendario e(14,10,2006, (char*) "mensaje 5");
	TCalendario f(15,10,2006, (char*) "mensaje 6");
	TCalendario g(16,10,2006, (char*) "mensaje 7");
	TCalendario h(17,10,2006, (char*) "mensaje 8");
	TCalendario i(18,10,2006, (char*) "mensaje 9");
	TCalendario j(19,10,2006, (char*) "mensaje 10");
	TCalendario k(20,10,2006, (char*) "mensaje 11");
	TCalendario l(21,10,2006, (char*) "mensaje 12");

	TListaCalendario lista;
	TListaCalendario lista2;

	lista.Insertar(a);
	lista.Insertar(b);
	lista.Insertar(c);
	lista.Insertar(d);
	lista.Insertar(e);

	lista2=lista.ExtraerRango(5,20);
	cout<<lista2<<endl;

	TListaPos p,p2;
	p =lista.Primera();  
	p2=lista.Ultima();  

	cout<<lista.Obtener(p)<<endl;
	cout<<lista.Obtener(p2)<<endl;
}

void tad18(){
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	TCalendario b(11,10,2006, (char*) "mensaje 2");
	TCalendario c(12,10,2006, (char*) "mensaje 3");
	TCalendario d(13,10,2006, (char*) "mensaje 4");
	TCalendario e(14,10,2006, (char*) "mensaje 5");
	TCalendario f(15,10,2006, (char*) "mensaje 6");
	TCalendario g(16,10,2006, (char*) "mensaje 7");
	TCalendario h(17,10,2006, (char*) "mensaje 8");
	TCalendario i(18,10,2006, (char*) "mensaje 9");
	TCalendario j(19,10,2006, (char*) "mensaje 10");
	TCalendario k(20,10,2006, (char*) "mensaje 11");
	TCalendario l(21,10,2006, (char*) "mensaje 12");


	TListaCalendario lista;
	TListaPos p;

	lista.Insertar(a);
	lista.Insertar(b);
	lista.Insertar(c);
	lista.Insertar(d);
	lista.Insertar(e);
	lista.Insertar(f);
	lista.Insertar(g);
	lista.Insertar(h);
	lista.Insertar(i);
	lista.Insertar(j);

	lista.Borrar(14,10,2006);

	p=lista.Primera();  

	cout<<lista.Obtener(p)<<endl;
}

void tad19(){
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	TCalendario b(11,10,2006, (char*) "mensaje 2");
	TCalendario c(12,10,2006, (char*) "mensaje 3");
	TCalendario d(13,10,2006, (char*) "mensaje 4");
	TCalendario e(14,10,2006, (char*) "mensaje 5");
	TCalendario f(15,10,2006, (char*) "mensaje 6");
	TCalendario g(16,10,2006, (char*) "mensaje 7");
	TCalendario h(17,10,2006, (char*) "mensaje 8");
	TCalendario i(18,10,2006, (char*) "mensaje 9");
	TCalendario j(19,10,2006, (char*) "mensaje 10");
	TCalendario k(20,10,2006, (char*) "mensaje 11");
	TCalendario l(21,10,2006, (char*) "mensaje 12");


	TListaCalendario lista;
	TListaCalendario lista2;
	TListaCalendario lista3;
	TListaPos p;

	lista.Insertar(a);
	lista.Insertar(b);
	lista2.Insertar(c);
	lista2.Insertar(d);

	lista3=lista+lista2;
	
	cout<<lista3<<endl;
}

void tad20(){
	TCalendario a(10,10,2006, (char*) "mensaje 1");
	TCalendario b(11,10,2006, (char*) "mensaje 2");
	TCalendario c(12,10,2006, (char*) "mensaje 3");
	TCalendario d(13,10,2006, (char*) "mensaje 4");
	TCalendario e(14,10,2006, (char*) "mensaje 5");
	TCalendario f(15,10,2006, (char*) "mensaje 6");
	TCalendario g(16,10,2006, (char*) "mensaje 7");
	TCalendario h(17,10,2006, (char*) "mensaje 8");
	TCalendario i(18,10,2006, (char*) "mensaje 9");
	TCalendario j(19,10,2006, (char*) "mensaje 10");
	TCalendario k(20,10,2006, (char*) "mensaje 11");
	TCalendario l(21,10,2006, (char*) "mensaje 12");


	TListaCalendario lista;
	TListaCalendario lista2;
	TListaCalendario lista3;
	TListaPos p;

	lista.Insertar(a);
	lista.Insertar(b);
	lista.Insertar(c);
	lista2.Insertar(c);
	lista2.Insertar(d);

	lista3=lista-lista2;
	
	cout<<lista3<<endl;
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
	cout<<"EMPIEZA EL TAD16:\n";
	tad16();	
	/*cout<<"EMPIEZA EL TAD17:\n";
	tad17();	
	cout<<"EMPIEZA EL TAD18:\n";
	tad18();
	cout<<"EMPIEZA EL TAD19:\n";
	tad19();
	cout<<"EMPIEZA EL TAD20:\n";
	tad20();*/
}

int main() {
	pruebasTad();
}
