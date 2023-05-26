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
a. Creación de hello3.s

gcc -S hello3.c

``` 
hello3.c: In function 'main':
hello3.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
  prontf("La respuesta es %d\n");
  ^~~~~~
hello3.c:4:2: error: expected declaration or statement at end of input
```

Este error es de tipo sintáctico, resultante de no haber declarado el final del código main, al no haber escrito la llave de cierre.

b. Creación de hello4.c y hello4.s

gcc -S hello4.c 
```
hello4.c: In function 'main':
hello4.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
  prontf("La respuesta es %d\n");}
  ^~~~~~
```

c. hello4.s

- Define la función main.
- Reserva espacio en memoria para las variables a utilizar.
- Crea la etiqueta LC0 y le asigna "La respuesta es %d\12\0".
- Llama a la función main.
- Guarda el valor 42 en el registro llamado 28(%esp).
- Guarda el contenido de LC0 en el registro llamado (%esp).
- Llama a la función prontf.
- La función main retorna valor 0, se ejcutó correctamente.


d. Creación hello4.o

gcc -c hello4.c

```
hello4.c: In function 'main':
hello4.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
  prontf("La respuesta es %d\n");}
  ^~~~~~
```

## 3. Vinculación
  
## 4. Corrección de Bug
 
## 5. Remoción de prototipo

## 6. Compilación Separada: Contratos y Módulos

## 
