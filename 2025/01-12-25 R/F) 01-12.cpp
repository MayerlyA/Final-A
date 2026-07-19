// ============================================================================
// EXAMEN FINAL: 01/12/2025
// MATERIA: Algoritmos y Estructuras de Datos (UTN-FRBA)
// ============================================================================

#include <iostream>
#include <string>

using namespace std;

/*
----------------------------------------------------------------------------
EJERCICIO 1: Preguntas Teóricas (V o F)
----------------------------------------------------------------------------
a. Sea int a[3]; entonces: cout << a + 1 equivale a hacer cout << a[1];
   - RESPUESTA: FALSO.
   - JUSTIFICACIÓN: "cout << a + 1" muestra la dirección de memoria del segundo 
     elemento del array debido a la aritmética de punteros. En cambio, 
     "cout << a[1]" muestra el valor almacenado en dicha posición.

b. Sea struct Nodo { int x; Nodo* sig; }; y una lista Nodo* p con dos o más nodos. 
   Entonces void f(Nodo* p) { p->sig->sig->x = 10; } falla (no asigna el valor 10) 
   porque la función debería recibir por referencia al parámetro p.
   - RESPUESTA: FALSO.
   - JUSTIFICACIÓN: Funciona perfectamente porque la modificación se realiza sobre 
     el espacio de memoria apuntado (acceso directo a la estructura). No se está 
     intentando cambiar la dirección a la que apunta el puntero base p en sí.

----------------------------------------------------------------------------
EJERCICIO 2: Seguimiento de Código (Rastreo QuickSort)
----------------------------------------------------------------------------
- Enunciado: Sea int a[] = {5, 1, 6, 8, 2, 4, 3}; Si invocamos a la función de 
  partición de QuickSort f(a, 0, 6); donde el pivote es el último elemento (3), 
  ¿Cómo quedará el array?
- RESPUESTA: El orden final de los elementos de a será: [1, 2, 3, 8, 5, 4, 6].

----------------------------------------------------------------------------
EJERCICIO 3: Punteros y Evaluación en Cortocircuito
----------------------------------------------------------------------------
- Enunciado: Sea la función bool g(Nodo* p) { return p->sig != NULL && p != NULL; }
  ¿Qué retorna g(NULL);?
- RESPUESTA: No llega a retornar nada porque el programa falla (Runtime Error / Segmentation Fault).
- JUSTIFICACIÓN: Al pasar NULL, la expresión evalúa primero p->sig. Intentar 
  desreferenciar un puntero nulo (NULL->sig) provoca un fallo inmediato antes de 
  evaluar la segunda condición. Para solucionarlo, debería estar al revés debido 
  a la evaluación en cortocircuito (p != NULL && p->sig != NULL).
*/

// --- EJERCICIO 4: Estructuras de Datos ---
struct NodoB {
    int b;
    NodoB* sig;
};

struct NodoA {
    int a;
    NodoB* slst; // Sublista de NodoB
    NodoA* sig;
};

// Variable del enunciado: NodoA* x[5];

// --- EJERCICIO 5: Función de Remoción ---
int remove(NodoA* x[], int a, int b) {
    int removidos = 0;
    
    for (int i = 0; i < 5; i++) {
        NodoA* pa = x[i];
        while (pa != NULL) {
            if (pa->a == a) {
                NodoB* actual = pa->slst;
                NodoB* ant = NULL;
                
                while (actual != NULL) {
                    if (actual->b == b) {
                        removidos++;
                        if (ant == NULL) { // Primer nodo de la sublista
                            pa->slst = actual->sig;
                        } else {
                            ant->sig = actual->sig;
                        }
                        NodoB* borrar = actual;
                        actual = actual->sig;
                        delete borrar;
                    } else {
                        ant = actual;
                        actual = actual->sig;
                    }
                }
            }
            pa = pa->sig;
        }
    }
    return removidos;
}

int main() {
    return 0;
}