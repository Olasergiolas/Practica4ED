#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "arbolbinario.h"
#include "acciones.h"
#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief T.D.A. Instrucciones
 * 
 * Una instancia de @c Instrucciones contiene la secuencia de pasos que deben darse
 * para cocinar una receta. Los pasos se almacenan en un árbol binario.
 * 
 * Un ejemplo de su uso:
 * @include cocinero_integral.cpp
 * 
 * @author Guillermo García Arredondo
 * @author Sergio García Cabrera
 * 
 * @date Diciembre 2019
 */

class Instrucciones{
private:
    
    /**
     * @page Representación del TDA Instrucciones
     * 
     * Un objeto válido Instrucciones está formado por un árbol binario de string y un objeto
     * de tipo Acciones. Los nodos del árbol se forman por un conjunto de nodos hojas que
     * serán los ingredientes base de la receta y el resto de nodos serán acciones del conjunto
     * de acciones permitidas.
     */
    ArbolBinario<string> datos;
    static Acciones acc;
    
public:
    /**
     * @brief Constructor por defecto
     */
    Instrucciones();
    
    /**
     * @brief Constructor con parámetro
     * @param acciones
     */
    Instrucciones(Acciones acciones);
    
    /**
     * @brief Consultor del atributo acc
     * @return Atributo acc de tipo Acciones
     */
    Acciones& getAcciones();
    
    /**
     * @brief Modificador del árbol binario datos
     * @param d Parámetro que se le va asignar a datos
     */
    void setDatos(ArbolBinario<string> &d);
    
    /**
     * @brief Método para fusionar los árboles de dos objetos instrucciones
     * @param Objeto instrucciones otro para fusionar con this
     * @return Resultado de la fusión de tipo Instrucciones
     */
    Instrucciones fusionarInstrucciones(Instrucciones otro);
    
    /**
     * @brief Sobrecarga del operador de asignación
     * @param og Parámetro que se le va a asignar a datos
     * @return Devuelve *this
     */
    Instrucciones& operator=(const Instrucciones& og);
    
    /**
     * @brief Sobrecarga del operador de entrada para Instrucciones
     * @param is Flujo de entrada
     * @param otro Objeto Instrucciones
     */
    friend istream &operator>>(istream &is, Instrucciones &otro);
    
    /**
     * @brief Sobrecarga del operador de salida para Instrucciones
     * @param os Flujo de salida
     * @param otro Objeto Instrucciones
     */
    friend ostream &operator<<(ostream &os, Instrucciones &otro);
    
};



#endif /* INSTRUCCIONES_H */

