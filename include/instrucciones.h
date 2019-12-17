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
    Acciones acc;
    
public:
    
    Instrucciones(Acciones acciones);
    
    Acciones& getAcciones();
    
};

istream &operator>>(istream &is, Instrucciones &otro);

#endif /* INSTRUCCIONES_H */

