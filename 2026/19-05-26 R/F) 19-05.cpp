#include <iostream>
#include <cstring>

using namespace std;

// --- Parte 1: Ventas ---
// EJERCICIO 1

struct Ventas {
    int idEntrada;
    float precio;
};

struct NodoVentas {
    Ventas info;
    NodoVentas *sgte;
};

//funciones que vamos a usar para el ejercicio, la primera para quitar los elementos de la cola y la segunda, la vamos a usar para poder insertar los elementos en la cola.
// Prototipos
Ventas unqueue(NodoVentas *&, NodoVentas *&);
void insertarLista(NodoVentas *&, Ventas);
void procesarColaVector(NodoVentas *&, NodoVentas *&, NodoVentas *&, Ventas [], int);

/*como nos dicen que no importa el orden, primero sacamos todos los elementos de la cola y los mandamos
a la lista y luego hacemos lo mismo con los elementos del vector. Retornamos la lista como parámetro,
pasandola como referencia.*/

void procesarColaVector(NodoVentas *&frenteCola, NodoVentas *&finCola, NodoVentas *&ListaVentas, Ventas vecVentasVentanilla[], int tamVecVentas) {
    Ventas info;
    float montoGanado = 0;
    
    while (frenteCola != NULL) {
        info = unqueue(frenteCola, finCola);
        montoGanado += info.precio;
        insertarLista(ListaVentas, info);
    }
    
    for (int i = 0; i < tamVecVentas; i++) {
        insertarLista(ListaVentas, vecVentasVentanilla[i]);
        montoGanado += vecVentasVentanilla[i].precio;
    }
    
    cout << "Monto total ganado: " << montoGanado << endl;
}
// EJERCICIO 2
// --- Parte 2: Vehículos ---

struct Vehiculos {
    char patente[8];
    char categoria[2];
    int cantDiasDisp;
};

struct Reserva {
    char patente[8];//agrego un espacio más al final de la cadena para el \0
    int cantDiasReserv;
};

struct Nodo {
    Reserva info;
    Nodo *sgte;
};

// Prototipos
void actualizarVector(Vehiculos [], int, char [], int);
void procesarListas(Nodo *, Nodo *, Vehiculos [], int);

void actualizarVector(Vehiculos vecVehiculos[], int tamVecVechiculos, char patente[], int cantDiasReserva) {
    for (int i = 0; i < tamVecVechiculos; i++) {
// como la patente es char, usamos strcmp() y si la patente coincide
if (strcmp(patente, vecVehiculos[i].patente) == 0) {
            vecVehiculos[i].cantDiasDisp -= cantDiasReserva;
        }
    }
}

//usamos a nuestro amigo fiel, la busqueda secuencial :D
void procesarListas(Nodo *listaAutosEconomicos, Nodo *listaAutosLujosos, Vehiculos vecVehiculos[], int tamVecVechiculos) {
//usamos a nuestro amigo fiel, la busqueda secuencial :D
    Nodo *auxEcos = listaAutosEconomicos;
    Nodo *auxLujosos = listaAutosLujosos;
//actualizamos con la lista de economicos
// Actualizamos con la lista de economicos
    while (auxEcos != NULL) {
        actualizarVector(vecVehiculos, tamVecVechiculos, auxEcos->info.patente, auxEcos->info.cantDiasReserv);
        auxEcos = auxEcos->sgte;
    }
//actualizamos con la lista de Lujosos
// Actualizamos con la lista de Lujosos
    while (auxLujosos != NULL) {
        actualizarVector(vecVehiculos, tamVecVechiculos, auxLujosos->info.patente, auxLujosos->info.cantDiasReserv);
        auxLujosos = auxLujosos->sgte;
    }
}

// EJERCICIO 3
/*a) Salida: 55
b) Salida: 64*/

// EJERCICIO 4

/*
a) Verdadero, en un apareo, obtengo valores con claves similares de dos vectores para
formar un solo vector ordenado (o sea, evaluando cual de los elementos va primero) con
todos los elementos de ambos vectores.
b) Verdadero, en el corte de control si estamos usando una variable como acumulador,
cuando se acaba el lote de elementos repetidos, se muestra el resultado y el valor se
vuelve a 0 para que empiece a acumular todos los datos de la siguiente clave.*/