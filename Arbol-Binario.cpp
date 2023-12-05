#include "Milibreria.h"

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Funci�n para insertar un nuevo valor en el �rbol binario
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

// Funci�n para imprimir el �rbol en orden
void imprimirEnorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        imprimirEnorden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirEnorden(raiz->derecha);
    }
}

// Funci�n para imprimir visualmente el �rbol con niveles
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
    struct Nodo* raiz = NULL;  // Inicializar la ra�z del �rbol como nula

    // Insertar valores en el �rbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 10);

    // Imprimir el �rbol visualmente con niveles
    printf("\nArbol binario:\n");
    imprimirArbol(raiz, 0);
    
        // Imprimir el �rbol en orden
    printf("Arbol binario en orden: ");
    imprimirEnorden(raiz);
    printf("\n");

    return 0;
}
