#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include "ingrediente.h"
#include "string.h"
#include <vector>
#include <assert.h>

using namespace std;

/**
  *  @brief T.D.A. Ingredientes
  *
  * Una instancia de @c Ingredientes es un objeto conjunto de ingredientes,
  * haciendo uso de un atributo de tipo Vector de Ingrediente 
  * (vector<ingrediente>), con cada objeto ingrediente ordenados por nombre, 
  * y otro atributo de tipo Vector de enteros (vector<int>),
  * con los indices de los ingredientes del vector anterior ordenados por
  * tipo.
  * 
  *
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  *
  * @author Sergio García Cabrera
  * @author Guillermo García Arredondo
  * @date Octubre 2019
  */

class ingredientes {

private:
    /**
    *  @page Representación del TDA Ingredientes
    * 
    *  @section faIngrediente Estado válido de un objeto Ingredientes
    *
    *  Un objeto válido del TDA posee un vector de la STL de ingrediente ordenados por nombre
    *  y otro vector de int con los índices de cada ingrediente del vector de ingrediente
    *  ordenados por tipo. Debe de haber correspondencia entre ambos vectores.
    *
    */
    
    vector<ingrediente> datos;
    vector<int> indice;

public:
    class iterador{
    private:
        /**
        *  @page Representación del iterador no constante para vector<ingrediente>
        *
        *  Para implementar nuestro iterador propio nos apoyamos en el iterator del vector de
        *  la stl así que usaremos un vector<ingrediente>::iterator.
        */       
        vector<ingrediente>::iterator it;
        
    public:
        
        /**
         * @brief Constructor por defecto del iterador
         */   
        iterador(){
            
        }
        
        /**
         * @brief Destructor del iterador
         */   
        ~iterador(){
            
        }
        
        /**
         * @brief Constructor copia
         * @param Otro objeto de la clase iterador
         */   
        iterador(const iterador& otro){
            it = otro.it;
        }
        
        /**
         * @brief Sobrecarga del operador =
         * @return Un iterador por referencia
         * @param Otro objeto de la clase iterador
         */   
        iterador& operator= (const iterador& orig){
            it = orig.it;
            return *this;
        }
        
        /**
         * @brief Sobrecarga del operador *
         * @return Un ingrediente por referencia
         */  
        ingrediente& operator*() const{
            return *it;
        }
        
        /**
         * @brief Sobrecarga del operador ++ para incrementar
         * el iterador en una posición
         * @return Un iterador por referencia
         */  
        iterador& operator++(){
            it++;
            return *this;
        }
        
        /**
         * @brief Sobrecarga del operador -- para decrementar
         * el iterador en una posición
         * @return Un iterador por referencia
         */          
        iterador& operator--(){
            it--;
            return *this;
        }
        
        /**
         * @brief Sobrecarga del operador !=
         * @param otro iterador
         * @return booleano indicando si los iteradores son iguales o no
         */
        bool operator !=(const iterador& otro) const{
            return !(*this==otro);
        }
        
        /**
         * @brief Sobrecarga del operador ==
         * @param otro iterador
         * @return booleano indicando si los iteradores son iguales o no
         */
        bool operator ==(const iterador& otro) const{
            return it == otro.it;
        }
               
        friend class ingredientes;
    };
    
    class const_iterador{
    private:
        
        /**
        *  @page Representación del const_iterador para vector<ingrediente>
        *
        *  Para implementar nuestro const_iterador propio nos apoyamos en el const_iterator del vector de
        *  la stl así que usaremos un vector<ingrediente>::const_iterator.
        */ 
        vector<ingrediente>::const_iterator it;
        
        /*const_iterador(vector<ingrediente>::const_iterator otro){     //Ver si sigue siendo necesario
            it = otro;
        }*/
        
    public:
        
        /**
         * @brief Constructor por defecto del const_iterador
         */
        const_iterador(){
            
        }
        
        /**
         * @brief Constructor copia
         * @param Otro objeto de la clase const_iterador
         */         
        const_iterador(const const_iterador& otro){
            it = otro.it;
        }
        
        /**
         * @brief Constructor copia
         * @param Un objeto de la clase iterador
         */        
        const_iterador(const iterador& otro){
            it = otro.it;
        }
        
        /**
         * @brief Destructor del const_iterador
         */   
        ~const_iterador(){
            
        }
        
        /**
         * @brief Sobrecarga del operador =
         * @return Un const_iterador por referencia
         * @param Otro objeto de la clase const_iterador
         */        
        const_iterador& operator=(const const_iterador& orig){
            it = orig.it;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador *
         * @return Un ingrediente por referencia
         */        
        const ingrediente& operator*() const{
            return *it;
        }
        
        /**
         * @brief Sobrecarga del operador ++ para incrementar
         * el const_iterador en una posición
         * @return Un const_iterador por referencia
         */        
        const_iterador &operator++(){
            it++;
            return *this;
        }
        
        /**
         * @brief Sobrecarga del operador -- para decrementar
         * el const_iterador en una posición
         * @return Un const_iterador por referencia
         */        
        const_iterador &operator--(){
            it--;
            return *this;
        }
        
        /**
         * @brief Sobrecarga del operador != 
         * @param Otro const_iterador
         * @return Booleano indicando si los const_iterador son iguales o no
         */        
        bool operator != (const const_iterador& otro) const{
            return it != otro.it;
        }
        
        /**
         * @brief Sobrecarga del operador ==
         * @param Otro const_iterador
         * @return Booleano indicando si los const_iterador son iguales o no
         */
        bool operator == (const const_iterador &otro) const{
            return it == otro.it;
        }
        
        friend class ingredientes;
    };
    
    /**
     * @brief Devuelve un iterador al comienzo del vector
     * de datos.
     * @return Un iterador
     */  
    iterador begin(){
        iterador aux;
        aux.it = datos.begin();
        return aux;
    }
    
    /**
     * @brief Devuelve un iterador al final del vector
     * de datos.
     * @return Un iterador
     */
    iterador end(){
        iterador aux;
        aux.it = datos.end();
        return aux;
    }
    
    /**
     * @brief Devuelve un const_iterador al comienzo del vector
     * de datos.
     * @return Un const_iterador
     */ 
    const_iterador begin() const{
        const_iterador aux;
        aux.it = datos.begin();
        return aux;        
    }
    
    /**
     * @brief Devuelve un const_iterador al final del vector
     * de datos.
     * @return Un const_iterador
     */
    const_iterador end() const{
        const_iterador aux;
        aux.it = datos.end();
        return aux;          
    }
    
    /**
     * @brief Añade el ingrediente al vector de datos de forma ordenada
     * @return Posición en la que el ingrediente ha sido añadido
     * @param Ingrediente a añadir
     */    
    unsigned aniadirordenadoDatos(const ingrediente& dato);
    
    /**
     * @brief Constructor por defecto de la clase.
     */
    ingredientes();
    
    /**
     * @brief Se encarga de llamar a las funciones correspondientes para
     * añadir un ingrediente de forma ordenada al vector datos y luego
     * añadir el indice correspondiente al vector de indice.
     * @param Ingrediente ingr a añadir
     */
    void aniadiringrediente(const ingrediente& ingr);
    
    /**
     * @brief Añade el índice recibido en el vector<int> indice según orden de tipos
     * @param pos_d Índice del ingrediente en el vector de datos
     * @pre Siempre se debe llamar después de aniadiringrediente
     */
    void aniadirindice(unsigned pos_d);
    
    /**
     * @brief Elimina el ingrediente de nombre n
     * @param string n Nombre del ingrediente
     */
    void borrar(string &n);
    
    /**
     * @brief Consultor del util (número de elementos) del VD de ingredientes
     * @return util del VD de tipo const unsigned
     */
    const unsigned size() const;
    
    /**
     * @brief Devuelve el ingrediente que tenga el nombre recibido como parámetro
     * @param string n Nombre del ingrediente
     * @return ingrediente con el nombre en cuestión
     */
    ingrediente get(const string &n);
    
    /**
     * @brief Introduce en una nueva colección de ingredientes todos los que
     * tengan el mismo tipo al recibido como parámetro y la devuelve
     * @param t Tipo de ingrediente
     * @return Colección de ingredientes del mismo tipo
     */
    ingredientes getIngredienteTipo(const string t);
    
    /**
     * @brief Modificador de la clase
     * @param Índice i de tipo unsigned
     * @return Objeto de tipo ingrediente que se encuentra en la
     * posición indicada por el parámetro i
     */
    ingrediente& operator[] (unsigned i);
    
    /**
     * @brief Consultor de la clase
     * @param Índice i de tipo unsigned
     * @return Objeto de tipo constante ingrediente que se encuentra en la
     * posición indicada por el parámetro i
     */
    const ingrediente& operator[] (unsigned i) const;
    
    /**
     * @brief Introduce en un Vector de string los tipos de ingredientes presentes en el
     * vector datos ordenados alfabéticamente y sin repetir
     * @return Vector de string con los tipos presentes en la instancia
     */
    vector<string> getTipos();
    
    /**
     * @brief Imprime en pantalla los ingredientes ordenados por tipo
     * @param os Flujo de salida
     */
    void ImprimirPorTipo(std::ostream &os);
};

/**
 * @brief Sobrecarga del operador flujo de salida para la clase ingredientes
 * @param flujo de salida os
 * @param ingredientes ingrs
 * @return flujo de salida
 */
std::ostream & operator<<(std::ostream &os, const ingredientes& ingrs);
    
/**
 * @brief Sobrecarga del operador flujo de entrada para la clase ingredientes
 * @param flujo de entrada is
 * @param ingredientes ingrs
 * @return flujo de entrada
 */
std::istream & operator>>(std::istream &is, ingredientes& ingrs);

#endif /* INGREDIENTES_H */
