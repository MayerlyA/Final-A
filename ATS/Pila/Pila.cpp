// Insertar Elementos en la pila
//Quitar Elementos en la pila
#include <iostream>
#include <conio.h>
#include <stdlib.h> 

using namespace std;

// Estructura del Nodo de la Pila
struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Prototipo de Funciones
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);

int main() {
    Nodo *pila = NULL;
    int dato;

    cout << "Digite un numero: ";
    cin >> dato;
    agregarPila(pila, dato);

    cout << "Digite otro numero: ";
    cin >> dato;
    agregarPila(pila, dato);


    cout << "\nSacando todos los elementos de la Pila: ";
    while (pila != NULL) { // Mientras no sea el final de la pila
        sacarPila(pila, dato);
        if (pila != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << ".";
        }
    }
    getch();
    return 0;
}

// Función para insertar elementos en la pila (Push)
void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo(); // 1. Crear espacio en memoria para almacenar un nodo
    nuevo_nodo->dato = n;          // 2. Cargar el valor dentro del nodo (dato).
    nuevo_nodo->siguiente = pila;  // 3. Cargar el puntero pila dentro del nodo (*siguiente)
    pila = nuevo_nodo;             // 4. Asignar el nuevo nodo a pila.

    cout << "\tElemento " << n << " ha sido agregado a PILA correctamente\n";
}

// Función para eliminar/sacar elementos de la pila (Pop)
void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;        // 1. Crear una variable *aux de tipo Nodo
    n = aux->dato;           // 2. Igualar 'n' a aux -> dato
    pila = aux->siguiente;   // 3. Pasar pila al siguiente nodo
    delete aux;              // 4. Eliminar aux
}