struct Envio{
    int id_envio;
    float precio;
};

struct Nodo{
    Envio info;
    Nodo *sgte;
};

void armarListaOrdenada(Nodo *&, Nodo *&, Envio [], int );
Envio pop(Nodo *&);
void insertarOrdenado(Nodo *&lista, Envio);
void vaciarElementoEnVector(Nodo *&, Envio [], int &);
void ordenarVector(Envio [], int);
Nodo *armarListaOrdenadoDos(Nodo *&, Envio [], int );

int main(){
    return 0;
}
//forma uno: sin usar apareo. Forma incorrecta ya que no sabemos cuantos elementos tiene la pila
void armarListaOrdenada(Nodo *&lista, Nodo *&pila, Envio vecEnvios[], int tamVecEnvios){
    Envio auxEnvio;
    while(pila != NULL){
        auxEnvio = pop(pila);
        for(int i = 0; i <tamVecEnvios; i++){
            if(auxEnvio.id_envio == vecEnvios[i].id_envio){
                insertarOrdenado(lista, auxEnvio);
            }
        }
    }
}

//Forma dos: Usando el apareo de vectores.
void vaciarElementoEnVector(Nodo *&pila, Envio vecEnvios[], int &tamVecEnvios){
    Envio aux;
    while(pila != NULL){
        aux = pop(pila);
        vecEnvios[tamVecEnvios] = aux;
        tamVecEnvios++; //aumentar el tamaño del vector apuntando a su dirección de memoria
    }
}

void ordenarVector(Envio vecEnvios[], int tamVecEnvios){
    Envio aux;
    for(int i = 0; i < tamVecEnvios - 1; i++){
        for(int j = 0; j<tamVecEnvios - 1 - i; j++){
            if(vecEnvios[j].id_envio > vecEnvios[j+1].id_envio){
                aux = vecEnvios[j];
                vecEnvios[j] = vecEnvios[j+1];
                vecEnvios[j+1] = aux;
            }
        }
    }
}

Nodo *armarListaOrdenadoDos(Nodo *&pila, Envio vecEnviosUno[], int tamVecUno) {
    Nodo *listaAux = NULL;
    int tamVecDos = 0;
    Envio vecEnviosDos[100];
    vaciarElementoEnVector(pila, vecEnviosDos, tamVecDos);
    ordenarVector(vecEnviosUno, tamVecUno);
    ordenarVector(vecEnviosDos, tamVecDos);
    
    int i = 0;
    int j = 0;
    
    while (i < tamVecUno && j < tamVecDos) {
        if (vecEnviosUno[i].id_envio == vecEnviosDos[j].id_envio) {
            insertarOrdenado(listaAux, vecEnviosUno[i]);
            i++;
            j++;
        }
        else if (vecEnviosUno[i].id_envio < vecEnviosDos[j].id_envio) {
            i++;
        }
        else {
            j++;
        }
    }
    return listaAux;
}

//Ejercicio 2:

struct Reservas{
    int numHabitacion;
    char tipo;
    int canDias;
};

struct Reserva{
    int numHabitacion;
    int cantDiasReservados;
};

struct Nodo{
    Reserva info;
    Nodo *sgte;
};

void actualizarVector(Nodo *, Nodo *, Reservas [], int){

int main(){
    return 0;
}

//suponiendo que NO hay habitaciones con el mismo número pero con diferente tipo
void actualizarVector(Nodo *listaEstandar, Nodo *listaPremium, Reservas vecReservas[], int tamVecReservas){
    while(listaEstandar != NULL){
        for(int i = 0; i < tamVecReservas; i++){
            if(listaEstandar->info.numHabitacion == vecReservas[i].numHabitacion){
                vecReservas[i].canDias -= listaEstandar->info.cantDiasReservados;
            }
        }
}

while(listaPremium != NULL){
    for(int i = 0; i < tamVecReservas; i++){
        if(listaPremium->info.numHabitacion == vecReservas[i].numHabitacion){
            vecReservas[i].canDias -= listaPremium->info.cantDiasReservados;
        }
    }
}
}

//Ejercicio 3-a:
/*El código no tiene errores de sintaxis, pero si un error en la lógica, al
decir if (n == 0) return 0;, lo que provoca es que al final de todo, se
anule el factorial del número n, entonces. La salida es 0*/

//Ejercicio 3-b:
/*La salida del ejercicio es 15, ya que al acceder al *(p+2) primero
desreferencia y es como si estuviera accediendo a p[2].*/

//Ejercicio 4-a:
/*El enunciado es Falso, ya que si o si, necesitamos un elemento auxiliar
para poder completar la intersección de ambos elementos.*/

//Ejercicio 4-b:
/*El enunciado es Verdadero, el corte de control genera la lista sumarizando
los resultados que tengan la clave repetida.*/