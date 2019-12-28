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
    Instrucciones instruc(acc);
    
    rcs.establecerNutrientes(ingrs);
    
    string path;
    //establece las instrucciones de las recetas a la vez que muestra el código, nombre y número de cada una
    for (recetas::const_iterador i = rcs.begin(); i != rcs.end(); ++i)
    {
        path = argv[4];
        path.append((*i).first);
        path.append("m.txt");
        inst.open(path);
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
    
    receta fusion;
    string code2;
    cout << "\nIntroduzca el código de dos recetas para fusionar: \n";
    cin >> code >> code2;
    
    if (rcs[code].getPlato() == 0)
        cout << "No existe la receta con código " << code << endl;
    else if (rcs[code2].getPlato() == 0)
        cout << "No existe la receta con código " << code2 << endl;
    else if (!rcs[code].comprobarIngredientes(ingrs).first)
        cout << "La receta " << code << " es errónea porque el ingrediente " << rcs[code].comprobarIngredientes(ingrs).second << " no existe en la colección.\n";
    else if (!rcs[code2].comprobarIngredientes(ingrs).first)
        cout << "La receta " << code2 << " es errónea porque el ingrediente " << rcs[code2].comprobarIngredientes(ingrs).second << " no existe en la colección.\n";
    else if (rcs[code].getPlato() != rcs[code2].getPlato())
        cout << "No se puede fusionar una receta de tipo " << rcs[code].getPlato() << " con otra de tipo " << rcs[code2].getPlato() << endl;
    else
    {
        fusion = rcs[code].fusionarRecetas(rcs[code2]);
        
        cout << "\nCODE: " << fusion.getCode() << "\tRECETA: " << fusion.getNombre() << "\tPLATO: " << fusion.getPlato() << endl;
        cout << "\nIngredientes: \n\n";
        fusion.mostrarIngredientes();
        cout << "\nInformación Nutricional: \n\n";
        fusion.mostrarInformacionNutricional();
        cout << "\nPasos a seguir: \n\n";
        fusion.mostrarInstrucciones();
    }
    
    return 0;
}