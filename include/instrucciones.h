/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instrucciones.h
 * Author: sergio
 *
 * Created on 7 de diciembre de 2019, 20:36
 */

#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "arbolbinario.h"
#include "acciones.h"
#include <iostream>
#include <stack>

using namespace std;

class Instrucciones{
private:
    ArbolBinario<string> datos;
    
    
public:
    static Acciones acc;
    
    Instrucciones(Acciones acciones){
        acc = acciones;
    }
    
};

istream &operator>>(istream &is, Instrucciones &otro){
    string accion, ingrediente;
    unsigned char ariedad;
    stack<ArbolBinario<string>> pila;
    
    while(is){
        getline(is, accion, ' ');
        getline(is, ingrediente);   //Ver si funciona bien con palabras separadas
        ariedad = otro.acc.getAriedad(accion);
        
        if (ariedad == '1'){
            ArbolBinario<string> arbol(accion);
            arbol.Insertar_Hi(ingrediente);
            pila.push(arbol);
        }
        
        else{
            
        }
        
        
    }
}

#endif /* INSTRUCCIONES_H */

