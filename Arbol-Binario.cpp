#include "Milibreria.h"

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nuevo valor en el árbol binario
struct Nodo* insertar(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// Función para imprimir el árbol en orden
void imprimirEnorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        imprimirEnorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirEnorden(raiz->derecha);
    }
}

// Función para imprimir visualmente el árbol con niveles
void imprimirArbol(struct Nodo* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    imprimirArbol(raiz->derecha, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }

    printf("%d\n", raiz->valor);

    imprimirArbol(raiz->izquierda, nivel + 1);
}

int main() {
    struct Nodo* raiz = NULL;  // Inicializar la raíz del árbol como nula

    // Insertar valores en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 10);

    // Imprimir el árbol visualmente con niveles
    printf("\nArbol binario:\n");
    imprimirArbol(raiz, 0);
    
        // Imprimir el árbol en orden
    printf("Arbol binario en orden: ");
    imprimirEnorden(raiz);
    printf("\n");

    return 0;
}
