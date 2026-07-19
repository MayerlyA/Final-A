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

//suponiendo que NO hay habitaciones con el mismo número pero con diferente tipo
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

// EJERCICIO 3
/*
Ejercicio 3-a:
El código no tiene errores de sintaxis, pero si un error en la lógica, al
decir if (n == 0) return 0;, lo que provoca es que al final de todo, se
anule el factorial del número n, entonces. La salida es 0

Ejercicio 3-b:
La salida del ejercicio es 15, ya que al acceder al *(p+2) primero
desreferencia y es como si estuviera accediendo a p[2].
*/

// EJERCICIO 4
/*Ejercicio 4-a:
El enunciado es Falso, ya que si o si, necesitamos un elemento auxiliar
para poder completar la intersección de ambos elementos.
Ejercicio 4-b:
El enunciado es Verdadero, el corte de control genera la lista sumarizando
los resultados que tengan la clave repetida.
*/