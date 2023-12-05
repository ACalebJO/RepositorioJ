#include "Milibreria.h"

// Funci�n para crear un nuevo nodo con un valor dado
struct Nodo* crearNodo(int valor) {
    // Asigna memoria para el nuevo nodo
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    // Inicializar el nodo con el valor proporcionado sin hijos
    nodo->valor = valor;
    nodo->izquierda = nodo->derecha = NULL;

    // Devolver el nuevo nodo
    return nodo;
}

// Funci�n para insertar un nuevo valor en el �rbol 
struct Nodo* insertar(struct Nodo* raiz, int valor) {
    // Si la ra�z es nula, crear un nuevo nodo con el valor 
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    // Si el valor es menor que el valor de la ra�z, insertar a la izquierda
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } 
    // Si el valor es mayor que el valor de la ra�z, insertar a la derecha
    else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    // Devolver la ra�z actualizada
    return raiz;
}

// Funci�n para imprimir el �rbol en orden 
void imprimirEnorden(struct Nodo* raiz) {
    // Si la ra�z no es nula
    if (raiz != NULL) {
        // Imprimir en orden: izquierda, ra�z, derecha
        imprimirEnorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirEnorden(raiz->derecha);
    }
}

// Funci�n para imprimir el �rbol visualmente con niveles
void imprimirArbol(struct Nodo* raiz, int nivel) {
    // Si la ra�z es nula, no hay nada que imprimir
    if (raiz == NULL) {
        return;
    }

    // Imprimir el sub�rbol derecho, aumentando el nivel
    imprimirArbol(raiz->derecha, nivel + 1);

    // Imprimir espacios para visualizar la estructura del �rbol
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }

    // Imprimir el valor del nodo
    printf("%d\n", raiz->valor);

    // Imprimir el sub�rbol izquierdo, aumentando el nivel
    imprimirArbol(raiz->izquierda, nivel + 1);
}


int main() {
    // Inicializar la ra�z del �rbol
    struct Nodo* raiz = NULL;

    //  valores en el �rbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    // Imprimir el �rbol visualmente
    printf("\nArbol binario:\n");
    imprimirArbol(raiz, 0);

    // Imprimir el �rbol en orden 
    printf("Arbol binario en orden: ");
    imprimirEnorden(raiz);
    printf("\n");

    return 0;
}

