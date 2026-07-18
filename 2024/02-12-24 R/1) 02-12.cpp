#include <iostream>
#include <stdio.h>


using namespace std;


// EJ 1)


struct Nodo{
    int info;
    Nodo *sgte;
};


Nodo unir(Nodo *cfte,Nodo *cfin,int vec[],int len){
    int valor;
    Nodo *lista = NULL;
    while(cfte != NULL){
        valor = desencolar(cfte,cfin);
        insertarOrdenado(lista,valor);
    }
    for(int i=0;i<len;i++){
        valor = vec[i];
        insertarOrdenado(lista,valor);
    }


    return *lista;
}


// EJ 2)


struct Stock {
    int id;
    char tipo; // 'p' o 'n'
    int unidades_disp;
};


struct tInfo {
    int id;
    int id_cliente;
    int unidades_req;
};


struct Nodo {
    tInfo info;
    Nodo *sgte;
};


void actualizar(Stock vec[],Nodo *lista){
    Nodo *aux = lista;
   
    while(aux != NULL){
    for(int i=0;i<50;i++){
        if(vec[i].id == aux->info.id){
            vec[i].unidades_disp -= aux->info.unidades_req;
        }
    }
        aux = aux->sgte;
    }
}


// EJ 3)
// 1) 30 20
// 2) 16


// EJ 4)
// F. No solo con listas, tambien con arrays por ejemplo.
// V. Utilizando fseek y fwrite
