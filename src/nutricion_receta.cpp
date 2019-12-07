#include "recetas.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    ingredientes ingrs;
    recetas rcs;
    if (argc != 4)
    {
        cout << "Hay que especificar dos archivos y una cifra.\n";
        return -1;
    }
    
    string rnf = argv[1], inf = argv[2];
    ifstream f1(rnf), f2(inf);
    
    f1 >> rcs;
    f2 >> ingrs;
    rcs.establecerNutrientes(ingrs);
    rcs.mostrarRecetas();
    
    recetas resultado;
    receta aux;
    double mayor = 0, max = stoi(argv[3], nullptr, 10);
    for (recetas::iterador i = rcs.begin(); i != rcs.end(); ++i)
    {
        aux = (*i).second;
        if (aux.getProteinas()/aux.getHidratos() >= mayor && aux.getCalorias() <= max)
        {
            mayor = aux.getCalorias()/aux.getHidratos();
            resultado.aniadirReceta(aux);
        }
    }
    
    cout << "\nLas recetas escogidas son: \n" << resultado;
    cout << "\nCalorias Totales: " << resultado.getCaloriasTotales() << "\t" << "Proteinas totales: " << resultado.getProteinasTotales() << endl;
    
    return 0;
}