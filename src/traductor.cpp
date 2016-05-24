#include <string>
#include <cstring>
#include <iostream>
#include "palabra.h"
#include "traductor.h"
using namespace std;

	void traductor::Resize(int nuevo_n){
		if(nuevo_n>0 && nuevo_n>entrres){
			palabra* aux1 = new palabra[nuevo_n] ;
			palabra* aux2 = entradas ;
			for(int i=0; i<nentr; i++)
				aux1[i]=entradas[i];
			entradas=aux1 ;
			aux1=aux2;
			aux2=NULL;
			entrres=nuevo_n;
		}
	}

	int traductor::Reservados(){
		return entrres;
	}

	traductor::traductor(){
		entradas=new palabra[2] ;
		nentr=0 ;
		entrres=2 ;
	}

	traductor::~traductor(){
		if(entrres!=0){
			delete[]entradas ;
			nentr=0 ;
			entrres=0 ;
		}
	}

	int traductor::Tamanio() const {
		return nentr ;
	}
	traductor::traductor(const traductor& orig){
		if(orig.entrres>entrres)
			Resize(orig.entrres);
		for(int i=0; i<orig.nentr; i++){	
			entradas[i]=orig.entradas[i];
		nentr=orig.nentr;
		}
	}

	traductor& traductor::operator=(const traductor& trad){
		traductor nuevo(trad);
		palabra* aux=entradas;
		entradas=nuevo.entradas;
		nuevo.entradas=aux;
		nentr=nuevo.Tamanio();
		entrres=nuevo.Reservados();
	return *this;
	}

	void traductor::Aniade(palabra w){
		if(entrres==nentr){        
				Resize(2*entrres);
		}
		entradas[nentr]=w;	
		nentr++;
	}

	istream& operator>>(istream& f, traductor& datos){
		string acepcion;
		getline(f,acepcion);
		int i = 0 ;
		palabra w ;
		while(acepcion.size()!=0){
			w.cargar(acepcion) ;
			datos.Aniade(w) ;
			getline(f,acepcion) ; 
			i++;
		}
	return f;
	}

	string* traductor::GetTraduccion(string busqueda, int& nacep){
		int i=0;
		string* aux = NULL ; 
		while(i<nentr && busqueda!=entradas[i].Terminos()[0]){   
			i++;
		}
		if(i<nentr){
			nacep=entradas[i].Tamanio() ;
			aux=entradas[i].Terminos() ;
			
		}else{
			nacep=0;
			aux=NULL;
		}
		return aux;
	}





