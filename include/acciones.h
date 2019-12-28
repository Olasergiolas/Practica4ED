#include<map>
#include<iostream>

using namespace std;

#ifndef ACCIONES_H
#define ACCIONES_H

/**
 * @brief T.D.A. Acciones
 * 
 * Una instancia @c Acciones es una colección de pares formado por una acción
 * junto a la ariedad (número de operandos necesarios) de la acción.
 * 
 * @author Sergio García Cabrera
 * @author Guillermo García Arredondo
 * 
 * @date Diciembre 2019
 */

class Acciones{
private:
    /**
     * @page Representación del TDA Acciones
     * 
     * Un objeto válido Acciones está formado por un contenedor map con una
     * clave de tipo string (la acción) y un valor de tipo unsigned char (la ariedad,
     * es decir, número de operandos necesarios, cuyos valores válidos son solo 1 o 2).
     */
    map<string, unsigned char> datos;
    
public:
    /**
     * @brief Constructor por defecto
     */
    Acciones();
    
    /**
     * @brief Añade una acción al diccionario de acciones
     * @param accion Par de string (acción) y unsigned char (ariedad) con la acción
     * a añadir
     */
    void aniadirAccion(pair<string, unsigned char> accion);
    
    /**
     * @brief Sobrecarga del operador de asignación
     * @param otro Parámetro a asignar
     * @return *this
     */
    Acciones& operator= (const Acciones& otro);
    
    /**
     * @brief Consultor de la ariedad de una acción concreta
     * @param accion Acción a la que se le va a consultar su ariedad
     * @return Devuelve la ariedad correspondiente si la encuentra, sino devuelve 0
     */
    unsigned char getAriedad(string accion);
};

/**
 * @brief Sobrecarga del operador de entrada para acciones
 * @param is Flujo de entrada
 * @param otro Objeto de tipo Acciones
 * @return 
 */
istream &operator>>(istream &is, Acciones &otro);

#endif /* ACCIONES_H */

