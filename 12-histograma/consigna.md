# 12 - Máquinas de Estado — Histograma de longitud de palabras

Este trabajo está basado en el ejercicio 1-13 de [KR1988] de la sección arreglos:
```
Ejercicio 1-13. Escriba un programa que imprima el histograma de las longitudes de las palabras de su entrada.
Es fácil dibujar el histograma con las barras horizontales; la orientación vertical es un reto más interesante.
```

Problema: Imprimir un histograma de las longitudes de las palabras de en la
entrada estándar.

## 12.1. Objetivos

• Aplicar los conceptos de modularización.

• Utilizar las herramientas de compilación y construcción de ejecutables estudiadas.

• Aplicar máquinas de estado para el procesamiento de texto.

• Implementar máquinas de estado con diferentes métodos.

## 12.2. Temas

• Árboles de expresión.

• Representación de máquinas de estado.

• Implementación de máquinas de estado.

• Arreglos

• Flujos

• Modularización

## 12.3. Tareas

1. Árboles de Expresión
   
   a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras de [KR1988].

   b. Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.

   c. Dibujar el árbol de expresión para la expresión de control del segundo if: c == ' ' || c == '\n' || c == '\t'.

  
2. Máquina de Estado:

   a. Describir en lenguaje dot [DOT] y dentro del archivo histograma.gv la máquina de estado que resuelve el problema planteado.

   b. Formalizar la máquina de estados como una n-upla, basarse en el Capítulo #1 del Volumen #3 de [MUCH2012].

3. Implementaciones de Máquinas de Estado:
   
   Las implementaciones varían en los conceptos que utilizan para representaar los estados y las transiciones.

      a. Implementación #1: Una variable para el estado actual.

      i. Escribir el programa histograma-1-enum-switch.c que siga la Implementación #1, variante enum y switch.
      Esta implementación es la regularización de la implementación de la sección 1.5.4 de [KR1988]. Los estados son valores de una variable y las            transiciones son la selección estructurada y la actualización de esa variable. Esta versión es menos eficiente que la versión de [KR1988], pero         su regularidad permite la automatización de la construcción del programa que implementa la máquina de estados.
      Además de la regularidad, esta versión debe:

      • Utilizar typedef y enum en vez de define, de tal modo que la variable estado se pueda declarar de la siguiente manera: State s = Out;

      • Utilizar switch en vez de if.

      ii. Responder en readme.md: Indicar ventajas y desventajas de la versión de [KR1988] y de esta implementción.

      b. Implementación #2: Sentencias goto (sí, el infame goto)

      i. Leer la sección 3.8 Goto and labels de [KR1988]

      ii. Leer Go To Statement Considered Harmful de [DIJ1968].

      iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].

      iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?

      v. Escribir el programa histograma-2-goto.c que siga la Implementación #2.
      En esta implementación los estados son etiquetas y las transiciones son la selección estructurada y el salto incondicional con la sentencia goto.

      c. Implementación #3: Funciones Recursivas

      i. Leer la sección 4.10 Recursividad de [KR1988].

      ii. Responder en readme.md: ¿Es necesario que las funciones accedan a contadores? Si es así, ¿cómo hacerlo?.

      Leer la sección 1.10 Variables Externas y Alcance y 4.3 Variables Externas de [KR1988].

      iii. Escribir el programa, histograma-3-rec.c que siga la implementación #3.

      En esta implementación los estados son funciones recursivas y las transiciones son la selección estructurada y la invocación recursiva.

      d. Implementación #X:

      Es posible diseñar más implementaciones. Por ejemplo, una basada en una tabla que defina las transiciones de la máquina. En ese caso, el programa       usaría la tabla para lograr el comportamiento deseado. El objetivo de este punto es diseñar una implementación diferente a las implementaciones         #1, #2, y #3.

      i. Diseñar una nueva implementación e indicar en Readme.md cómo esa implementación representa los estados y cómo las transiciones.

      ii. Escribir el programa, histograma-x.c que siga la nueva implementación.

4. Escribir un único programa de prueba para las cuatro implementaciones.

5. (Opcional) Construir una tabla comparativa a modo de benchmark que muestre el tiempo de procesamiento para cada una de las cuatro                    implementaciones, para tres archivos diferentes de tamaños diferentes, el primero en el orden de los kilobytes, el segundo en el orden de los           megabytes, y el tercero en el orden de los gigabytes.

   Eficiencia del uso del Tiempo:
   La tabla tiene en las filas las cuatro implementación, en las columnas los tres archivos, y en la intersección la duración para una implementación      para un archivo.

# 12.4. Restricciones

- La implementación de la máquina de estado debe ser "seleccionable".

   Algunas formas posibles de implementar la selección son:

     -   En tiempo de traducción desde el makefile.
     -   En de tiempo de ejecución mediante reemplazlo de dynamic link library.
     -   En de tiempo de ejecución mediante argumentos de la línea de comandos.

-  La solución debe estar modularizada: las máquinas de estado no deben conocer del graficador y viceversa.

- Desde main.c se coordina todo.

# Crédito extra

Parametrizar si el histograma se dibuja vertical u horizontalmente.

# Productos

12.5. Productos
```
DD-histograma
|-- readme.md
| |-- Árboles de expresión.
| |-- Respuestas.
| `-- Benchmark.
|-- histograma.gv
|-- Makefile
|-- main.c
|-- Graficador.h
|-- Graficador.c
|-- Test.c
|-- histograma.h
|-- histograma-1-enum-switch.c
|-- histograma-2-goto.c
|-- histograma-3-rec.c
`-- histograma-x.c
```
