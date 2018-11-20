#include "main.hpp"


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


/////////////////////////////////
//   Logica de los menus      //
/////////////////////////////////
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

/////////////////////////////////
//   Logica de los clientes    //
/////////////////////////////////
void ingresar_cliente()
{
    menu_superior();
    string codigo, nombre, apellido, celular;
    cout << "           Ingrese el codigo del cliente: ";
    cin >> codigo;
    cout << endl
         << "           Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << endl
         << "           Ingrese el apellido del cliente: ";
    cin >> apellido;
    cout << endl
         << "           Ingrese el celular del cliente: ";
    cin >> celular;
    cliente cli;
    cli.codigo = codigo;
    cli.nombre = nombre;
    cli.apellido = apellido;
    cli.celular = celular;
    clientes.push_back(cli);
    cout << "              Cliente registrado";
    cin.get();
    cin.ignore(100, '\n');
}

void buscar_clientes()
{
    menu_superior();
    string codigo;
    if (clientes.empty())
    {
        cout << "-----------------------------------------------" << endl;
        cout << "         NO HAY CLIENTES REGISTRADOS" << endl
             << "-----------------------------------------------" << endl;
    }
    else
    {
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
                cout << "Apellido: " << it->apellido << endl;
                cout << "Celular: " << it->celular << endl;
                cout << "----------------------------" << endl;
            }
        }
        else
        {
            if (clientes.empty())
            {
                cout << "-----------------------------------------------" << endl;
                cout << "         NO HAY CLIENTES REGISTRADOS" << endl
                     << "-----------------------------------------------" << endl;
            }
            else
            {
                bool exist = false;
                for (it = clientes.begin(); it != clientes.end(); it++)
                {
                    if (codigo == it->codigo)
                    {
                        exist = true;
                        cout << "----------------------------" << endl;
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nombre: " << it->nombre << endl;
                        cout << "Apellido: " << it->apellido << endl;
                        cout << "Celular: " << it->celular << endl;
                        cout << "----------------------------" << endl;
                    }
                }
                if (!exist)
                {
                    cout << "----------------------------------------------------------------" << endl;
                    cout << "         NO HAY CLIENTES REGISTRADOS CON ESE CODIGO" << endl
                         << "----------------------------------------------------------------" << endl;
                }
            }
        }
    }
    cin.get();
    cin.ignore(100, '\n');
}

void actualizar_cliente()
{
    menu_superior();
    string codigo;
    cout << "      Ingrese el codigo del cliente a actualizar: ";
    cin >> codigo;
    list<cliente>::iterator it;

    if (clientes.empty())
    {
        cout << "-----------------------------------------------" << endl;
        cout << "         NO HAY CLIENTES REGISTRADOS" << endl
             << "-----------------------------------------------" << endl;
    }
    else
    {
        bool exist = false;
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            if (codigo == it->codigo)
            {
                exist = true;
                string codigo, nombre, apellido, celular;
                cout << "           Ingrese el codigo del cliente (act:" << it->codigo << "): ";
                cin >> codigo;
                cout << endl
                     << "           Ingrese el nombre del cliente (act:" << it->nombre << "): ";
                cin >> nombre;
                cout << endl
                     << "           Ingrese el apellido del cliente (act:" << it->apellido << "): ";
                cin >> apellido;
                cout << endl
                     << "           Ingrese el celular del cliente (act:" << it->celular << "): ";
                cin >> celular;
                it->codigo = codigo;
                it->nombre = nombre;
                it->apellido = apellido;
                it->celular = celular;
                cout << "              Cliente actualizado";
            }
        }
        if (!exist)
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "         NO HAY CLIENTES REGISTRADOS CON ESE CODIGO" << endl
                 << "----------------------------------------------------------------" << endl;
        }
    }
    cin.get();
    cin.ignore(100, '\n');
}

void eliminar_cliente()
{
    menu_superior();
    string codigo;
    cout << "      Ingrese el codigo del cliente a eliminar: ";
    cin >> codigo;
    list<cliente>::iterator it;

    if (clientes.empty())
    {
        cout << "-----------------------------------------------" << endl;
        cout << "         NO HAY CLIENTES REGISTRADOS" << endl
             << "-----------------------------------------------" << endl;
    }
    else
    {
        bool exist = false;
        for (it = clientes.begin(); it != clientes.end(); it++)
        {
            if (codigo == it->codigo)
            {
                exist = true;
                clientes.erase(it);
                cout << "              Cliente eliminado";
                break;
            }
        }
        if (!exist)
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "         NO HAY CLIENTES REGISTRADOS CON ESE CODIGO" << endl
                 << "----------------------------------------------------------------" << endl;
        }
    }
    cin.get();
    cin.ignore(100, '\n');
}

void crear_archivo()
{
    list<cliente>::iterator it, last;

    if (clientes.empty())
    {
        cout << "-----------------------------------------------" << endl;
        cout << "         NO HAY CLIENTES REGISTRADOS" << endl
             << "-----------------------------------------------" << endl;
    }
    else
    {
        ofstream archivo;
        archivo.open("bd.txt", ios::out);
        if (!archivo.fail())
        {
            last = clientes.end();
            last--;
            for (it = clientes.begin(); it != clientes.end(); it++)
            {
                string cliente = it->codigo + "," + it->nombre + "," + it->apellido + "," + it->celular;
                archivo << cliente;

                if (it != last)
                {
                    archivo << endl;
                }
            }
            cout << "Archivo backup creado correctamente";
            archivo.close();
        }
        else
        {
            cout << "Error al crear el archivo backup";
        }
    }
    cin.get();
    cin.ignore(100, '\n');
}

void recuperar_datos()
{
    string ruta = "bd.txt";

    // cout << "Ingrese la ruta del archivo a cargar: ";
    // cin >> ruta;

    FILE *archivo;
    archivo = fopen(ruta.c_str(), "r");

    if (archivo == NULL)
    {
        cout << "Ruta invalida";
    }
    else
    {
        char aux[100], *token;

        while (!feof(archivo))
        {
            fscanf(archivo, "%s", aux);
            cliente cli;
            token = strtok(aux, ",");
            int i = 0;
            cout << "Cliente: ";
            while (token != NULL)
            {
                if (i == 0)
                {
                    cli.codigo = token;
                }
                else if (i == 1)
                {
                    cli.nombre = token;
                }
                else if (i == 2)
                {
                    cli.apellido = token;
                }
                else if (i == 3)
                {
                    cli.celular = token;
                }

                cout << token << " ";
                i++;
                token = strtok(NULL, ",");
            }
            cout << endl;
            clientes.push_back(cli);

            i = 0;
        }
        cout << "\t\tClientes registrados";
        cin.get();
        cin.ignore(100, '\n');
    }
}

void menu_clientes(int respuesta)
{
    switch (respuesta)
    {
    case 1:
        ingresar_cliente();
        break;
    case 2:
        buscar_clientes();
        break;
    case 3:
        actualizar_cliente();
        break;
    case 4:
        eliminar_cliente();
        break;
    case 5:
        crear_archivo();
        break;
    case 6:
        recuperar_datos();
        break;
    default:
        break;
    }
}

/////////////////////////////////
//   Logica de los productos    //
/////////////////////////////////

void ingresar_producto(){
    
}

void buscar_producto(){

}

void eliminar_producto(){

}

void actualizar_producto(){

}

void menu_productos(int respuesta)
{
    switch (respuesta)
    {
        case 1:
            /* ingresar_producto() */
            break;
        case 2:
            /* buscar_producto() */
            break;
        case 3:
            /* eliminar_producto() */
            break;
        case 4:
            /* actualizar_producto() */
            break;
        case 5:
            /* producto_economico() */
            break;
        case 6:
            /* producto_costoso() */
            break;
    
        default:
            break;
    }
}

/////////////////////////////////
//   Logica de las facturas    //
/////////////////////////////////
void menu_facturas(int respuesta)
{
}

/////////////////////////////////
//   Logica de los pedidos    //
/////////////////////////////////
void menu_pedidos(int respuesta)
{
}

/////////////////////////////////
//   Logica de los empleados    //
/////////////////////////////////
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

