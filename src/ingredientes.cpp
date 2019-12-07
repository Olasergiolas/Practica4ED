#include "ingredientes.h"
#include "ingrediente.h"
#include <cmath>
#include<bits/stdc++.h> 

using namespace std;

ingredientes::ingredientes(){   
}

void ingredientes::aniadiringrediente(const ingrediente& ingr){
    unsigned aux = aniadirordenadoDatos(ingr);
    
    aniadirindice(aux);
}

unsigned ingredientes::aniadirordenadoDatos(const ingrediente& dato){
    unsigned posicion = datos.size();
    bool encontrado = false;
    const_iterador aux = begin();

    for (unsigned i = 0; !encontrado && i < datos.size(); ++i)
    {
        if (datos[i] > dato)
        {
            posicion = i;
            encontrado = true;
        }  
    }
    
    advance(aux.it, posicion);
    datos.insert(aux.it, dato); 
    return posicion;
}

void ingredientes::aniadirindice(unsigned pos_d)
{
    bool encontrado = false;
    unsigned posicion = indice.size();
    ingrediente aux;
    ingrediente aniadido = datos[pos_d];
    vector<int>::iterator it = indice.begin();
    
    for (unsigned j = 0; j < indice.size(); j++){
        if (indice[j] >= pos_d)
            indice[j] = indice[j] + 1;
    }
    
    for (unsigned i = 0; i < indice.size() && !encontrado; i++){

        aux = datos[indice[i]];
        
        if (aux.getTipo() == aniadido.getTipo() && aux != aniadido){
            if (aux.getNombre() > aniadido.getNombre()){
                posicion = i;
                encontrado = true;
            }
        }
        
        else if (aux.getTipo() > aniadido.getTipo()){
            posicion = i;
            encontrado = true;
        }
    }
    
    advance(it, posicion);
    indice.insert(it, pos_d);
}

void ingredientes::borrar (string &n){
    bool encontrado = false;
    unsigned pos;
    const_iterador aux = begin();
    
    for (unsigned i = 0; i < datos.size(); ++i){
        if (datos[i].getNombre() == n){
            pos = i;
            encontrado = true;
        }
    }
    
    advance(aux.it, pos);
    datos.erase(aux.it);
    indice.erase(find(indice.begin(), indice.end(), pos));
    
    
    for (unsigned i = 0; i < indice.size(); i++){
        if (indice[i] > pos)
            indice[i]--;
    }
}

const unsigned ingredientes::size() const
{
    return datos.size();
}

ingrediente ingredientes::get(string &n){
    ingrediente encontrado, aux;
    bool fin = false;
    
    for (unsigned i = 0; i < datos.size() && !fin; ++i){
        aux = datos[i];
        
        if (aux.getNombre() == n){
            encontrado = datos[i];
            fin = true;
        }
    }
    
    return encontrado;
}

ingredientes ingredientes::getIngredienteTipo(const string t){
    unsigned util = datos.size();
    ingredientes aux;
    ingrediente auxing;
    
    for (unsigned i = 0; i < util; ++i)
    {
        auxing = datos[i];
        
        if (auxing.getTipo() == t)
            aux.aniadiringrediente(datos[i]);
    }
    
    return aux;
}

ingrediente& ingredientes::operator[] (unsigned i)
{
    return datos[i];
}

const ingrediente& ingredientes::operator[] (unsigned i) const{
    return datos[i];                 
}

vector<string> ingredientes::getTipos(){
    vector<string> tiposPresentes;
    string tipo_actual;
    vector<string>::iterator aux = tiposPresentes.begin();
    unsigned util = datos.size();
    unsigned contador = 0;
    bool repetido;
    
    for (unsigned i = 0; i < util; ++i)
    {
        repetido = false;
        tipo_actual = datos[indice[i]].getTipo();
        for (unsigned j = 0; j < tiposPresentes.size() && !repetido; ++j)
        {
            if (tipo_actual == tiposPresentes[j])
                repetido = true;
        }
        
        if (!repetido){
            aux = tiposPresentes.begin();
            advance(aux, contador);
            tiposPresentes.insert(aux, tipo_actual);
            contador++;
        }
    }
    
    return tiposPresentes;
}

void ingredientes::ImprimirPorTipo(std::ostream& os)
{
    unsigned util = indice.size();
    for (unsigned i = 0; i < util; ++i)
        os << datos[indice[i]] << endl;
}

std::ostream & operator<<(std::ostream &os, const ingredientes& ingrs)
{
    unsigned util = ingrs.size();
    for (unsigned i = 0; i < util; ++i)
        os << ingrs[i] << endl;
    
    return os;
}

std::istream & operator>>(std::istream &is, ingredientes& ingrs)
{
    ingrediente aux;
    string n;
    getline(is, n);
    while(is >> aux)
        ingrs.aniadiringrediente(aux);
                        
    return is;
}