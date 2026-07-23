#include <iostream>

// Definición de la estructura Nodo para listas enlazadas simples
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

// Función para imprimir una lista enlazada simple
void imprimirListaSimple(Nodo* inicio) {
    Nodo* actual = inicio;

    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    std::cout << std::endl;
}

int main() {

    // Crear una lista enlazada simple
    Nodo* listaSimple = crearNodo(10);
    listaSimple->siguiente = crearNodo(20);
    listaSimple->siguiente->siguiente = crearNodo(30);

    // Imprimir la lista enlazada simple
    std::cout << "Lista Simple: ";
    imprimirListaSimple(listaSimple);

    // Liberar la memoria al final del programa
    delete listaSimple->siguiente->siguiente;
    delete listaSimple->siguiente;
    delete listaSimple;

    return 0;
}

// Carga sin restricciones:

Nodo* cargarLista(Nodo* inicio, int valor) {

    Nodo* nuevoNodo = crearNodo(valor);

    if (inicio == nullptr) {
        inicio = nuevoNodo;
    } else {

        Nodo* actual = inicio;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevoNodo;
    }

    return inicio;
}

// Carga sin repetir

bool existeElemento(Nodo* inicio, int valor) {

    Nodo* actual = inicio;

    while (actual != nullptr) {

        if (actual->dato == valor) {
            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

Nodo* cargarSinRepetir(Nodo* inicio, int valor) {

    if (!existeElemento(inicio, valor)) {
        return cargarLista(inicio, valor);
    }

    return inicio;
}

// Busqueda

Nodo* buscarElemento(Nodo* inicio, int valor) {

    Nodo* actual = inicio;

    while (actual != nullptr) {

        if (actual->dato == valor) {
            return actual; // Devuelve el nodo que contiene el valor
        }

        actual = actual->siguiente;
    }

    return nullptr; // El valor no se encontró en la lista
}

// Recorrido

void recorrerLista(Nodo* inicio) {

    Nodo* actual = inicio;

    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    std::cout << std::endl;
}

// Eliminación de nodos

Nodo* eliminarNodo(Nodo* inicio, int valor) {

    if (inicio == nullptr) {
        return nullptr; // Lista vacía, no hay nada que eliminar
    }

    if (inicio->dato == valor) {

        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;

        return inicio; // Devuelve la lista actualizada
    }

    Nodo* actual = inicio;

    while (actual->siguiente != nullptr) {

        if (actual->siguiente->dato == valor) {

            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;

            return inicio; // Devuelve la lista actualizada
        }

        actual = actual->siguiente;
    }

    return inicio; // Valor no encontrado en la lista
}

// Insertar ordenado

// Función para insertar un elemento de manera ordenada en la lista
Nodo* insertarOrdenado(Nodo* inicio, int valor) {

    Nodo* nuevoNodo = crearNodo(valor);

    // Caso especial: si la lista está vacía o el valor es menor que el primer elemento
    if (inicio == nullptr || valor < inicio->dato) {
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
        return inicio;
    }

    Nodo* actual = inicio;

    while (actual->siguiente != nullptr && actual->siguiente->dato < valor) {
        actual = actual->siguiente;
    }

    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;

    return inicio;
}