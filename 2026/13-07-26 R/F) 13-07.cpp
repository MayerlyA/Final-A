// ============================================================================
// EXAMEN FINAL: 13/07/2026
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>

using namespace std;

// --- EJERCICIO 1: Consolidación de Viajes (Pila + Cola -> Lista Ordenada) ---
struct Viajes {
    int id_viaje;
    float km_recorridos;
};

struct Nodo {
    Viajes info;
    Nodo* sgte;
};

Viajes pop(Nodo*& pila);
Viajes unqueue(Nodo*& frente, Nodo*& fin);
void insertarOrdenado(Nodo*& lista, Viajes viaje);

bool existeLista(Nodo* lista, int idViaje) {
    Nodo* aux = lista;
    while (aux != NULL) {
        if (idViaje == aux->info.id_viaje) {
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

void combinarPilaCola(Nodo*& pilaViajes, Nodo*& frenteViajes, Nodo*& finViajes, Nodo*& listaViajes) {
    float kmRecorridos = 0;
    Viajes info;
    
    while (pilaViajes != NULL) {
        info = pop(pilaViajes);
        if (!existeLista(listaViajes, info.id_viaje)) {
            kmRecorridos += info.km_recorridos;
            insertarOrdenado(listaViajes, info);
        }
    }
    
    while (frenteViajes != NULL) {
        info = unqueue(frenteViajes, finViajes);
        if (!existeLista(listaViajes, info.id_viaje)) {
            kmRecorridos += info.km_recorridos;
            insertarOrdenado(listaViajes, info);
        }
    }
    
    cout << "La cantidad de Km recorrido fue: " << kmRecorridos << endl;
}

// --- EJERCICIO 2: Gestión de Cupos por Zonas ---
struct Excursiones {
    int id_Excursion;
    char zona[2];
    int cupos_Disponibles;
};

struct Reservas {
    int id_Excursion;
    int cupos_Reservados;
};

struct NodoReservas {
    Reservas info;
    NodoReservas* sgte;
};

void actualizarVectorExcursiones(Excursiones vecExcursiones[], int tamVecExcursiones, NodoReservas* listaReservas) {
    NodoReservas* aux = listaReservas;
    while (aux != NULL) {
        for (int i = 0; i < tamVecExcursiones; i++) {
            if (vecExcursiones[i].id_Excursion == aux->info.id_Excursion) {
                vecExcursiones[i].cupos_Disponibles -= aux->info.cupos_Reservados;
            }
        }
        aux = aux->sgte;
    }
}

/*
----------------------------------------------------------------------------
EJERCICIO 3: Salidas de Punteros Básicos y Referencias
----------------------------------------------------------------------------
- Código con int v[4] = {12, 24, 36, 48}; y desreferenciación desplazada:
  Salida:
  36
  24
  Justificación: p apunta al índice 2 (36). Luego *(p - 1) accede al elemento anterior en memoria (v[1] que equivale a 24).

- Código del procedimiento cambiar(int *p) operando sobre la dirección de n:
  Salida: 14
  Justificación: Pasa la dirección mediante &n, la función multiplica su valor interno por dos de forma destructiva sobre la memoria original.

----------------------------------------------------------------------------
EJERCICIO 4: Teoría (V o F)
----------------------------------------------------------------------------
a) FALSO. En una lista doblemente enlazada, el último nodo apunta siempre a NULL. Si apuntara al primero, se trataría de una lista de tipo circular doblemente enlazada.
b) VERDADERO. Siguiendo la restricción abstracta FIFO de la cátedra de la UTN, la única operación de lectura directa es extraer/desencolar (unqueue). Si se requiere inspeccionar elementos siguientes sin perder el frente, es forzoso extraer y reencolar en una cola auxiliar.
*/

int main() {
    return 0;
}