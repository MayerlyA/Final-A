/*a. Es falso porque aplica la aritmética de punteros, debido a que incrementa la dirección
de memoria, no el valor de la misma.
b. Es Falso ya que si bien “l” lo pasan por valor, la copia del puntero y el original están
apuntando a la misma dirección de memoria. Por lo cual, si se modifica el valor del nodo de la lista
original.
*/
#include <iostream>

using namespace std;

struct NodoA{
    int legajo;
    string nya;
    float promedio;
    NodoA *sgte;
    };

void insertarSinRepetir(NodoA *&lista, int legajo,string nya, float promedio){
    NodoA *nuevo = new NodoA();
    nuevo->legajo = legajo;
    nuevo->nya = nya;
    nuevo->promedio = promedio;
    
    NodoA *aux = lista;
    while(aux != NULL){
        if(aux->legajo == legajo){
            return;
        }
        aux = aux->sgte;
    }
    nuevo->sgte = lista;
    lista = nuevo;
}

NodoA *alumnosDestacados(NodoA *x[][10], int anios, int materias){
    NodoA *listaDestacados = NULL;
    for(int i = 0; i < anios;i++){
        for(int j = 0; j < materias; j++){
            NodoA *aux = x[i][j];
            while(aux != NULL){
                if(aux->promedio >= 7 && aux->promedio <= 9){
                    insertarSinRepetir(listaDestacados,aux->legajo,aux->nya,aux->promedio);
                }
            }
        }
    }   
return listaDestacados;
}