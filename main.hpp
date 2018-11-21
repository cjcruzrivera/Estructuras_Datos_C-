
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
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
    string apellido;
    string celular;
};

struct producto
{
    string codigo;
    string nombre;
    int precio;
};

list<cliente> clientes;

producto *productos;
int cantProd = 0;
int cantProdReg = 0;



void menu_superior();
string menu_inferior();
bool valida(int respuesta);
bool valida2(int r1, int r2);
void imprimir(int respuesta, bool invalid);
void ingresar_cliente();
void buscar_clientes();
void actualizar_cliente();
void eliminar_cliente();
void crear_archivo();
void recuperar_datos();
void menu_clientes(int respuesta);
void menu_productos(int respuesta);
void menu_facturas(int respuesta);
void menu_pedidos(int respuesta);
void menu_empleados(int respuesta);
void menus(int r1, int r2);
void ingresar_producto();
void buscar_producto();
void eliminar_producto();
void actualizar_producto();
void producto_economico();
void producto_costoso();