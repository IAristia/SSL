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
- La función main retorna valor 0, se ejecutó correctamente.


d. Creación hello4.o

gcc -c hello4.c

```
hello4.c: In function 'main':
hello4.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
  prontf("La respuesta es %d\n");}
  ^~~~~~
```

## 3. Vinculación

a. gcc -o hello4 hello4.o

```
hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
collect2.exe: error: ld returned 1 exit status
```

b. Creación hello5.c y creación hello5.exe

gcc hello5.c -o hello5.exe

c. Output de hello5.exe

```
La respuesta es 4200768
```

- ¿Por qué ahora vincula?

Anteriormente se intentó vincular prontf sin éxito ya que no había sido declarada, en esta versión, al haber cambiado prontf por printf fue capaz de vincularla correctamente con la declaración existente.

- ¿Por que tira basura y no 42?

La funcion printf tira basura y no 42 porque al usar %d la función espera otro parámetro numérico (que se pueda formatear a decimal) el cual no estamos especificando, esto produce que la función tome por referencia lo que sea que esté contenido en memoria (basura) y lo imprime.
  
## 4. Corrección de Bug

a. Creación hello6.c y hello6.exe

```
gcc hello6.c -o hello6.exe

hello6.exe 
La respuesta es 42
```
_printf_ funciona correctamente ya que añadimos el parámetro faltante mencionado en el punto 3.c.

## 5. Remoción de prototipo

a. Creación de hello7.c

b. 

i. gcc hello7.c

Arroja warning al momento de compilar

```
hello7.c: In function 'main':
hello7.c:3:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
  printf("La respuesta es %d\n", i);
  ^~~~~~
hello7.c:3:2: warning: incompatible implicit declaration of built-in function 'printf'
hello7.c:3:2: note: include '<stdio.h>' or provide a declaration of 'printf'
```

ii. Un prototipo es la declaración de una función, se indica qué tipo de dato develve, el nombre de la función y que tipo de dato recibe.
Se puede generar de dos maneras: explícitamente e implicitamente.

iii. Implícitamente: No se escribe el prototipo en el código fuente, sino que la función se invoca directamente, en este caso el vinculador se encargá de buscar la definición (por defecto lo hará en la bibilioteca estándar).

iv. La especificación indica el comportamiento esperado para funciones declaradas, pero no indica el comportamiento en caso de no estar declaradas.

v. En el caso de gcc, si no encuentra una declaración de una función, la busca en la librería estándar. En el caso de Clang, el compilador arroja un error.
En el caso de Clang, a partir de la versión 15, arroja un error al no encontrar una declaración de la función (no soporta declaración implícita de funciones)

vi. Las funciones "built-in" en C son funciones que están integradas directamente en el lenguaje (vienen en el compilador) y se proporcionan como parte de la biblioteca estándar de C.

vii. Al compilar hello7.c, GCC arroja warnings, no errores.

```
.\hello7.c: In function 'main':
.\hello7.c:4:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    4 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
.\hello7.c:4:5: warning: incompatible implicit declaration of built-in function 'printf'
.\hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | int main(void)
```
Estos warnings nos advierten del uso de la declaración implícita de printf, que no debería soportarse de acuerdo con el estándar de C99.
Al compilar con Clang (versión 15), el código arroja el siguiente error, en el cual se hace mención del estándar C99:

```
<source>:4:5: error: call to undeclared library function 'printf' with type 'int (const char *, ...)'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
    printf("La respuesta es %d\n", i);
    ^
<source>:4:5: note: include the header <stdio.h> or explicitly provide a declaration for 'printf'
1 error generated.
Compiler returned: 1
```

Sin embargo, GCC permite compilar esto ya que su razón de ser es trabajar en Linux, y este depende de las declaraciones implícitas para su funcionamiento.
Dejar de soportar estas declaraciones implícitas traería consigo la necesidad de hacer otros cambios mayores en el código fuente de Linux para que siga siendo compatible.
Como dijimos antes, la especificación define el comportamiento esperado únicamente en funciones explícitas, por lo que esto no va en contra de la especificación.

## 6. Compilación Separada: Contratos y Módulos

a. Creación de studio1.c y hello8.c.

b. En gcc podemos añadirle mas argumentos al comando de compilación, de manera que el compilador utilizará varios archivos para generar el ejecutable.

```
gcc studio1.c hello8.c -o hello8
```

En este caso, el programa compila.

```
hello8.exe

La respuesta es 42
```
c. La función prontf es un wrapper de la función printf que si bien en su declaración admite dos parámetros, esta le pasa un único parámetro a la función printf (el segundo).
Esto provoca que, al añadirle parámetros, la función siga arrojando exactamente el mismo resultado, pues esta simplemente no  usa los parámetros extras. Por otro lado, si eliminamos parámetros, la función utilizará como segundo parámetro lo que sea que este alojado en memoria, es decir, basura. 

d.
i. Creación de studio.h

ii. Creación de hello9.c

iii. Creación de studio2.c

iv.
- Permite tener más control sobre la utilización e implementación de funciones. El cliente debe respetar los parámetros al invocar la función, y el proveedor debe implementarla de acuerdo con la declaración del contrato.
- Es menos flexible, pero evita errores de tipado al implementar y al invocar funciones declaradas en el contrato, lo cual es una ventaja al reducir inconsistencias en el código.
