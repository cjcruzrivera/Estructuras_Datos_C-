
#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace std;

#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__
 
#ifdef __MINGW32__
#define LIMPIAR "cls"
#endif // __MINGW32__
 



int main(int argc, char **argv)
{
    int respuesta = 1;
    string menu_superior, menu_inferior = "";
    menu_superior += "========================================================\n";
    menu_superior += "              LACTEOS DEL CARIBE LIMITADA\n";
    menu_superior += "   SISTEMA DE INFORMACION GERENCIAL - MODULO DE VENTA\n";
    menu_superior += "           CURSO PROGRAMACION ESTRUCTURADA\n";
    menu_superior += "            ESTUDIANTE: \n";
    menu_superior += "========================================================\n\n\n\n\n";
    
    menu_inferior += "                  MENU\n ";
    menu_inferior += "                1- CLIENTE\n ";
    menu_inferior += "                2- PRODUCTOS\n ";
    menu_inferior += "                3- FACTURAS\n ";
    menu_inferior += "                4- PEDIDOS\n ";
    menu_inferior += "                5- EMPLEADOS\n ";
    menu_inferior += "                6- SALIR\n ";
    menu_inferior += "             ELIJA UNA OPCION [ ] \n ";
    
    while (respuesta != 6)
    {   
        system(LIMPIAR);
        cout << menu_superior;
        cout << menu_inferior;
        cin >> respuesta;
    }

    return 0;
}
