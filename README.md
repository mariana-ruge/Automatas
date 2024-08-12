# Automatas

¿Que es un automata? Es una maquina que funciona por si misma y esta diseñada para realizar tareas especificas.

## Automatas Finitos Deterministas
Estos automatas se limitaran a aceptar o no una determinada cadena para recibir en la entrada, por lo tanto podemos que su salida solo tendra dos valores posibles a aceptar o no aceptar la entrada. El término “autómata finito” hace referencia a la variedad determinista.

*Formalmente, un autómata finito determinista es una quíntupla (Q, Σ, δ, q 0, F), donde:*

 Q: conjunto finito  no vacio de estados.

  Σ: alfabeto de entrada. 

δ: Q x Σ  Q, es la función total de transición. 

q 0 ∈ Q: estado inicial de autómata.

 F ⊆ Q: conjunto de estados finales.

**Procesamientos de las cadenas de un AFD**

Lo primero que tenemos que entender sobre un AFD es cómo decide si “aceptar” o no una secuencia de símbolos de entrada. El “lenguaje” del AFD es el conjunto de todas las cadenas que acepta. Supongamos que a1a2 · · ·an es una secuencia de símbolos de entrada. Comenzaremos con

o   Sea A AFD y w = a1a2…. an una cadena de entrada para A.

o   Iniciamos con A en su estado q0, δ(q0, a1) = q1.

o   Sea A AFD y w = a1a2… an una cadena de entrada para A.

o   Iniciamos con A en su estado q0, δ(q0, a1) = q1.

o   Procesamos a2, δ(q1, a2) = q2 y continuamos encontrando q3, q4, . . . , qn.

o   Sea A AFD y w = a1a2 … an una cadena de entrada para A.

o   Iniciamos con A en su estado q0, δ(q0, a1) = q1.

o   Procesamos a2, δ(q1, a2) = q2 y continuamos encontrando q3, q4, . . . , qn.

o   δ(qi1, ai) = qi para cada i

o   Sea A AFD y w = a1a2    an una cadena de entrada para A.

o   Iniciamos con A en su estado q0, δ(q0, a1) = q1.

o   Procesamos a2, δ(q1, a2) = q2 y continuamos encontrando q3, q4, . . . , qn.

o   δ(qi1, ai) = qi para cada i. Si qn 2 F diremos que la entrada w = a1a2    an es aceptada sino es rechazada

**Nos referimos a la fuente de esta secuencia como el flujo de entrada conforme llega cada símbolo del flujo de entrada, nuestro proceso de reconocimiento implica cambiar de un estado, tomando de entre una cantidad finita de ellos, a otro, o bien permanecer en el estado actual.  El nuevo proceso dependerá únicamente del estado actual y del símbolo del que se recibe.****


# Automatas
