/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test.cpp
 * Author: sergio
 *
 * Created on 7 de diciembre de 2019, 10:23
 */

#include <cstdlib>
#include <iostream>
#include <map>
#include "acciones.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    Acciones acciones;
    
    ifstream f("./datos/Acciones.txt");
    
    if (!f){
        exit(-1);
    }
    
    f >> acciones;
    
    cout << "mehj";
    
    
}

