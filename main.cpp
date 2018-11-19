
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

using namespace std;

#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "cls"
#endif // __MINGW32__

struct cliente
{
    string codigo;
    string nombre;
    string apellidos;
    string celular;
};

list<cliente> clientes;

//GENERAR MENU SUPERIOR
void menu_superior()
{
    system(LIMPIAR);

    string menu_superior = "";
    menu_superior += "========================================================\n";
    menu_superior += "              LACTEOS DEL CARIBE LIMITADA\n";
    menu_superior += "   SISTEMA DE INFORMACION GERENCIAL - MODULO DE VENTA\n";
    menu_superior += "           CURSO PROGRAMACION ESTRUCTURADA\n";
    menu_superior += "            ESTUDIANTE: \n";
    menu_superior += "========================================================\n\n\n\n\n";
    cout << menu_superior;
}

//GENERAR MENU INFERIOR SEGUN SELECCION
string menu_inferior(int respuesta)
{
    string menu_inferior = "";
    switch (respuesta)
    {
    case 1:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- INGRESAR CLIENTE\n ";
        menu_inferior += "                2- BUSCAR CLIENTE\n ";
        menu_inferior += "                3- ACTUALIZAR CLIENTE\n ";
        menu_inferior += "                4- ELIMINAR CLIENTE\n ";
        menu_inferior += "                5- CREAR ARCHIVO\n ";
        menu_inferior += "                6- RECUPERAR DATOS\n ";
        menu_inferior += "                7- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    case 2:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- INGRESAR PRODUCTO\n ";
        menu_inferior += "                2- BUSCAR PRODUCTO\n ";
        menu_inferior += "                3- ELIMINAR PRODUCTO\n ";
        menu_inferior += "                4- ACTUALIZAR PRODUCTO\n ";
        menu_inferior += "                5- BUSCAR EL PRODUCTO MAS ECONOMICO\n ";
        menu_inferior += "                6- BUSCAR EL PRODUCTO MAS COSTOSO\n ";
        menu_inferior += "                7- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    case 3:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- INGRESAR FACTURA\n ";
        menu_inferior += "                2- MOSTRAR FACTURA\n ";
        menu_inferior += "                3- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    case 4:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- INGRESAR PEDIDO\n ";
        menu_inferior += "                2- MOSTRAR PEDIDO\n ";
        menu_inferior += "                3- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    case 5:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- INGRESAR EMPLEADOS X EDAD\n ";
        menu_inferior += "                2- BUSCAR EMPLEADO X EDAD\n ";
        menu_inferior += "                3- BUSCAR EMPLEADO X EDAD\n ";
        menu_inferior += "                4- RECORRER ARBOL EN PRE ORDEN\n ";
        menu_inferior += "                5- RECORRER ARBOL EN IN ORDEN\n ";
        menu_inferior += "                6- RECORRER ARBOL EN POST ORDEN\n ";
        menu_inferior += "                7- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    default:
        menu_inferior += "                  MENU\n ";
        menu_inferior += "                1- CLIENTE\n ";
        menu_inferior += "                2- PRODUCTOS\n ";
        menu_inferior += "                3- FACTURAS\n ";
        menu_inferior += "                4- PEDIDOS\n ";
        menu_inferior += "                5- EMPLEADOS\n ";
        menu_inferior += "                6- SALIR\n ";
        menu_inferior += "             ELIJA UNA OPCION [ ]\n\t\t\t";
        break;
    }
    return menu_inferior;
}

//Validar que la seleccion del primer menu sea correcta
bool valida(int respuesta)
{
    if (respuesta != 1 && respuesta != 2 && respuesta != 3 && respuesta != 4 && respuesta != 5)
    {
        return false;
    }
    return true;
}

//Validar que la seleccion del segundo menu sea correcta
bool valida2(int r1, int r2)
{
    bool respuesta = false;
    switch (r1)
    {
    case 1:
    case 2:
    case 5:
        if (r2 == 1 || r2 == 2 || r2 == 3 || r2 == 4 || r2 == 5 || r2 == 6 || r2 == 7)
        {
            respuesta = true;
        }
        break;
    case 3:
    case 4:
        if (r2 == 1 || r2 == 2 || r2 == 3)
        {
            respuesta = true;
        }
        break;
    default:
        break;
    }
    return respuesta;
}

//Imprimir los menus
void imprimir(int respuesta, bool invalid = false)
{
    menu_superior();
    if (invalid)
    {
        cout << "           OPCION INVALIDA \n\n";
    }
    cout << menu_inferior(respuesta);
}

void ingresar_cliente()
{
    menu_superior();
    string codigo, nombre, apellidos, celular,confirm;
    cout << "           Ingrese el codigo del cliente: ";
    cin >> codigo;
    cout << endl
         << "           Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << endl
         << "           Ingrese el apellidos del cliente: ";
    cin >> apellidos;
    cout << endl
         << "           Ingrese el celular del cliente: ";
    cin >> celular;
    cliente cli;
    cli.codigo = codigo;
    cli.nombre = nombre;
    cli.apellidos = apellidos;
    cli.celular = celular;
    clientes.push_back(cli);
    cout << "              Cliente registrado";
    cin.get();
    cin.ignore(100,'\n'); 

}

void buscar_clientes()
{
    menu_superior();
    string codigo;
    cout << "      Ingrese el codigo del cliente a buscar o 0 para consultarlos todos: ";
    cin >> codigo;
    list<cliente>::iterator it;
    cout << endl;
    if (codigo == "0")
    {
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            cout << "----------------------------" << endl;
            cout << "Codigo: " << it->codigo << endl;
            cout << "Nombre: " << it->nombre << endl;
            cout << "Apellidos: " << it->apellidos << endl;
            cout << "Celular: " << it->celular << endl;
            cout << "----------------------------" << endl;
        }
    }
    else
    {
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            if (codigo == it->codigo)
            {
                cout << "----------------------------" << endl;
                cout << "Codigo: " << it->codigo << endl;
                cout << "Nombre: " << it->nombre << endl;
                cout << "Apellidos: " << it->apellidos << endl;
                cout << "Celular: " << it->celular << endl;
                cout << "----------------------------" << endl;
            }
        }
    }
    cin.get();
    cin.ignore(100,'\n'); 
}

//Logica de los clientes
void menu_clientes(int respuesta)
{

    switch (respuesta)
    {
    case 1:
        ingresar_cliente();
        break;
    case 2:
        buscar_clientes();
    default:
        break;
    }
}

//Logica de los productos
void menu_productos(int respuesta)
{
}

//Logica de las facturas
void menu_facturas(int respuesta)
{
}

//Logica de los pedidos
void menu_pedidos(int respuesta)
{
}

//Logica de los empleados
void menu_empleados(int respuesta)
{
}

// seleccionar la logica segun la opcion elegida
void menus(int r1, int r2)
{

    switch (r1)
    {
    case 1:
        menu_clientes(r2);
        break;
    case 2:
        menu_productos(r2);
        break;
    case 3:
        menu_facturas(r2);
        break;
    case 4:
        menu_pedidos(r2);
        break;
    case 5:
        menu_empleados(r2);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    int respuesta = 0;
    bool invalid = false;

    while (respuesta != 6)
    {
        imprimir(respuesta, invalid);
        invalid = false;
        cin >> respuesta;
        if (!valida(respuesta))
        {
            invalid = true;
            continue;
        }
        int respuesta_2;
        bool invalid2 = false;
        do
        {
            imprimir(respuesta, invalid2);
            cin >> respuesta_2;
            invalid2 = true;
        } while (!valida2(respuesta, respuesta_2));

        menus(respuesta, respuesta_2);
        respuesta = 0;
    }

    return 0;
}
