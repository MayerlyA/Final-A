// ============================================================================
// ARCHIVO: final_13_07_2026.cpp
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>
using namespace std;

/*
----------------------------------------------------------------------------
EJERCICIO 3: Salidas de Punteros Básicos y Referencias [cite: 127, 128]
----------------------------------------------------------------------------
- a. Fragmento con int v[4] = {12, 24, 36, 48}; int *p = &v[2]; [cite: 130, 131]
     cout << *p << endl;
     cout << *(p - 1) << endl; [cite: 132, 133]
     - SALIDA:
       36 [cite: 224]
       24 [cite: 225]
     - JUSTIFICACIÓN: p apunta inicialmente a v[2] (36)[cite: 131]. Por aritmética de 
       punteros, (p - 1) apunta al elemento previo contiguo, es decir v[1] (24)[cite: 678].

- b. Fragmento con procedimiento cambiar(int *p): [cite: 134]
     void cambiar(int *p) { *p = *p * 2; } [cite: 134, 135]
     // En main: int n = 7; cambiar(&n); cout << n << endl; [cite: 136, 138, 139, 140]
     - SALIDA: 14[cite: 226].
     - JUSTIFICACIÓN: Se le envía la dirección de memoria de la variable n (&n)[cite: 139], 
       por lo que la alteración efectuada mediante desreferenciación modifica la variable original[cite: 680].

----------------------------------------------------------------------------
EJERCICIO 4: V o F y Justifique [cite: 142]
----------------------------------------------------------------------------
- a. En una lista doblemente enlazada, el último nodo siempre apunta como siguiente al primer nodo[cite: 143].
     - RESPUESTA: FALSO[cite: 228].
     - JUSTIFICACIÓN: El campo siguiente del último elemento apunta siempre a NULL[cite: 228]. 
       Si apuntara al primero, estaríamos hablando de una lista circular[cite: 685].

- b. En una cola, para consultar el próximo elemento a salir, se debe eliminar obligatoriamente[cite: 144].
     - RESPUESTA: VERDADERO[cite: 229].
     - JUSTIFICACIÓN: Las únicas operaciones elementales y puras disponibles son queue (encolar) 
       y unqueue (desencolar)[cite: 229]. Para observar el elemento posterior, es obligatorio 
       removerlo del frente[cite: 229].
*/

// ----------------------------------------------------------------------------
// EJERCICIO 1: Consolidación de Viajes (Pila + Cola -> Lista Ordenada) [cite: 114, 146]
// ----------------------------------------------------------------------------
struct Viajes {
    int id_viaje; // [cite: 148]
    float km_recorridos; // [cite: 149]
};

struct Nodo {
    Viajes info; // [cite: 152]
    Nodo* sgte; // [cite: 153]
};

// Primitivas declaradas para posibilitar libre compilación en IDE
Viajes pop(Nodo*& pila);
Viajes unqueue(Nodo*& frente, Nodo*& fin);
void insertarOrdenado(Nodo*& lista, Viajes viaje);

bool existeLista(Nodo* lista, int idViaje) { // [cite: 185]
    Nodo* aux = lista; // [cite: 186]
    while (aux != NULL) { // [cite: 187]
        if (idViaje == aux->info.id_viaje) { // [cite: 188]
            return true; // [cite: 189]
        }
        aux = aux->sgte; // [cite: 191]
    }
    return false; // [cite: 193]
}

void combinarPilaCola(Nodo*& pilaViajes, Nodo*& frenteViajes, Nodo*& finViajes, Nodo*& listaViajes) { // [cite: 163]
    float kmRecorridos = 0; // [cite: 164]
    Viajes info; // [cite: 165]
    
    while (pilaViajes != NULL) { // [cite: 166]
        info = pop(pilaViajes); // [cite: 167]
        if (!existeLista(listaViajes, info.id_viaje)) { // [cite: 168]
            kmRecorridos += info.km_recorridos; // [cite: 169]
            insertarOrdenado(listaViajes, info); // [cite: 169]
        }
    }
    
    while (frenteViajes != NULL) { // [cite: 172]
        info = unqueue(frenteViajes, finViajes); // [cite: 173]
        if (!existeLista(listaViajes, info.id_viaje)) { // [cite: 174]
            kmRecorridos += info.km_recorridos; // [cite: 175]
            insertarOrdenado(listaViajes, info); // [cite: 176]
        }
    }
    cout << "La cantidad de Km recorrido fue: " << kmRecorridos << endl; // [cite: 181]
}

// ----------------------------------------------------------------------------
// EJERCICIO 2: Gestión de Cupos por Zonas [cite: 121, 195]
// ----------------------------------------------------------------------------
struct Excursiones {
    int id_Excursion; // [cite: 197]
    char zona[2]; // [cite: 198]
    int cupos_Disponibles; // [cite: 199]
};

struct Reservas {
    int id_Excursion; // [cite: 202]
    int cupos_Reservados; // [cite: 203]
};

struct NodoReservas {
    Reservas info; // [cite: 206]
    NodoReservas* sgte; // [cite: 208]
};

void actualizarVector(Excursiones vecExcursiones[], int tamVecExcursiones, NodoReservas* listaReservas) { // [cite: 209]
    NodoReservas* aux = listaReservas; // [cite: 210]
    while (aux != NULL) { // [cite: 211]
        for (int i = 0; i < tamVecExcursiones; i++) { // [cite: 212]
            if (vecExcursiones[i].id_Excursion == aux->info.id_Excursion) { // [cite: 213]
                vecExcursiones[i].cupos_Disponibles -= aux->info.cupos_Reservados; // [cite: 213, 214]
            }
        }
        aux = aux->sgte; // [cite: 217]
    }
}

int main() {
    return 0;
}