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

using namespace std;

class Instrucciones{
private:
    ArbolBinario<string> datos;
    static Acciones acc;
    
public:
    
    Instrucciones(){
        
    }
    
};

istream &operator>>(istream &is, Instrucciones &otro){
    Acciones aux;
    string accion;
    unsigned char ariedad;
    
    while(is){
        getline(is, accion, ' ');
        ariedad = aux.getAriedad(accion);
    }
}

#endif /* INSTRUCCIONES_H */

