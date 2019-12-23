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
    string accion, ingrediente, linea;
    unsigned char ariedad;
    stack<ArbolBinario<string>> pila;
    
    while(is){    
        getline(is, linea);
        int contador = 0;
        
        while(linea[contador] != ' ' && linea[contador] != '\0'){
            accion += linea[contador];
            contador++;
        }
        
        ariedad = otro.getAcciones().getAriedad(accion);
        
        //Procedo a sacar dos elementos de la pila
        if (linea[contador] == '\0' && ariedad == '2'){
            ArbolBinario<string> aux1 = pila.top();
            pila.pop();
            
            ArbolBinario<string> aux2 = pila.top();
            pila.pop();
            
            ArbolBinario<string> aux(accion);
            aux.Insertar_Hd(aux.getRaiz(), aux1);
            aux.Insertar_Hi(aux.getRaiz(), aux2);
            
            pila.push(aux);
        }
        
        //Saco un elemento
        else if (linea[contador] == '\0' && ariedad == '1'){
            ArbolBinario<string> aux1 = pila.top();
            pila.pop();
            
            ArbolBinario<string> aux(accion);
            aux.Insertar_Hi(aux.getRaiz(), aux1);
            pila.push(aux);
        }
        
        //Leo el ingrediente que hay acontinuación (no puede haber más de un ingrediente por línea)
        else if (linea[contador] == ' ' && ariedad == '1'){
            contador++;
            while(linea[contador] != '\0'){
                ingrediente += linea[contador];
                contador++;
            }
            
            ArbolBinario<string> aux(accion);    
            aux.Insertar_Hi(aux.getRaiz(), ingrediente);
            
            pila.push(aux);
        }
        
        //Leo el elemento a continuación y saco el otro de la pila
        else if (linea[contador] == ' ' && ariedad == '2'){
            contador++;
            while(linea[contador] != '\0'){
                ingrediente += linea[contador];
                contador++;
            }
            
            ArbolBinario<string> aux(accion);
            aux.Insertar_Hd(aux.getRaiz(), ingrediente);
            aux.Insertar_Hi(aux.getRaiz(), pila.top());
            pila.pop();
            
            pila.push(aux);            
        }
        
        ingrediente = "";
        accion = "";
        contador = 0;
        
    }
    
    otro.setDatos(pila.top());
    pila.pop();
    
    return is;
}

void Instrucciones::setDatos(ArbolBinario<string> &d){
    datos = d;
}