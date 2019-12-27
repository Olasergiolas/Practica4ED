#include <fstream>
#include "instrucciones.h"
#include "ingredientes.h"
#include "recetas.h"

using namespace std;

int main(int argc, char** argv) {
    recetas rcs;
    ingredientes ingrs;
    Acciones acc;
    
    if (argc != 5)
    {
        cout << "Se requieren cuatro argumentos.\n";
        return -1;
    }
    
    ifstream a(argv[1]), r(argv[2]), in(argv[3]), inst;
    a >> acc;
    r >> rcs;
    in >> ingrs;
    
    rcs.establecerNutrientes(ingrs);
    
    string path;
    //establece las instrucciones de las recetas a la vez que muestra el código, nombre y número de cada una
    for (recetas::const_iterador i = rcs.begin(); i != rcs.end(); ++i)
    {
        path = argv[4];
        path.append((*i).first);
        path.append("m.txt");
        inst.open(path);
        Instrucciones instruc(acc);
        inst >> instruc;
        rcs.setInstrucciones(instruc, (*i).first);
        inst.close();
        
        cout << "CODE: " << (*i).first << "\tNOMBRE: " << (*i).second.getNombre() << "\tPLATO: " << (*i).second.getPlato() << endl;
    }
    
    string code;
    cout << "\n\nIntroduzca el código de una receta: \n";
    cin >> code;
    if (rcs[code].getPlato() == 0)
        cout << "No existe la receta con código " << code << endl;
    else
    {
        cout << "\nCODE: " << rcs[code].getCode() << "\tRECETA: " << rcs[code].getNombre() << "\tPLATO: " << rcs[code].getPlato() << endl;
        cout << "\nIngredientes: \n\n";
        rcs[code].mostrarIngredientes();
        cout << "\nInformación Nutricional: \n\n";
        rcs[code].mostrarInformacionNutricional();
        cout << "\nPasos a seguir: \n\n";
        rcs[code].mostrarInstrucciones();
    }
    
    return 0;
}