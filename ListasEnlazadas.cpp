#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct Nodo{
	char palabra[30];
	int rep=0,tl=0;
	Nodo *sig=NULL;
};

typedef Nodo * Lista;
typedef Nodo * ptrNodo;

bool aniadirNodo(char pal[], Lista l){
	ptrNodo	aux, nuevo;
	aux = l;
	bool b;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	nuevo = new Nodo;
	if(nuevo!=NULL){
		aux->sig= nuevo;
		aux=nuevo;
		
		aux->sig=NULL;
		strcpy(aux->palabra, pal);
		aux->tl=strlen(pal);
		aux->rep=1;
		b=true;
	}else{
		b=false;//no hay suficiente espacio para crear un nuevo nodo
	}
	return b;
}

bool encontrarPalabra(Lista l, ptrNodo &ptr, char pal[]){
	bool encontrado=false;
	ptrNodo aux=l;
	while(!encontrado && aux->sig!=NULL){
		encontrado=(strcmp(aux->palabra,pal)==0);
		if(!encontrado)aux=aux->sig;
	}
	if(encontrado){
		ptr=aux;
	}
	return encontrado;
}

float longitudPromedio(Lista l){
	long long total=0;
	float promedio=0;
	int cant=0;
	ptrNodo ptr=l;
	if(ptr->sig!=NULL){
		do{
			total+=ptr->tl;
			cant+=ptr->rep;
			ptr=ptr->sig;
		}while(ptr->sig!=NULL);
		promedio=(float)total/cant;
	}
	return promedio;
}

