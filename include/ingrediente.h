#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include<iostream>

using namespace std;

/**
  *  @brief T.D.A. Ingrediente
  *
  * Una instancia de @c Ingrediente es un objeto que intenta representar un
  * ingrediente alimenticio, formado por un nombre, el n. de calorías/100g, su
  * tipo y sus porcentajes de hidratos de carbono, proteínas, grasas y fibra.
  * 
  *
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  *
  * @author Sergio García Cabrera
  * @author Guillermo García Arredondo
  * @date Octubre 2019
  */


class ingrediente {
private:
    
/**
  *  @page Representación del TDA Ingrediente
  * 
  *  @section faIngrediente Estado válido de un Ingrediente
  *
  *  Un objeto válido del TDA posee las características de
  *  un ingrediente en la vida real, con un nombre y un tipo real
  *  y unos porcentajes entre 0-100 cuya suma total sea 100%.
  *
  */
    
    string nombre;
    double nCalx100;
    double v[4];
    string tipo;

public:
    /**
    * @brief Constructor por defecto de la clase, crea un ingrediente inválido
    */    
    ingrediente();
    
    /**
    * @brief Constructor con parámetros de la clase
    * @param n Nombre del ingrediente
    * @param nCal  Número de calorías/100g
    * @param hc    Porcentaje de Hidratos de carbono
    * @param prot  Porcentaje de Proteínas
    * @param gra   Porcentaje de Grasas
    * @param fib   Porcentaje de Fibra
    * @param t     Tipo del ingrediente
    * @return      Crea el ingrediente con dichos parámetros
    * @pre         Suma de los porcentajes <= 100
    */  
    ingrediente(const char* n, const double& nCal, const double& hc, const double& prot, const double& gra, const double& fib, const char* t);
      
    /**
     * @brief Nombre
     * @return Devuelve un string con el nombre del ingrediente
     */  
    string getNombre() const;
    
    /**
     * @brief Calorías
     * @return Devuelve un double con las calorías
     */
    double getCalorias() const;
    
    /**
     * @brief Hidratos de Carbono
     * @return Devuelve un double con el porcentaje de hidratos de carbono
     */    
    double getHc() const;
    
    /**
     * @brief Proteínas
     * @return Devuelve un double con el porcentaje de proteínas
     */
    double getProteinas() const;
    
    /**
     * @brief Grasas
     * @return Devuelve un double con el porcentaje de grasas
     */    
    double getGrasas() const;
    
    /**
     * @brief Fibra
     * @return Devuelve un double con el porcentaje de fibra
     */    
    double getFibra() const;
    
    /**
     * @brief Tipo
     * @return Devuelve un string con el tipo de alimento que es
     */     
    string getTipo() const;
    
    /**
    * @brief   Sobrecarga del operador mayor estricto según el orden alfabético para el nombre
    * @param   ingrediente otro
    * @return  Devuelve true si el nombre del objeto otro es posterior alfabéticamente al this, devuelve false en el caso contrario o si son iguales
     */
    bool operator>(const ingrediente& otro) const;
    
    
    /**
     * @brief Sobrecarga del operador desigual
     * @param ingrediente otro
     * @return Devuelve true si tienen el mismo nombre y false en el caso contrario
     */
    bool operator!=(const ingrediente& otro) const;
};

/**
 * @brief   Sobrecarga operador flujo de entrada para la clase ingrediente
 * @param   flujo de entrada i
 * @param   ingrediente otro
 * @return  flujo de entrada i
 */
istream& operator>> (istream &i, ingrediente &otro);

/**
 * @brief  Sobrecarga operador flujo de salida para la clase ingrediente
 * @param  flujo de salida o
 * @param  ingrediente otro
 * @return flujo de salida o
 */
ostream& operator<< (ostream &o, const ingrediente &otro);

#endif /* INGREDIENTE_H */
