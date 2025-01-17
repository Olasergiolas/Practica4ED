#include "receta.h"
#include "ingredientes.h"
#include <string>
#include <cctype>

receta::receta(){
    code = "Undefined";
    plato = 0;
    nombre = "Undefined";
    calorias = 0;
    hidratos = 0;
    grasas = 0;
    proteinas = 0;
    fibra = 0;
}

receta::receta(string c, unsigned p, string n)
{
    code = c;
    plato = p;
    nombre = n;
    calorias = 0;
    hidratos = 0;
    grasas = 0;
    proteinas = 0;
    fibra = 0;
}

receta::receta(const receta& og)
{
    code = og.code;
    plato = og.plato;
    nombre = og.nombre;
    ings = og.ings;
    calorias = og.calorias;
    hidratos = og.hidratos;
    grasas = og.grasas;
    proteinas = og.proteinas;
    fibra = og.fibra;
    inst = og.inst;
}

receta::~receta(){
}

void receta::aniadirIngrediente(pair<string,unsigned> ingr)
{
    bool encontrado = false;
    for (list<pair<string, unsigned> >::iterator i = ings.begin(); i != ings.end() && !encontrado; ++i)
    {
        if (i->first.compare(ingr.first) == 0)
        {
            encontrado = true;
            i->second += ingr.second;
        }
    }
    if (!encontrado)
        ings.insert(end().it, ingr);
}

pair<bool,string> receta::comprobarIngredientes(ingredientes& ingrs) const
{
    pair<bool,string> result;
    bool aux = true;
    for (receta::const_iterador i = begin(); i != end() && aux; ++i)
    {
        if (ingrs.get((*i).first).getNombre().compare("null") == 0)
        {
            aux = false;
            result.second = (*i).first;
        }
    }
    result.first = aux;
    
    return result;
}

void receta::establecerNutrientes(const ingredientes& ingrs)
{
    string i_name, aux;
    ingrediente r;
    double valor;
    bool encontrado;
    for (ingredientes::const_iterador i = ingrs.begin(); i != ingrs.end(); ++i)
    {
        i_name = (*i).getNombre();
        r = *i;
        encontrado = false;
        for (receta::const_iterador j = begin(); j != end() && !encontrado; ++j)
        {
            valor = (*j).second/100.0;
            aux = (*j).first;
            if (i_name.compare(aux) == 0)
            {
                calorias += (*i).getCalorias()*valor;
                hidratos += (*i).getHc()*valor;
                grasas += (*i).getGrasas()*valor;
                proteinas += (*i).getProteinas()*valor;
                fibra += (*i).getFibra()*valor;
                encontrado = true;
            }
        }
    }
}

void receta::setInstrucciones(const Instrucciones& ins)
{
    inst = ins;
}

void receta::mostrarIngredientes() const
{
    for (receta::const_iterador i = begin(); i != end(); ++i)
        cout << (*i).first << " " << (*i).second << endl;
    
}

void receta::mostrarInformacionNutricional() const
{
    cout << "Calorias: " << calorias << endl;
    cout << "Hidratos de Carbono: " << hidratos << endl;
    cout << "Grasas: " << grasas << endl;
    cout << "Proteinas: " << proteinas << endl;
    cout << "Fibra: " << fibra << endl;
}

void receta::mostrarInstrucciones()
{
    cout << inst << endl;
}

receta receta::fusionarRecetas(const receta& rc)
{
    receta result;
    if (plato == rc.plato)
    {
        string cod = "F_";
        cod.append(code);
        cod.append("_");
        cod.append(rc.code);

        string name = "Fusion ";
        name.append(nombre);
        name.append(" y ");
        name.append(rc.nombre);

        result.code = cod;
        result.nombre = name;
        result.plato = plato;
        result.calorias = calorias + rc.calorias;
        result.hidratos = hidratos + rc.hidratos;
        result.grasas = grasas + rc.grasas;
        result.proteinas = proteinas + rc.proteinas;
        result.fibra = fibra + rc.fibra;

        for (receta::const_iterador i = begin(); i != end(); ++i)
            result.aniadirIngrediente(*i);
        for (receta::const_iterador i = rc.begin(); i != rc.end(); ++i)
            result.aniadirIngrediente(*i);

        result.inst = inst.fusionarInstrucciones(rc.inst);
    }
    
    return result;
}

unsigned receta::ningredientes() const
{
    unsigned contador = 0;
    for (receta::const_iterador i = begin(); i != end(); ++i)
        contador++;
    return contador;
}

string receta::getCode() const
{
    return code;
}

unsigned receta::getPlato() const
{
    return plato;
}

string receta::getNombre() const
{
    return nombre;
}

double receta::getCalorias() const
{
    return calorias;
}

double receta::getHidratos() const
{
    return hidratos;
}

double receta::getGrasas() const
{
    return grasas;
}
double receta::getProteinas() const
{
    return proteinas;
}

double receta::getFibra() const
{
    return fibra;
}

receta& receta::operator=(const receta& og)
{
    code = og.code;
    plato = og.plato;
    nombre = og.nombre;
    ings = og.ings;
    calorias = og.calorias;
    hidratos = og.hidratos;
    grasas = og.grasas;
    proteinas = og.proteinas;
    fibra = og.fibra;
    inst = og.inst;
    return *this;
}

ostream & operator<<(ostream &os, const receta& rc)
{
    os << rc.getCode() << ";" << rc.getPlato() << ";" << rc.getNombre();
    for (receta::const_iterador i = rc.begin(); i != rc.end(); ++i)
    {
        os << ";" << (*i).first << " " << (*i).second;
    }
    return os;
}

istream & operator>>(istream &is, receta& rc)
{
    pair<string, unsigned> aux;
    string s_aux, digito;
    
    string line;
    string::iterator itr;
    
    string codigo;
    unsigned num_plato;
    string name;
    
    getline(is, line);
    if (!line.empty())
    {
        for (itr = line.begin(); *itr != ';'; ++itr)
            codigo.push_back(*itr);
        itr++;
        num_plato = atoi(itr.base());
        itr += 2;

        for (; *itr != ';'; ++itr)
            name.push_back(*itr);

        rc = receta(codigo, num_plato, name);

        itr++;
        while (itr != line.end())
        {
            digito.clear();
            s_aux.clear();
            for (; *itr != ';' && itr != line.end(); ++itr)
            {
                if (isdigit(*itr) != 0)
                    digito.push_back(*itr);
                else
                    s_aux.push_back(*itr);
            }
            s_aux.erase(s_aux.end()-1);
            if (itr != line.end())
                itr++;
            aux.first = s_aux;
            aux.second = stoi(digito, nullptr, 10);
            rc.aniadirIngrediente(aux);
        }
    }
    
    return is;
}