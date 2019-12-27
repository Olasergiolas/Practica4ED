#include "recetas.h"

recetas::recetas(){
}

recetas::recetas(const recetas& og)
{
    datos = og.datos;
}

recetas::~recetas(){
}

void recetas::aniadirReceta(receta rc)
{
    pair<string, receta> aux;
    aux.first = rc.getCode();
    aux.second = rc;
    datos.insert(aux);
}

void recetas::borrar(string code)
{
    bool encontrado = false;
    recetas::iterador itr;
    for (recetas::iterador i = begin(); i != end() && !encontrado; ++i)
    {
        if (code == (*i).first)
        {
            encontrado = true;
            itr = i;
        }
    }
    
    if (encontrado)
        datos.erase(itr.it);
}

unsigned recetas::size() const
{
    unsigned contador = 0;
    for (recetas::const_iterador i = begin(); i != end(); ++i)
        contador++;
    return contador;
}

receta recetas::operator[](string code) const
{
    bool encontrado = false;
    receta rc;
    
    for (recetas::const_iterador i = begin(); i != end() && !encontrado; ++i)
    {
        if (code == (*i).first)
        {
            encontrado = true;
            rc = (*i).second;
        }
    }
    
    return rc;
}

void recetas::establecerNutrientes(const ingredientes& ingrs)
{
    for (map<string, receta>::iterator i = datos.begin(); i != datos.end(); ++i)
        (*i).second.establecerNutrientes(ingrs);
}

void recetas::setInstrucciones(const Instrucciones& ins, string code)
{
    bool encontrado = false;
    for (map<string, receta>::iterator i = datos.begin(); i != datos.end() && !encontrado; ++i)
    {
        if (i->first.compare(code) == 0)
        {
            encontrado = true;
            i->second.setInstrucciones(ins);
        }
    }
}

void recetas::mostrarRecetas() const
{
    receta aux;
    cout << "\nConjuto de recetas: \n";
    for (recetas::const_iterador i = begin(); i != end(); ++i)
    {
        aux = (*i).second;
        cout << "\nValores Nutricionales de la receta: " << aux << endl;
        cout << "Calorias " << aux.getCalorias() << "\t";
        cout << "Hidratos de Carb. " << aux.getHidratos() << "\t";
        cout << "Proteinas " << aux.getProteinas() << "\t";
        cout << "Grasas " << aux.getGrasas() << "\t";
        cout << "Fibra " << aux.getFibra() << endl;
    }
}

double recetas::getCaloriasTotales() const
{
    double result = 0;
    for (recetas::const_iterador i = begin(); i != end(); ++i)
        result += (*i).second.getCalorias();
    return result;
}

double recetas::getProteinasTotales() const
{
    double result = 0;
    for (recetas::const_iterador i = begin(); i != end(); ++i)
        result += (*i).second.getProteinas();
    return result;
}

ostream & operator<<(ostream &os, const recetas& rcs)
{
    for (recetas::const_iterador i = rcs.begin(); i != rcs.end(); ++i)
        os << (*i).second << endl;
    
    return os;
}

istream & operator>>(istream &is, recetas& rcs)
{
    receta aux;
    while (is >> aux)
        rcs.aniadirReceta(aux);
    
    return is;
}
