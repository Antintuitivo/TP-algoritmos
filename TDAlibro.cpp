#include "TDAlibro.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


	
<<<<<<< Updated upstream
bool abrirLibro(Libro &arch,char modo,bool binario, string nombre){//abre el archivo para leer o escribir según el modo elegido
=======
bool abrirLibro(Libro &arch, char modo, string nombre){//abre el archivo para leer o escribir según el modo elegido

>>>>>>> Stashed changes
	switch(modo){
	case 'l'://leer
		if(!binario)arch.arc.open(nombre,ios::in);
		else{
			arch.arc.open(nombre,ios::in | ios::binary);
		}
		break;
	case 'e'://escribir
		if(!binario)arch.arc.open(nombre,ios::out);
		else{
			arch.arc.open(nombre,ios::out | ios::binary);
		}
		break;
	}
	return !(arch.arc.fail());
}

void cerrarLibro(Libro &arch){
	arch.arc.close();
}

char leerCaracterLibro(Libro &arch){
	char c;
	arch.arc.get(c);
	return c;
}
bool finArchivo(Libro &arch){
	return arch.arc.eof();
}

<<<<<<< Updated upstream
void LeerPalabraLibro(Libro &arch, char cad[], int tl=20){
	arch.arc.getline(cad, tl,' ');
	int p;
	for(int i=0;i<tl;i++){
		if((!isalpha(cad[i]))&&cad[i]!='-'){
			p=i;
			while(p<tl-1){
				cad[p]=cad[p+1];
			}
			tl--;
		}
	}
=======
string leerPalabraLibro(Libro &arch){
	string cad;
	getline(arch.arc,cad);
	return cad;
	
}

void escribirPalabraLibro(Libro &arch, char cad[]){
	arch.arc<<cad;
}

bool finLibro(Libro &arch){
	return arch.arc.eof();
}

void escribirString(Libro &arch,string frase){
	arch.arc<<frase;
}
void escribirChar(Libro &arch,char caracter){
	arch.arc<<caracter;
}
void escribirNum(Libro &arch,long long num){
	arch.arc<<num;
>>>>>>> Stashed changes
}
void escribirString(Libro &arch,string frase){
	arch.arc<<frase;
	return;
}
void escribirChar(Libro &arch,char caracter){
	arch.arc<<caracter;
	return;
}
void escribirInt(Libro &arch,int num){
	arch.arc<<num;
	return;
}

	
