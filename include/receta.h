/**
 */

#ifndef RECETA_H
#define RECETA_H

#include <string>
#include <list>
#include <iostream>
#include "ingredientes.h"
using namespace std;

/**
 * @brief T.D.A. Receta
 * 
 * Una instancia @c Receta es un objeto que intenta representar
 * una receta de cocina, formada por una lista de los ingredientes
 * necesarios por nombre y gramos, la cantidad de calorías, hidratos,
 * grasas, proteínas y fibra que aporta la receta en total, un código,
 * el número de plato y el nombe de la propia receta.
 * 
 * Un ejemplo de su uso:
 * @include test_receta.cpp
 * 
 * @author Guillermo García Arredondo
 * @author Sergio García Cabrera
 * @date Noviembre 2019
 */

class receta 
{
private:
    
    /**
     * @page Representación del TDA Receta
     * 
     * @section Estado válido de un objeto Receta
     * 
     * Un objeto válido del TDA posee una lista con
     * el nombre y cantidad en gramos de cada ingrediente, 
     * el código, número de plato (del 1 al 3 indicando si es
     * primer, segundo plato o postre) y el nombre de la propia
     * receta
     */
    
    string code;
    unsigned plato;
    string nombre;
    list<pair<string, unsigned> > ings;
    double calorias, hidratos, grasas, proteinas, fibra;
    
public:
    /**
     * @brief Constructor por defecto, crea una receta inválida
     */
    receta();
    
    /**
     * @brief Constructor con parámetros
     * @param c código de la receta
     * @param p número de plato
     * @param n nombre de la receta
     */
    receta(string c, unsigned p, string n);
    
    /**
     * @brief Constructor copia
     * @param og receta a copiar
     */
    receta(const receta& og);
    
    /**
     * @brief Destructor por defecto
     */
    ~receta();
    
    /**
     * @brief Añade un ingrediente a la receta
     * @param ingr Par de string para nombre del ingrediente y
     * de unsigned int para la cantidad en gramos de ese ingrediente
     */
    void aniadirIngrediente(pair<string,unsigned> ingr);
    
    /**
     * @brief Establece los nutrientes totales que aporta la receta
     * @param ingrs Objeto ingredientes de donde obtener los nutrientes que
     * aporta cada ingrediente
     */
    void establecerNutrientes(const ingredientes& ingrs);
    
    /**
     * @brief Número de ingredientes de la instancia
     * @return unsigned con el número de ingredientes
     */
    unsigned ningredientes() const;
    
    /**
     * @brief Consultor de code
     * @return string código
     */
    string getCode() const;
    
    /**
     * @brief Consultor de plato
     * @return unsigned del 1 al 3 (primero, segundo, postre)
     */
    unsigned getPlato() const;
    
    /**
     * @brief Consultor de nombre
     * @return string nombre
     */
    string getNombre() const;
    
    /**
     * @brief Consultor de calorias
     * @return double calorías
     */
    double getCalorias() const;
    
    /**
     * @brief Consultor de hidratos
     * @return double hidratos de carbono
     */
    double getHidratos() const;
    
    /**
     * @brief Consultor de grasas
     * @return double grasas
     */
    double getGrasas() const;
    
    /**
     * @brief Consultor de proteinas
     * @return double proteínas
     */
    double getProteinas() const;
    
    /**
     * @brief Consultor de fibra
     * @return double fibra
     */
    double getFibra() const;
    
    class iterador
    {
    private:
        list<pair<string, unsigned> >::iterator it;
        
    public:
        iterador(){
        }
        
        iterador(const iterador& og)
        {
            it = og.it;
        }
        
        ~iterador(){
        }
        
        iterador& operator=(const iterador& og)
        {
            it = og.it;
            return *this;
        }
        
        const pair<string, unsigned> operator*() const
        {
            return *it;
        }
        
        iterador& operator++()
        {
            it++;
            return *this;
        }
        
        iterador& operator--()
        {
            it--;
            return *this;
        }
        
        bool operator!=(const iterador& v)
        {
            return it!=v.it;
        }
        
        bool operator==(const iterador& v)
        {
            return it==v.it;
        }
        
        friend class receta;
    };
    
    class const_iterador
    {
    private:
        list<pair<string, unsigned> >::const_iterator it;
        
    public:
        const_iterador(){
        }
        
        const_iterador(const iterador& og)
        {
            it = og.it;
        }
        
        ~const_iterador(){
        }
        
        const_iterador& operator=(const iterador& og)
        {
            it = og.it;
            return *this;
        }
        
        const pair<string, unsigned> operator*() const
        {
            return *it;
        }
        
        const_iterador& operator++()
        {
            it++;
            return *this;
        }
        
        const_iterador& operator--()
        {
            it--;
            return *this;
        }
        
        bool operator!=(const const_iterador& v)
        {
            return it!=v.it;
        }
        
        bool operator==(const const_iterador& v)
        {
            return it==v.it;
        }
        
        friend class receta;
    };
    
    iterador begin()
    {
        iterador aux;
        aux.it = ings.begin();
        return aux;
    }
    
    iterador end()
    {
        iterador aux;
        aux.it = ings.end();
        return aux;
    }
    
    const_iterador begin() const
    {
        const_iterador aux;
        aux.it = ings.begin();
        return aux;
    }
    
    const_iterador end() const
    {
        const_iterador aux;
        aux.it = ings.end();
        return aux;
    }
    
    /**
     * @brief Sobrecarga del operador de asignación
     * @param og Receta a copiar
     * @return receta *this
     */
    receta& operator=(const receta& og);
};

/**
 * @brief Sobrecarga del operador de salida para receta
 * @param os Flujo de salida
 * @param rc Objeto receta
 * @return Flujo de salida os
 */
ostream & operator<<(ostream &os, const receta& rc);


/**
 * @brief Sobrecarga del operador de entrada para receta
 * @param is Flujo de entrada
 * @param rc Objeto receta
 * @return Flujo de entrada is
 */
istream & operator>>(istream &is, receta& rc);

#endif /* RECETA_H */