// ============================================================================
// EXAMEN FINAL: 09/02/2026
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>
#include <string>

using namespace std;

/*
----------------------------------------------------------------------------
EJERCICIO 1: Conceptos Básicos (V o F)
----------------------------------------------------------------------------
a. Sea int x = 10; int* p = &x; entonces la instrucción p = p + 1; modifica el valor de x.
   - RESPUESTA: FALSO.
   - JUSTIFICACIÓN: Modifica la dirección almacenada en el puntero p (hace que 
     apunte a la siguiente posición de memoria contigua de tipo int), pero no 
     altera el contenido de la variable x.

b. Sea struct Nodo { int dato; Nodo* sig; }; y una lista simplemente enlazada 
   Nodo* l con al menos un nodo. El procedimiento void f(Nodo* l) { l->dato = 5; } 
   no modifica la lista original porque el parámetro no se pasa por referencia.
   - RESPUESTA: FALSO.
   - JUSTIFICACIÓN: Aunque el puntero se pase por valor (se genera una copia del puntero), 
     tanto el original como la copia apuntan a la misma dirección física de memoria. 
     Por lo tanto, cualquier cambio a los campos del nodo (l->dato) altera la lista original.

----------------------------------------------------------------------------
EJERCICIO 2: Salidas por Pantalla
----------------------------------------------------------------------------
- a. Fragmento de código de asignación simétrica en matrices de 3x3:
     - SALIDA: 10 10 19

- b. Fragmento con bucle de pila:
     - SALIDA: El programa compila pero entra en un bucle infinito.
     - JUSTIFICACIÓN: Al procesar valores pares introducidos en la estructura, 
       vuelve a insertar elementos en la pila de forma indeterminada, impidiendo 
       que la condición de parada del ciclo while (pila == NULL) llegue a cumplirse.
*/

// --- EJERCICIO 3: Estructuras de Alumnos ---
struct NodoA {
    int legajo;
    string nya;
    float promedio;
    NodoA* sig;
};

// Variable declarada: NodoA* x[5][10];

// --- EJERCICIO 4: Implementación de Filtros ---
void insertarSinRepetir(NodoA*& lista, int legajo, string nya, float promedio) {
    NodoA* aux = lista;
    while (aux != NULL) {
        if (aux->legajo == legajo) {
            return;
        }
        aux = aux->sig;
    }
    NodoA* nuevo = new NodoA();
    nuevo->legajo = legajo;
    nuevo->nya = nya;
    nuevo->promedio = promedio;
    nuevo->sig = lista;
    lista = nuevo;
}

NodoA* alumnosDestacados(NodoA* x[5][10], int anios, int materias) {
    NodoA* listaDestacados = NULL;
    
    for (int i = 0; i < anios; i++) {
        for (int j = 0; j < materias; j++) {
            NodoA* aux = x[i][j];
            while (aux != NULL) {
                if (aux->promedio >= 7 && aux->promedio <= 9) {
                    insertarSinRepetir(listaDestacados, aux->legajo, aux->nya, aux->promedio);
                }
                aux = aux->sig;
            }
        }
    }
    return listaDestacados;
}

int main() {
    return 0;
}