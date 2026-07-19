// ============================================================================
// EXAMEN FINAL: 15/12/2025
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>

using namespace std;

/*
----------------------------------------------------------------------------
EJERCICIO 3: Salidas por Pantalla (Análisis de Código)
----------------------------------------------------------------------------
- a. Código recursivo con condición base "if (n == 0) return 0;" multiplicando los retornos.
     - SALIDA: 0
     - JUSTIFICACIÓN: Al llegar al caso base (n == 0), devuelve 0, lo que anula 
       recursivamente toda la cadena de multiplicaciones del factorial.

- b. Acceso a memoria dinámica "*cout << (p + 2) << endl;" en un array de enteros.
     - SALIDA: 15
     - JUSTIFICACIÓN: *(p + 2) es equivalente por aritmética de punteros a acceder 
       al índice p[2], cuyo valor asignado es 15.

----------------------------------------------------------------------------
EJERCICIO 4: Teoría (V o F)
----------------------------------------------------------------------------
- a. Si el ejercicio 1 hubiera pedido intersección entre pila y cola se podría haber 
     realizado sin estructuras auxiliares.
     - RESPUESTA: FALSO.
     - JUSTIFICACIÓN: Para contrastar todos los elementos entre dos estructuras 
       destructivas (como Pilas y Colas) sin perder los datos originales en el 
       proceso, obligatoriamente requerimos de estructuras auxiliares para preservar la información.

- b. El corte de control de archivos permite generar un listado sumariando resultados 
     para las claves repetidas por las que está ordenado el archivo.
     - RESPUESTA: VERDADERO.
     - JUSTIFICACIÓN: Esa es precisamente la definición y el objetivo algorítmico 
       de la estrategia de corte de control.
*/

// --- EJERCICIO 1: Intersección Pila y Vector ---
struct Envio {
    int id_envio;
    float precio;
};

struct NodoEnvio {
    Envio info;
    NodoEnvio* sgte;
};

// Prototipos de primitivas asumidas
Envio pop(NodoEnvio*& pila);
void insertarOrdenado(NodoEnvio*& lista, Envio info);

void armarListaOrdenada(NodoEnvio*& lista, NodoEnvio*& pila, Envio vecEnvios[], int tamVecEnvios) {
    Envio auxEnvio;
    while (pila != NULL) {
        auxEnvio = pop(pila);
        for (int i = 0; i < tamVecEnvios; i++) {
            if (auxEnvio.id_envio == vecEnvios[i].id_envio) {
                insertarOrdenado(lista, auxEnvio);
            }
        }
    }
}

// --- EJERCICIO 2: Actualización de Estructuras Combinadas ---
struct Reservas {
    int numHabitacion;
    char tipo; // 'E' Estándar, 'P' Premium
    int canDias;
};

struct Reserva {
    int numHabitacion;
    int cantDiasReservados;
};

struct NodoReserva {
    Reserva info;
    NodoReserva* sgte;
};

void actualizarVector(NodoReserva* listaEstandar, NodoReserva* listaPremium, Reservas vecReservas[], int tamVecReservas) {
    while (listaEstandar != NULL) {
        for (int i = 0; i < tamVecReservas; i++) {
            if (listaEstandar->info.numHabitacion == vecReservas[i].numHabitacion) {
                vecReservas[i].canDias -= listaEstandar->info.cantDiasReservados;
            }
        }
        listaEstandar = listaEstandar->sgte;
    }
    
    while (listaPremium != NULL) {
        for (int i = 0; i < tamVecReservas; i++) {
            if (listaPremium->info.numHabitacion == vecReservas[i].numHabitacion) {
                vecReservas[i].canDias -= listaPremium->info.cantDiasReservados;
            }
        }
        listaPremium = listaPremium->sgte;
    }
}

int main() {
    return 0;
}