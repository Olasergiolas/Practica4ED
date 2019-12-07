#include "ingrediente.h"
#include "string.h"
#include <iostream>

using namespace std;

ingrediente::ingrediente(){
    nombre.assign("null");
    nCalx100 = 0;
    tipo.assign("null");
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
}

ingrediente::ingrediente(const char* n, const double& nCal, const double& hc, const double& prot, const double& gra, const double& fib, const char* t) {
    nombre.assign(n);
    tipo.assign(t);
    nCalx100 = nCal;
    
    v[0] = hc;
    v[1] = prot;
    v[2] = gra;
    v[3] = fib;
}

string ingrediente::getNombre() const{
    return nombre;
}

string ingrediente::getTipo() const{
    return tipo;
}

double ingrediente::getCalorias() const{
    return nCalx100;
}

double ingrediente::getHc() const{
  return v[0];
}

double ingrediente::getProteinas() const{
    return v[1];
}

double ingrediente::getGrasas() const{
  return v[2];
}

double ingrediente::getFibra() const{
  return v[3];
}

bool ingrediente::operator>(const ingrediente& otro) const
{
    bool retorno = false;
    if (nombre > otro.nombre)
        retorno = true;
    return retorno;
}

bool ingrediente::operator!=(const ingrediente& otro) const{
    bool distintos = true;
    
    if (nombre == otro.nombre){
        distintos = false;
    }
    
    return distintos;
}

istream& operator>> (istream &i, ingrediente &otro){
    string n, t;
    double cal, hc, pr, gr, fi;
    char aux;

    getline(i, n, ';');    
    i >> cal >> aux >> hc >> aux >> pr >> aux >> gr >> aux >> fi >> aux;
    getline(i, t);

    otro = ingrediente(n.c_str(), cal, hc, pr, gr, fi, t.c_str());

    return i;
}

ostream& operator<< (ostream &o, const ingrediente &otro){
    char aux = ';';
    
    o << otro.getNombre() << aux << otro.getCalorias() << aux << otro.getHc() << aux << otro.getProteinas() << aux << otro.getGrasas() << aux << otro.getFibra() << aux << otro.getTipo();
    
    return o;
}
