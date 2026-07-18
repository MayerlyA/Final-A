#include<iostream>
#include<stdio.h>
using namespace std;

/* EJERCICIO 1
Desarrolle una funcion que retorne una lista ordenada a partir de la interseccion de 1 pila y 1 lista.
Defina usted las precondiciones y estructura de los nodos de la manera que considere mas conveniente y detallar.¿ 
*/

struct Nodo{
    int valor;
    Nodo *sgte;
};

Nodo *interserccionColaLista(Nodo *&Lista, Nodo *&Pila){
    Nodo *ListaOrdenada=NULL;
    Nodo *aux=Lista;
    Nodo *auxPila=Pila;
    int v;
    while(aux!=NULL){
        while(auxPila!=NULL){
            if(auxLista->valor==auxPila->valor){
                insertarOrdenado(ListaOrdenada,valor);
            }
            auxPila=auxPila->sgte;
        }
        auxPila=Pila;
        auxLista=auxLista->sgte;
    }
    return ListaOrdenada;
}

/* EJERCICIO 2
Se tiene un vector de saldos de cuentas bancarias de una empresa, que contiene los sigueintes campos:
-Nro de Cuenta
-Cantidad de Transacciones
-Saldo
Ademas, se cuenta con una lista que contiene las ultimas transaciones (1 nodo 1 transaccion), cada nodo de la
lista contiene:
-Nro de Cuenta
-Monto
Se pide, actulizar el vector saldos con la informacion que hay en la lista, considerando que debe actualizar el saldo
y actualizar la cantidad de transacciones por cuenta.
Maximo hay 150 cuentas.
*/

struct Saldo{
    int nro_Cuenta;
    int cant_Trans;
    int saldo;
};

struct Transacciones{
    int nro_Cuenta;
    int monto;
};

struct Nodo{
    Transacciones Info;
    Nodo *sgte;
};

int main(){

    Saldo vec[150];
    int len;

    Nodo *Lista;
    Nodo *aux=Lista;

    while(aux!=NULL){
        pos=buscar(vec,len,aux->Info.nro_Cuenta);
        if(pos>-1){
            vec[pos].saldo -=aux->Info.monto;
            vec[pos].cant_Trans +=1;
        }
        aux=aux->sgte;
    }
    liberar(Lista);

    return 0;
}

/* EJERCICIO 3
a) El primer codigo imprime: 10 30 60
b) El segundo codigo imprime: 41

*/

/* EJERCICIO 4
a) "La manera correcta de enviar como parametro por referenia un vector es: int *vec[]"

FALSO, la sintaxis int *vec[] no es correcta para pasar un vector por referencia, ya que esta sintaxis se refiere a un arreglo de punteros, no a un puntero a un arreglo.

b) "La estrategia de resolucion de apareo, solo puede aplicarse en Archivos"

FALSO, la estrategia de apareo se utiliza en vectores y archivos. Basicamente sirve 
para combinar dos o mas conjuntos de datos ordenados en uno solo, manteniendo el orden.
*/
