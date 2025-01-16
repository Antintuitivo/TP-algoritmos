#include <fstream>
#include <string>
using namespace std;

struct Libro{
	fstream arc;
};

void cerrarLibro(Libro &arch);
bool abrirLibro(Libro &arch, char modo,bool binario, string nombre);
char leerCaracterLibro(Libro &arch);
<<<<<<< Updated upstream
void LeerPalabraLibro(Libro &arch, char cad[]);
bool finArchivo(Libro &arch);
void escribirString(Libro &arch,string);
void escribirChar(Libro &arch,char);
void escribirInt(Libro &arch,int);
=======
string leerPalabraLibro(Libro &arch);
void escribirPalabraLibro(Libro &arch, char cad[]);
void escribirNumeroLibro(Libro &arch, long long num);
bool finLibro(Libro &arch);
bool confirmarLibro(Libro &arch);
void escribirNum(Libro &arch,long long num);
void escribirChar(Libro &arch,char caracter);
void escribirString(Libro &arch,string frase);
	
#endif
>>>>>>> Stashed changes
