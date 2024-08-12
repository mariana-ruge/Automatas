/*Realizado por:
 Sebastian Cortes Briceño
 Andres Sebastian Urrego Amaya
 Julian Esteban Rincon Rodriguez
 Mariana Ruge Vargas
*/


//Importar librerias
#include <stdio.h> //define constantes, macros, tipos y declara funciones de entrada y salida de secuencia.
#include <stdlib.h> //Gestiòn de la memoria dinamica en C
#include <string.h> //Definiciòn de macros constantes, funciones y algunos tipos de operaciones de manipualcion de memoria.

// Definir constantes de máximos en cadena
#define MAX_ESTADOS 20  //Numero maximo de estados en el DFA
#define MAX_SIMBOLOS 50 //Numero maximo de simbolos en el alfabeto
#define MAX_ENTRADA 1000 //Longitud maxima de cadenas en la entrada
#define TAMANIO_ASCII 128 //Tamaño del conjunto en caracteres ASCII

// Estructura del DFA (Autómata Finito Determinista)
typedef struct {
    int estados;        //Numero total de estados
    char simbolos[MAX_SIMBOLOS]; //Conjunto de simbolos en el alfabeto
    int estadosAceptacion[MAX_ESTADOS]; //Lista de estados de aceptacion
    int numEstadosAceptacion; //Numero de estados de aceptacion
    int transicion[MAX_ESTADOS][TAMANIO_ASCII]; //Matriz de transcion
} DFA;

// Inicializa el DFA
void inicializarDFA(DFA* dfa) {
    //Inicializar toda la estructuta del DFA en 0
    memset(dfa, 0, sizeof(DFA));

    //Inicializar todas las transiciones a -1 (no definido en el archivo de configuracion)
    //Filas - Con los estados
    for (int i = 0; i < MAX_ESTADOS; i++) {
        //Columnas - Con los caracters permitidos
        for (int j = 0; j < TAMANIO_ASCII; j++) {
            dfa->transicion[i][j] = -1;
        }
    }
}

// Lee la configuración del DFA desde un archivo
int leerConfiguracionDFA(DFA* dfa, FILE* archivo) {
    //Leer el conjunto de simbolos
    if (fscanf(archivo, "%s", dfa->simbolos) != 1) return 0;
    //Leer el numero total de estados
    if (fscanf(archivo, "%d", &dfa->estados) != 1) return 0;
    //Leer el numero de estados de aceptacion
    if (fscanf(archivo, "%d", &dfa->numEstadosAceptacion) != 1) return 0;
    //Leer los estados de aceptacion
    for (int i = 0; i < dfa->numEstadosAceptacion; i++) {
        if (fscanf(archivo, "%d", &dfa->estadosAceptacion[i]) != 1) return 0;
    }
    //Leer la tabla de transiciones
    //Filas de la tabla
    for (int i = 0; i < dfa->estados; i++) {
        //Columnas de la tabla
        for (int j = 0; dfa->simbolos[j] != '\0'; j++) {
            //Leer la transicion
            int siguienteEstado;
            //No se encuentra, retorna 0
            if (fscanf(archivo, "%d", &siguienteEstado) != 1) return 0;
            //Asignar la transicion
            dfa->transicion[i][(int)dfa->simbolos[j]] = siguienteEstado;
        }
    }
    return 1; //Lectura exitosa
}

// Procesa una cadena con el DFA
int procesarCadena(DFA* dfa, const char* entrada) {
    int estadoActual = 0; //Comenzar con el estado inicial 0

    //Recorrer cada caracter de la entrada
    for (int i = 0; entrada[i] != '\0'; i++) {
        //Verificar si el caracter pertenece al alfabeto
        if (strchr(dfa->simbolos, entrada[i]) == NULL) {
            printf("Error: '%c' no está en el alfabeto\n", entrada[i]);
            return -1; //Error: Caracter no valido
        }

        //Rechazar la transaccion
        estadoActual = dfa->transicion[estadoActual][(int)entrada[i]];
        //Verificar si la transicion es valida
        if (estadoActual == -1) {
            printf("Error: Transición inválida\n");
            return -1; //Error: Transicion no valida
        }
    }

    //Verificar si el estado final es de aceptacion
    //Recorrer los estados de aceptacion
    for (int i = 0; i < dfa->numEstadosAceptacion; i++) {
        if (estadoActual == dfa->estadosAceptacion[i]) return 1;
    }
    return 0; //Rechazada
}

//Main
int main(int argc, char *argv[]) {
    //Crear un DFA
    DFA dfa;
    //Iniciar el DFA
    //Declarar el archivo
    FILE *archivoConfig = NULL;
    //declarar la entrada
    char entrada[MAX_ENTRADA];

    //Verificar si se proporciono el archivo de configuracion
    if (argc != 2) {
        printf("Uso: %s <archivo_config>\n", argv[0]);
        return 1;
    }

    //Abrir el archivo de configuracion
    archivoConfig = fopen(argv[1], "r");
    //Si no encuentra el archivo
    if (!archivoConfig) {
        printf("Error al abrir el archivo de configuración\n");
        return 1;
    }

    //Inicializar y configurar el DFA
    inicializarDFA(&dfa);
    //Sino se pudo leer el archivo 
    if (!leerConfiguracionDFA(&dfa, archivoConfig)) {
        printf("Error al leer la configuración del DFA\n");
        //Cerrar el archivo de configuracion
        fclose(archivoConfig);
        return 1;
    }
    fclose(archivoConfig);

    // Solicitar la entrada del usuario en un bucle hasta que escriba "salir"
    while (1) {
        //Pedir por consola la cadena
        printf("Ingrese una cadena (o 'salir' para terminar): ");
        //Si la cadena esta vacia romper el bucle
        if (fgets(entrada, MAX_ENTRADA, stdin) == NULL) {
            break;
        }
        entrada[strcspn(entrada, "\n")] = 0; // Eliminar el salto de línea
        //Si la cadena es "salir" romper el bucle
        if (strcmp(entrada, "salir") == 0) {
            break;
        }

        //Procesar la cadena y mostrar el resultado
        int resultado = procesarCadena(&dfa, entrada);
        //Si la cadena es aceptada, mandara 1, desde procesarCadena.
        if (resultado == 1) {
            printf("La cadena '%s' es aceptada\n", entrada);
        //Si es rechazda devolvera 0 luego de recorrer todos los estados de aceptacion
        } else if (resultado == 0) {
            printf("La cadena '%s' es rechazada\n", entrada);
        }
    }
    //Finalizar el programa
    return 0;
}