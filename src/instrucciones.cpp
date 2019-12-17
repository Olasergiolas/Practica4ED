/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "instrucciones.h"


Instrucciones::Instrucciones(Acciones acciones){
    acc = acciones;
}

Acciones& Instrucciones::getAcciones(){
    return acc;
}

istream &operator>>(istream &is, Instrucciones &otro){
    string accion, ingrediente;
    unsigned char ariedad;
    stack<ArbolBinario<string>> pila;
    
    //La idea es conseguir ver si todos los ingredientes que necesito
    //están en la línea, si no cojo de la pila.
    
    while(is){
        //problema, si no encuentra el espacio se salta hasta la siguiente línea
        getline(is, accion, ' ');
        getline(is, ingrediente);   //Ver si funciona bien con palabras separadas
        ariedad = otro.getAcciones().getAriedad(accion);
        
        /*if (ariedad == '1'){
            ArbolBinario<string> arbol(accion);
            arbol.Insertar_Hi(ingrediente);
            pila.push(arbol);
        }
        
        else{
            
        }*/   
    }
    
    return is;
}