#include "Milibreria.h"

// Función para crear un nuevo nodo con un valor dado
struct Nodo* crearNodo(int valor) {
    // Asigna memoria para el nuevo nodo
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    // Inicializar el nodo con el valor proporcionado sin hijos
    nodo->valor = valor;
    nodo->izquierda = nodo->derecha = NULL;

    // Devolver el nuevo nodo
    return nodo;
}

// Función para insertar un nuevo valor en el árbol 
struct Nodo* insertar(struct Nodo* raiz, int valor) {
    // Si la raíz es nula, crear un nuevo nodo con el valor 
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    // Si el valor es menor que el valor de la raíz, insertar a la izquierda
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } 
    // Si el valor es mayor que el valor de la raíz, insertar a la derecha
    else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    // Devolver la raíz actualizada
    return raiz;
}

// Función para imprimir el árbol en orden 
void imprimirEnorden(struct Nodo* raiz) {
    // Si la raíz no es nula
    if (raiz != NULL) {
        // Imprimir en orden: izquierda, raíz, derecha
        imprimirEnorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirEnorden(raiz->derecha);
    }
}

// Función para imprimir el árbol visualmente con niveles
void imprimirArbol(struct Nodo* raiz, int nivel) {
    // Si la raíz es nula, no hay nada que imprimir
    if (raiz == NULL) {
        return;
    }

    // Imprimir el subárbol derecho, aumentando el nivel
    imprimirArbol(raiz->derecha, nivel + 1);

    // Imprimir espacios para visualizar la estructura del árbol
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }

    // Imprimir el valor del nodo
    printf("%d\n", raiz->valor);

    // Imprimir el subárbol izquierdo, aumentando el nivel
    imprimirArbol(raiz->izquierda, nivel + 1);
}


int main() {
    // Inicializar la raíz del árbol
    struct Nodo* raiz = NULL;

    //  valores en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    // Imprimir el árbol visualmente
    printf("\nArbol binario:\n");
    imprimirArbol(raiz, 0);

    // Imprimir el árbol en orden 
    printf("Arbol binario en orden: ");
    imprimirEnorden(raiz);
    printf("\n");

    return 0;
}

