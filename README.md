# Automatas: Implementacion de un AFD en C

**Realizado por: Sebastian Cortes Briceño, Andres Sebastian Urrego Amaya, Julian Esteban Rincon Rodriguez, Mariana Ruge Vargas.**


## Requisitos

1. Tener un sistema operativo basado en el Kernel de Linux .
2. Asegurate de tener C instalado en tu distribucion de Linux, puedes verificarlo ejecutando en tu terminal el siguiente comando:
`gcc -- version`
Esto deberia mostrarte **la version del compilador de C que corre en tu maquina**
En caso de no tener el compilador, por favor, ejecuta en la terminal:
`sudo apt install gcc`
Una vez completada la instalacion, verifica nuevamente la version de C.

* Este proyecto fue realizado con la siguiente version de C.
`gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
`

## Para usar este proyecto localmente
A continuacion, deberas clonar localmente este proyecto en tu entorno de trabajo.

1. Clonar el proyecto localmente: en tu terminal ejecuta el siguiente comando de git.
`git clone  https://github.com/mariana-ruge/Automatas.git`
2. Una vez clonado el proyecto, navega hasta la ruta del directorio donde se clono localmente.
`cd Automatas`
3. Compila el codigo fuente en tu terminal.
`gcc automatas.c`

### Uso de archivo del programa
En el proyecto encontraras un archivo llamado "config.txt", eso es porque el programa requiere un archivo de configuracion que  define los parametros del DFA.
Por favor revisar que el archivo se encuentre en tu repositorio local.

El programa para correr solicita como parametros 2 archivos de entrada.
1. El archivo de configuracion.
2. El archivo de entrada (input), lo encuentras en el proyecto como "input.txt".

Para hacer una correctar ejecucion del programa se debe realizar lo siguiente en la terminal.
 1. Navega hasta tu directorio local con el proyecto que has descargado.
 `cd Automatas`
 2. Compilar el codigo con el siguiente comando
`gcc automatas.c`

3. Ejecutar el programa con el ejecutable que dejo el compilador de C
`./automatas`

En la terminal se deberia solicitar primero el archivo de configuracion (config.txt)
y luego la cadena a validar con respecto al archivo.

Por ultimo, en la terminal se debera mostrar si la cadena fue aceptada o rechazada.

