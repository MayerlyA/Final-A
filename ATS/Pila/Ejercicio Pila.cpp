/*Hacer un programa para agregar números enteros a una pila,
 hasta que el usuario lo decida, despues mostrar todos los 
 numeros introducidos en la pila.*/

// Insertar Elementos en la pila
#include <iostream>
#include <conio.h>

using namespace std;

// Estructura del Nodo de la Pila
struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Prototipo de Funciones
void agregarPila(Nodo *&pila, int n);
void sacarPila(Nodo *&pila, int &n);

int main() {
    Nodo *pila = NULL;
    int dato;
    char rpt;

    // Agregar elementos a la pila
    do {
        cout << "Digite un numero: ";
        cin >> dato;
        agregarPila(pila, dato);

        cout << "\nDesea agregar otro elemento a PILA (s/n): ";
        cin >> rpt;
    } while (rpt == 'S' || rpt == 's');

    // Sacar y mostrar todos los elementos de la pila
    cout << "\nSacando todos los elementos de la Pila: ";
    while (pila != NULL) { // Mientras no sea el final de la pila
        sacarPila(pila, dato);
        if (pila != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << " . ";
        }
    }

    getch();
    return 0;
}

// Función para insertar elementos en la pila (Push)
void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo(); // 1. Crear espacio en memoria
    nuevo_nodo->dato = n;          // 2. Cargar el valor dentro del nodo (dato).
    nuevo_nodo->siguiente = pila;  // 3. Cargar el puntero pila dentrp del nodo
    pila = nuevo_nodo;             // 4. Asignar el nuevo nodo a pila.

    cout << "\tElemento " << n << " ha sido agregado a PILA correctamente\n";
}

// Función para eliminar/sacar elementos de la pila (Pop)
void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;        // 1. Crear variable aux igualada a la pila
    n = aux->dato;           // 2. Igualar 'n' al dato
    pila = aux->siguiente;   // 3. Pasar pila al siguiente nodo
    delete aux;              // 4. Eliminar aux
}