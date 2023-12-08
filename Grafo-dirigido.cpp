#include <stdio.h>
#include <stdlib.h>

//Para este programa se creo una lista secundaria que se uniria atraves de los nodos 
//para crear el enlazamiento de cada nodo hacia atras y adelante

// Definición de la estructura del nodo en el grafo dirigido
struct Nodo {
    int dato;
    struct Nodo* siguiente;  // Enlace al siguiente nodo en la lista
    struct Nodo* secundario;     // Enlace al nodo secundario 
};

// Función para imprimir la lista secundaria
void imprimirListaSecundaria(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;                                  
    while (actual != NULL) {                                     //El ciclo imprime la lista con la flecha correspondiente al nodo que sigue de 
        printf("Nodo %d -> ", actual->dato);                               
        if (actual->secundario != NULL) {
            printf("%d", actual->secundario->dato);
        }
        printf("\n");
        actual = actual->siguiente;
    }
}

int main() {
    // Crear nodos para representar nodos en el grafo dirigido
    struct Nodo* nodo1 = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* nodo2 = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* nodo3 = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* nodo4 = (struct Nodo*)malloc(sizeof(struct Nodo));

    // Inicializacion de nodos y enlazandolos
    nodo1->dato = 1;
    nodo1->secundario = nodo2;
    nodo1->siguiente = nodo2;

    nodo2->dato = 2;
    nodo2->secundario = nodo3;
    nodo2->siguiente = nodo3;

    nodo3->dato = 3;
    nodo3->secundario = nodo4;
    nodo3->siguiente = nodo4;

    nodo4->dato = 4;
    nodo4->secundario = nodo1;
    nodo4->siguiente = NULL;

    // Imprimir la lista secundaria del grafo dirigido
    printf("Lista secundaria:\n");
    imprimirListaSecundaria(nodo1);

    // Liberar la memoria asignada
    free(nodo1);
    free(nodo2);
    free(nodo3);
    free(nodo4);

    return 0;
}


	
