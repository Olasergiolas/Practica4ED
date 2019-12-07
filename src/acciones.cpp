#include "acciones.h"

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
        map<string, unsigned char>::iterator it = datos.find(accion);
        
        return it->second;    
}

istream &operator>>(istream &is, Acciones &otro){
    string accion;
    unsigned char el, endline;
    Acciones aux;
    
    while (is){
        getline(is, accion, ' ');       
        is >> el;     
        is.ignore();
        aux.aniadirAccion(pair<string, unsigned char>(accion, el));
    }
    
    otro = aux;
    return is;
}