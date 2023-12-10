#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct Nodo{
	char palabra[30];
	int rep=0;
	Nodo *sig=NULL;
};

typedef Nodo * Lista;
typedef Nodo * ptrNodo;

void intercambiar(ptrNodo primero,ptrNodo segundo){
	int aux;
	aux=primero->rep;
	primero->rep=segundo->rep;
	segundo->rep=aux;
	char auxP[30];
	strcpy(auxP,primero->palabra);
	strcpy(primero->palabra,segundo->palabra);
	strcpy(segundo->palabra,auxP);
	return;
}
	
void ordenarLista(Lista ptrM){
	ptrNodo aux, aux2;
	aux=ptrM;
	while(aux!=NULL){
		aux2=ptrM;
		while(aux2->sig!=NULL){
			if((aux2->rep)<(aux2->sig->rep)){
				intercambiar(aux2,aux2->sig);
			}
			else if(((aux2->rep)==(aux2->sig->rep)) and ((strlen(aux2->palabra))<(strlen(aux2->sig->palabra)))){
				intercambiar(aux2,aux2->sig);
			}
			else if(((aux2->rep)==(aux2->sig->rep)) and ((strlen(aux2->palabra))==(strlen(aux2->sig->palabra))) and ((aux2->palabra[0])<(aux2->sig->palabra[0]))){
				intercambiar(aux2,aux2->sig);
			}
			aux2=aux2->sig;
		}
		aux=aux->sig;
	}
}

void palabraAMinuscula(char pal[]){
	int f=strlen(pal);
	for(int i=0;i<f;i++){
		if(isalpha(pal[i]))
			pal[i]=tolower(pal[i]);
	}
}

Lista crearLista(char pal[]){
	Lista l;
	l=new Nodo;
	strcpy(l->palabra, pal);
	l->rep=1;
	return l;
}

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
	long long total=0, cant=0;
	float promedio=0;
	ptrNodo ptr=l;
	if(ptr->sig!=NULL){
		do{
			total+=((strlen(ptr->palabra))*(ptr->rep));
			cant+=ptr->rep;
			ptr=ptr->sig;
		}while(ptr->sig!=NULL);
		promedio=(float)total/cant;
	}
	return promedio;
}

void porcentajePalabras(Lista l){
	float voc,cons;
	long long total=0, cant=0;
	ptrNodo ptr=l;
	if(ptr->sig!=NULL){
		do{
			if(ptr->palabra[0]=='a'||ptr->palabra[0]=='e'||ptr->palabra[0]=='i'||ptr->palabra[0]=='o'||ptr->palabra[0]=='u'){
				cant+= ptr->rep;
			}
			total+=ptr->rep;
			ptr=ptr->sig;
		}while(ptr->sig!=NULL);
		voc=(float)total/cant;
		cons=1-voc;
		cout<<"Palabras que comienzan en vocal: "<<voc<<"%"<<endl<<"Palabras que comienzan con consonante: "<<cons<<"%"<<endl;
	}
}

long long encontrarLetraLongitud(Lista l, char c, int n){//cuenta la cantidad de palabras distintas de esa longitud que comiencen por esa letra
	c=tolower(c);
	ptrNodo aux=l;
	long long cant=0;
	while(aux->sig!=NULL){
		if(strlen(aux->palabra)==n && aux->palabra[0]==c){
			cant++;
		}
		aux=aux->sig;
	}
	return cant;
}

