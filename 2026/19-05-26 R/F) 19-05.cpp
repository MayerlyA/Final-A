/*
// ============================================================================
// ARCHIVO: final_19_05_2026.cpp
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>
#include <cstring>
using namespace std;

/*
----------------------------------------------------------------------------
EJERCICIO 3: Determinación de Salidas por Pantalla
----------------------------------------------------------------------------
- a. Sumarización recursiva: int total = calcular(10);
     - SALIDA: 55.

- b. Elemento de array dinámico: cout << vec[4] << endl;
     - SALIDA: 64.

----------------------------------------------------------------------------
EJERCICIO 4: V o F y Justifique
----------------------------------------------------------------------------
- a. En un apareo de archivos ordenados, los registros se recorren comparando las 
     claves de ambos archivos para generar un único archivo resultado[cite: 263].
     - RESPUESTA: VERDADERO.
     - JUSTIFICACIÓN: En un apareo, se obtienen valores con claves similares de dos 
       fuentes para formar una sola estructura ordenada evaluando sincrónicamente las claves[cite: 336].

- b. En un algoritmo de corte de control, cada vez que cambia el valor de la clave 
     principal se debe reiniciar el acumulador correspondiente[cite: 264].
     - RESPUESTA: VERDADERO.
     - JUSTIFICACIÓN: Cuando se acaba el lote de elementos repetidos, se muestra el 
       resultado parcial y el valor acumulado vuelve a 0 para la siguiente clave[cite: 337].
*/

// ----------------------------------------------------------------------------
// EJERCICIO 1: Mezcla de Cola y Vector (Estructuras No Ordenadas) [cite: 236, 266]
// ----------------------------------------------------------------------------
/*
struct Ventas {
    int idEntrada; 
    float precio;

struct NodoVentas {
    Ventas info; 
    NodoVentas* sgte; 
};

// Primitivas abstractas declaradas para la compilación limpia
Ventas unqueue(NodoVentas*& frente, NodoVentas*& fin);
void insertarLista(NodoVentas*& lista, Ventas info);

void procesarColaVector(NodoVentas*& frenteCola, NodoVentas*& finCola, NodoVentas*& ListaVentas, Ventas vecVentasVentanilla[], int tamVecVentas) { 
    Ventas info; 
    float montoGanado = 0; 
    
    // Como no importa el orden, sacamos primero de la cola y luego del vector 
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

// ----------------------------------------------------------------------------
// EJERCICIO 2: Actualización de Inventario de Vehículos con Cadenas
// ----------------------------------------------------------------------------
struct Vehiculos {
    char patente[8]; // Agrego un espacio más al final para el \0 de cadena
    char categoria[2];
    int cantDiasDisp; 
};

struct Reserva {
    char patente[8]; 
    int cantDiasReserv; 
};

struct Nodo {
    Reserva info; 
    Nodo* sgte; 
};

void actualizarVector(Vehiculos vecVehiculos[], int tamVecVehiculos, char patente[], int cantDiasReserva) { 
    for (int i = 0; i < tamVecVehiculos; i++) { // 
        // Como la patente es char[], usamos strcmp() para comparar cadenas 
        if (strcmp(patente, vecVehiculos[i].patente) == 0) { // 
            vecVehiculos[i].cantDiasDisp -= cantDiasReserva; // 
        }
    }
}

void procesarListas(Nodo* listaAutosEconomicos, Nodo* listaAutosLujosos, Vehiculos vecVehiculos[], int tamVecVehiculos) { 
    // Usamos búsqueda secuencial mediante punteros auxiliares 
    Nodo* auxEcos = listaAutosEconomicos; // 
    while (auxEcos != NULL) { // 
        actualizarVector(vecVehiculos, tamVecVehiculos, auxEcos->info.patente, auxEcos->info.cantDiasReserv);
        auxEcos = auxEcos->sgte; 
    }
    
    Nodo* auxLujosos = listaAutosLujosos; 
    while (auxLujosos != NULL) { 
        actualizarVector(vecVehiculos, tamVecVehiculos, auxLujosos->info.patente, auxLujosos->info.cantDiasReserv);
        auxLujosos = auxLujosos->sgte; 
    }
}

int main() {
    return 0;
}
*/


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