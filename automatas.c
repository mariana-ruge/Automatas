#include <stdio.h>    // define constantes, macros, tipos y declara funciones de entrada y salida de secuencia.
#include <stdlib.h>   // Gestión de la memoria dinámica en C
#include <string.h>   // Definición de macros constantes, funciones y algunos tipos de operaciones de manipulación de memoria.

// Definir constantes de máximos en cadena
#define MAX_ESTADOS 20      // Número máximo de estados en el DFA
#define MAX_SIMBOLOS 50     // Número máximo de símbolos en el alfabeto
#define MAX_ENTRADA 1000    // Longitud máxima de cadenas en la entrada
#define TAMANIO_ASCII 128   // Tamaño del conjunto en caracteres ASCII

// Estructura del DFA (Autómata Finito Determinista)
typedef struct {
    int estados;                      // Número total de estados
    char simbolos[MAX_SIMBOLOS];      // Conjunto de símbolos en el alfabeto
    int estadosAceptacion[MAX_ESTADOS]; // Lista de estados de aceptación
    int numEstadosAceptacion;         // Número de estados de aceptación
    int transicion[MAX_ESTADOS][TAMANIO_ASCII]; // Matriz de transición
} DFA;

// Inicializa el DFA
void inicializarDFA(DFA* dfa) {
    // Inicializar toda la estructura del DFA en 0
    memset(dfa, 0, sizeof(DFA));

    // Inicializar todas las transiciones a -1 (no definido en el archivo de configuración)
    for (int i = 0; i < MAX_ESTADOS; i++) {
        for (int j = 0; j < TAMANIO_ASCII; j++) {
            dfa->transicion[i][j] = -1;
        }
    }
}

// Lee la configuración del DFA desde un archivo
int leerConfiguracionDFA(DFA* dfa, FILE* archivo) {
    // Leer el conjunto de símbolos
    if (fscanf(archivo, "%s", dfa->simbolos) != 1) return 0;
    // Leer el número total de estados
    if (fscanf(archivo, "%d", &dfa->estados) != 1) return 0;
    // Leer el número de estados de aceptación
    if (fscanf(archivo, "%d", &dfa->numEstadosAceptacion) != 1) return 0;
    // Leer los estados de aceptación
    for (int i = 0; i < dfa->numEstadosAceptacion; i++) {
        if (fscanf(archivo, "%d", &dfa->estadosAceptacion[i]) != 1) return 0;
    }
    // Leer la tabla de transiciones
    //Lectura de las filas
    for (int i = 0; i < dfa->estados; i++) {
        //Lecy¡tura de las columnas
        for (int j = 0; dfa->simbolos[j] != '\0'; j++) {
            //Avanzar al siguiente estado
            int siguienteEstado;
            //verificar si la lectura de un entero desde el archivo fue exitosa y, si no lo fue, devuelve 0 para indicar un error.
            if (fscanf(archivo, "%d", &siguienteEstado) != 1) return 0;
            //Asignar el siguiente estado a la matriz de transición
            dfa->transicion[i][(int)dfa->simbolos[j]] = siguienteEstado;
        }
    }
    return 1; // Lectura exitosa
}

// Procesa una cadena con el DFA
int procesarCadena(DFA* dfa, const char* entrada) {
    int estadoActual = 0; // Comenzar con el estado inicial 0

    // Recorrer cada carácter de la entrada
    for (int i = 0; entrada[i] != '\0'; i++) {
        // Verificar si el carácter pertenece al alfabeto
        if (strchr(dfa->simbolos, entrada[i]) == NULL) {
            printf("Error: '%c' no está en el alfabeto\n", entrada[i]);
            return -1; // Error: Carácter no válido
        }

        // Actualizar el estado actual basado en la transición
        estadoActual = dfa->transicion[estadoActual][(int)entrada[i]];
        // Verificar si la transición es válida
        if (estadoActual == -1) {
            printf("Error: Transición inválida\n");
            return -1; // Error: Transición no válida
        }
    }

    // Verificar si el estado final es de aceptación
    
    for (int i = 0; i < dfa->numEstadosAceptacion; i++) {
        if (estadoActual == dfa->estadosAceptacion[i]) return 1;
    }
    return 0; // Rechazada
}

// Main
int main() {
    // Crear un DFA
    DFA dfa;
    // Declarar el archivo y la entrada
    FILE *archivoConfig = NULL;
    char archivoNombre[100];
    //Declarara la entrada
    char entrada[MAX_ENTRADA];

    // Solicitar el nombre del archivo de configuración
    printf("Ingrese el nombre del archivo de configuración: ");
    //Obtener el archivo en local
    fgets(archivoNombre, sizeof(archivoNombre), stdin);
    //Asignar a la variable el nombre del archivo
    archivoNombre[strcspn(archivoNombre, "\n")] = 0; 

    // Abrir el archivo de configuración
    archivoConfig = fopen(archivoNombre, "r");
    //Sino se encontro la ruta del archivo, mostrar un error
    if (!archivoConfig) {
        printf("Error al abrir el archivo de configuración\n");
        return 1;
    }

    // Inicializar y configurar el DFA
    inicializarDFA(&dfa);
    //Sino se hixo la lectura exitosa ni del dfa declarado ni del archivo de configuracion
    if (!leerConfiguracionDFA(&dfa, archivoConfig)) {
        //Mostrar el error
        printf("Error al leer la configuración del DFA\n");
        //Cerra el archivo de configuracion
        fclose(archivoConfig);
        //Retorna 1 como error
        return 1;
    }
    fclose(archivoConfig);

    // Solicitar la cadena de entrada
    printf("Ingrese la cadena de entrada: ");
    //Usar los parametros de la funcion
    fgets(entrada, MAX_ENTRADA, stdin);
    entrada[strcspn(entrada, "\n")] = 0; // Eliminar el salto de línea

    // Procesar la cadena y mostrar el resultado
    int resultado = procesarCadena(&dfa, entrada);
    //Si es 1 se acepta la cadena
    if (resultado == 1) {
        printf("Resultado: La cadena fue aceptada.\n");
    } else if (resultado == 0) {
        //Si es 0 no esta en el archivo, se rechaza
        printf("Resultado: La cadena fue rechazada.\n");
    }

    // Finalizar el programa
    return 0;
}
