#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura de un nodo en el �rbol binario
struct Nodo {
    int valor;               // Valor almacenado en el nodo
    struct Nodo* izquierda;  // Puntero al sub�rbol izquierdo
    struct Nodo* derecha;    // Puntero al sub�rbol derecho
};

// Declaraci�n de funciones proporcionadas por la librer�a
struct Nodo* crearNodo(int valor);                // Crear un nuevo nodo con el valor dado
struct Nodo* insertar(struct Nodo* raiz, int valor);  // Insertar un nuevo valor en el �rbol binario
void imprimirEnorden(struct Nodo* raiz);           // Imprimir el �rbol en orden (
void imprimirArbol(struct Nodo* raiz, int nivel);  // Imprimir visualmente el �rbol con niveles


