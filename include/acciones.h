/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   acciones.h
 * Author: sergio
 *
 * Created on 7 de diciembre de 2019, 10:16
 */

#include<map>
#include<iostream>

using namespace std;

#ifndef ACCIONES_H
#define ACCIONES_H

class Acciones{
private:
    map<string, unsigned char> datos;
    
public:
    Acciones();
    
    void aniadirAccion(pair<string, unsigned char> accion);
    
    Acciones& operator= (const Acciones& otro);
    
    unsigned char getAriedad(string accion);
};

istream &operator>>(istream &is, Acciones &otro);

#endif /* ACCIONES_H */

