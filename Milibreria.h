#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en el árbol binario
struct Nodo {
    int valor;               // Valor almacenado en el nodo
    struct Nodo* izquierda;  // Puntero al subárbol izquierdo
    struct Nodo* derecha;    // Puntero al subárbol derecho
};

// Declaración de funciones proporcionadas por la librería
struct Nodo* crearNodo(int valor);                // Crear un nuevo nodo con el valor dado
struct Nodo* insertar(struct Nodo* raiz, int valor);  // Insertar un nuevo valor en el árbol binario
void imprimirEnorden(struct Nodo* raiz);           // Imprimir el árbol en orden (
void imprimirArbol(struct Nodo* raiz, int nivel);  // Imprimir visualmente el árbol con niveles


