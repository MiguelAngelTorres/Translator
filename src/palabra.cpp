#include <cstring>
#include <string>
#include "palabra.h"
#include <iostream>
using namespace std;

	void palabra::Resize(int nuevo_n){
		if(nuevo_n>0 && nuevo_n>reservados){
			string* aux1 = new string [nuevo_n] ;
			string* aux2 = termino ;
			for(int i=0; i<n; i++)
				aux1[i]=termino[i];
			termino=aux1 ;
			aux1=aux2;
			aux2=NULL;
			reservados=nuevo_n;
		}
	}
	
	palabra::palabra(){ 
		termino = new string[2] ;
		n=0;	
		reservados=2;
	}
	
	palabra::palabra(const palabra& w){
		n=0;
		reservados=0;
		int nuevo_n = w.n;
		Resize(nuevo_n);
		for(int i=0; i<nuevo_n; i++){
			termino[i]=w.termino[i];
		}
		n=nuevo_n ;
		reservados=w.reservados;
	}
		
	void palabra::cargar(const string d){ 
		int lon=d.size();
		int j=0;
		string aux ;	
		for(int i=0; i<lon; i++){
			if(d[i]==';'){
				termino[j]=aux ;
				aux.clear();
				j++;
				if(reservados<=j){
					Resize(reservados*2);
				}
			}else{
				aux=aux+d[i];
			}
		}
		n=j;
	}

	palabra::~palabra(){
		if(reservados!=0){
			delete[]termino;
			n=0;
			reservados=0;
		}
	}

	const int palabra::Tamanio(){
		return n;
	}

	const int palabra::Reserva(){
		return reservados;
	}

	string* palabra::Terminos(){
		return termino ;
	}	

	palabra& palabra::operator= (const palabra &original){
		palabra nueva(original);
		string* aux=this->termino;
		termino=nueva.termino;
		nueva.termino=aux;
		n=nueva.Tamanio();
		reservados=nueva.Reserva();
	return *this ;
	}

