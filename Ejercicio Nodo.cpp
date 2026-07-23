/*Ejercicio 1: Crear una lista que almacene "n" numeros enteros  y calcular el menor y mayor
de ellos.*/

#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void calcularMayorMenor(Nodo *);

int main(){
    Nodo *lista = NULL;
    int dato;
    char respuesta;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        insertarLista(lista,dato); //Agregando un nuevo elemento a la lista

        cout<<"Desea agregar otro nodo(s/n): ";
        cin>>respuesta;
    }while(respuesta == 's' || respuesta == 'S');

    cout<<"\nElementos de la lista: \n";
    mostrarLista(lista);

    calcularMayorMenor(lista);

    return 0;
}

//Agregar elementos al final de la lista
void insertarLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(lista == NULL){ //si la lista esta vacia
        lista = nuevo_nodo; //agregamos el primer elemento a la lista
    }
    else{
        aux = lista; //aux apunta al inicio de la lista
        while(aux->siguiente != NULL){ //recorrer la lista
            aux = aux->siguiente; //avanzamos posiciones en la lista
        }
        aux->siguiente = nuevo_nodo; //agrega el nuevo nodo a la lista
    }

    cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
    while(lista != NULL){ //mientras no sea el final de la lista
        cout<<lista->dato<<" -> ";
        lista = lista->siguiente; //avanzamos una posicion en lista
    }
}

//Calcular el mayor y menor elemento de la lista
void calcularMayorMenor(Nodo *lista){
    int mayor=0, menor=99999;

    while(lista != NULL){ //recorremos la lista
        if(lista->dato > mayor){ //calculando el mayor elemento
            mayor = lista->dato;
        }
        if(lista->dato < menor){ //calculando el menor elemento
            menor = lista->dato;
        }
        lista = lista->siguiente; //avanzamos una posicion en lista
    }

    cout<<"\nEl mayor elemento es: "<<mayor<<endl;
    cout<<"El menor elemento es: "<<menor<<endl;
}
