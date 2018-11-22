
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

struct factura
{
    string codigo;
    string nombre_pagar;
    int valor;
};


struct empleado
{
    string nombre;
    int edad;
};


struct nodo
{
    factura dato;
    nodo *siguiente;
};


struct nodo_arbol
{
    empleado dato;
    nodo_arbol *derecho;
    nodo_arbol *izquierdo;
};


list<cliente> clientes;
producto *productos;
nodo *pila = NULL;
nodo_arbol *arbol = NULL;
nodo *frente = NULL;
nodo *fin = NULL;

int cantProd = 0;
int cantProdReg = 0;

void menu_superior();
string menu_inferior();
bool valida(int);
bool valida2(int, int);
void imprimir(int, bool);
void ingresar_cliente();
void buscar_clientes();
void actualizar_cliente();
void eliminar_cliente();
void crear_archivo();
void recuperar_datos();
void menu_clientes(int);
void menu_productos(int);
void menu_facturas(int);
void menu_pedidos(int);
void menu_empleados(int);
void menus(int, int);
void ingresar_producto();
void buscar_producto();
void eliminar_producto();
void actualizar_producto();
void producto_economico();
void producto_costoso();
void ingresar_empleado();
void mostrar_empleados();
void buscar_empleados();
void recorrer_pre_orden();
void recorrer_in_orden();
void recorrer_post_orden();
void insertar_factura();
void mostrar_facturas();
void insertar_pedido();
void mostrar_pedidos();
void insertarCola(factura);
void insertarPila(factura);
nodo_arbol *crearNodo(empleado);
void insertarArbol(nodo_arbol *&, empleado);
void mostrarArbol(nodo_arbol *, int);
bool buscarArbol(nodo_arbol *, int);