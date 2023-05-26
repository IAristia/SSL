## 1. Preprocesador

a. Creación de hello2.c

b. gcc -E hello2.c> hello2.i

 - Reemplaza los comentarios por espacios.
 
 - Expande recursivamente el #include <stdio.h>
 
 - No detecta errores semánticos, léxicos ni sintácticos.
 
 - Ahorra trabajo de escitura de código repetitivo y propenso a error.
 
 - El prefijo __ está reservado para elementos de la implementación.
 
 - Añade linemarkers para señalizar el código generado, esta característica es propia de GCC.
 
c. Creación de hello3.c

d. int printf(const char * restrict s, ...);

Esta línea es una declaración de una función llamada _printf_.

Esta función devuelve un tipo de dato _int_.

Esta función recibe un puntero al primer elemento de un array de chars (string).

_Const_ hace referencia a constante, lo que implica que el contenido del puntero recibido no se puede modificar.

_Restrict_ asegura que el único puntero que va a acceder a esa posición de memoria es el puntero "s".

La función acepta como mínimo un parmámetro

... implica que la función acepta cantidad variable de parámetros de cualquier tipo de dato.

e. Creación de hello3.i

Al no haber ninguna directiva ni ningun comentario, no hace ningún cambio descripto en el punto 1.b.

El único cambio es la adición de 4 líneas de linemarkes.

```
# 1 "hello3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hello3.c"
```
  
  
## 2. Compilación
  
## 3. Vinculación
  
## 4. Corrección de Bug
 
## 5. Remoción de prototipo

## 6. Compilación Separada: Contratos y Módulos

## 
