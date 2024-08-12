#include <stdio.h> /*Librería estándar de C*/
#include <stdlib.h> /*Control de procesos*/

int main()
    {
        FILE *archivo; /*Objeto capaz de almacenar información*/
        char caracter;/*Variable que almacena un caracter*/


        /* Permisos de los archivos:
            r: lectura
            w: escritura
            x: ejecución
        */

        archivo=fopen("./archivo.txt", "r"); //Accciones con los archivos
        if (archivo==NULL) //Significa que el archivo está vacío.
        {
            printf("Error en la apertura del archivo"); //Se imprime el error para evitar que se rompa el programa
        } 
        else //Si hay contenido en el archivo
        {
            printf("El contenido del archivo es: \n\n"); //Se imprime el contenido
            //Usar el while para obtener cada elemento de los archivos.
            while(feof(archivo) == 0) //Mientras el archivo tenga elementos
            {
                //feof: Comprueba el indicador al final del archivo.
                //Obtenemos el contenido del archivo
                caracter = fgetc(archivo);
                //Imprimimos el contenido del archivo
                printf("%c", caracter);
            }
        }
        fclose(archivo); //Cerramos el archivo para evitar problemas de memoria
        getchar(); //Pausa el sistema
        return 0; //Finaliza el programa
    }