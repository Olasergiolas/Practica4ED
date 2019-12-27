#ifndef RECETAS_H
#define RECETAS_H

#include "receta.h"
#include <string>
#include <map>
using namespace std;

/**
 * @brief T.D.A. Recetas
 * 
 * Una instancia @c Recetas es una colección de objetos de la clase
 * receta ordenados alfabéticamente por código.
 * 
 * Un ejemplo de su uso:
 * @include test_receta.cpp
 * 
 * @author Guillermo García Arredondo
 * @author Sergio García Cabrera
 * @date Noviembre 2019
 */

class recetas
{
private:
    /**
     * @page Representación del TDA Recetas
     * 
     * @section Estado válido de un objeto Recetas
     * 
     * Un objeto válido del TDA posee una colección de
     * recetas ordenada por nombre 
     */
    map<string, receta> datos;
    
public:
    /**
     * @brief Constructor por defecto
     */
    recetas();
    
    /**
     * @brief Constructor copia
     * @param og receta a copiar
     */
    recetas(const recetas& og);
    
    /**
     * @brief Destructor por defecto
     */
    ~recetas();
    
    /**
     * @brief Añade una receta a la colección
     * @param rc Receta a añadir
     */
    void aniadirReceta(receta rc);
    
    /**
     * @brief Elimina una receta contenida en la colección
     * @param code Código de la receta a eliminar
     */
    void borrar(string code);
    
    /**
     * @brief Número de recetas en la colección
     * @return unsigned int del total
     */
    unsigned size() const;
    
    /**
     * @brief Calcula las calorías que aportan todas las receta de la 
     * colección en total y lo devuelve
     * @return double total de calorías
     */
    double getCaloriasTotales() const;
    
    /**
     * @brief Calcula las proteínas que aportan todas las receta de la 
     * colección en total y lo devuelve
     * @return double total de proteínas
     */
    double getProteinasTotales() const;
    
    /**
     * @brief Establece los nutrientes totales que aporta cada receta
     * de la colección
     * @param ingrs Objeto ingredientes de donde obtener los nutrientes que
     * aporta cada ingrediente
     */
    void establecerNutrientes(const ingredientes& ingrs);
    
    /**
     * @brief Establece las instrucciones para poder elaborar una receta concreta
     * @param ins Instrucciones
     * @param code Código de la receta a la que establecer instrucciones
     */
    void setInstrucciones(const Instrucciones& ins, string code);
    
    /**
     * @brief Muestra todas las recetas de la colección junto a sus
     * respectivos valores nutricionales
     */
    void mostrarRecetas() const;
    
    /**
     * @brief Consultor con corchetes de recetas; si la encuentra devuelve
     * una copia de la receta con el código recibido como parámetro, si no
     * devuelve una receta inválida.
     * @param code Código de la receta a devolver
     * @return receta
     */
    receta operator[](string code) const;
    
    class iterador
    {
    private:
        map<string, receta>::iterator it;
        
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
        
        pair<string, receta> operator*()
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
        
        friend class recetas;
    };
    
    class const_iterador
    {
    private:
        map<string, receta>::const_iterator it;
        
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
        
        const pair<string, receta> operator*() const
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
        
        friend class recetas;
    };
    
    iterador begin()
    {
        iterador aux;
        aux.it = datos.begin();
        return aux;
    }
    
    iterador end()
    {
        iterador aux;
        aux.it = datos.end();
        return aux;
    }
    
    const_iterador begin() const
    {
        const_iterador aux;
        aux.it = datos.begin();
        return aux;
    }
    
    const_iterador end() const
    {
        const_iterador aux;
        aux.it = datos.end();
        return aux;
    }
};

/**
 * @brief Sobrecarga del operador de salida para recetas
 * @param os Flujo de salida
 * @param rcs objeto recetas
 * @return Flujo de salida os
 */
ostream & operator<<(ostream &os, const recetas& rcs);

/**
 * @brief Sobrecarga del operador de entrada para recetas
 * @param is Flujo de entrada
 * @param rcs objeto recetas
 * @return Flujo de entrada is
 */
istream & operator>>(istream &is, recetas& rcs);

#endif /* RECETAS_H */

