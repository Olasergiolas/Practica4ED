#include "acciones.h"
#include <cstring>

using namespace std;

Acciones::Acciones(){
    
}

void Acciones::aniadirAccion(pair<string, unsigned char> accion){
    datos.insert(accion);
}

Acciones& Acciones::operator= (const Acciones& otro){
    datos = otro.datos;
    return *this;
}

unsigned char Acciones::getAriedad(string accion){
    unsigned char result = 0;
    map<string, unsigned char>::iterator it = datos.find(accion);
    if (it != datos.end())
        result = it->second;

    return result;    
}

istream &operator>>(istream &is, Acciones &otro){
    string accion;
    unsigned char el;
    Acciones aux;
    
    while (is){
        getline(is, accion, ' ');       
        is >> el;     
        is.ignore();
        
        if (strcmp(accion.c_str(), "\n") != 0)
            aux.aniadirAccion(pair<string, unsigned char>(accion, el));
    }
    
    otro = aux;
    return is;
}