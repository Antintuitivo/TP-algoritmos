#include "TDAlibro.h"
#include <iostream>
#include <string>
using namespace std;

Libro crearLibro(){
	Libro arch;
	return arch;
}

bool confirmarLibro(Libro &arch){//confirma si se abri� correctamente
	return !arch.arc.fail();
}
	
bool abrirLibro(Libro arch, char modo, string nombre){//abre el archivo para leer o escribir seg�n el modo elegido

	switch(modo){
	case 'l'://leer
		arch.arc.open(nombre,ios::in);
		break;
	case 'e'://escribir
		arch.arc.open(nombre,ios::out);
		break;
	case 'b'://binario
		arch.arc.open(nombre,ios::binary);
		break;
	}
	
	return confirmarLibro(arch);
}

void cerrarLibro(Libro &arch){
	arch.arc.close();
}

char leerCaracterLibro(Libro &arch){
	char c;
	arch.arc.get(c);
	return c;
}

void leerPalabraLibro(Libro &arch, char cad[], int tl){
	arch.arc.getline(cad, tl,' ');
	int p;
	for(int i=0;i<tl;i++){
		if((!isalpha(cad[i]))&&cad[i]!='-'&&cad[i]!='\''){
			p=i;
			while(p<tl-1){
				cad[p]=cad[p+1];
			}
			tl--;
		}
	}
}
