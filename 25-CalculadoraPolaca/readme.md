1. Diagramar en Dot las dependencias entre los componentes e interfaces.

2. Definir formalmente y con digrafo en Dot la máquina de estados que implementa GetNextToken, utilizar estados finales para diferentes para cada clase de tokens.

M = (Q, Σ, q0, qf, T) donde:

Q = {Inicio, Sumar, Restar, Dividir, Multiplicar, Resultado, CaracterMenos, LiteralPositivo, LiteralPositivoFlotante, LiteralPositivoFinal, LiteralNegativo, LiteralNegativoFlotante, LiteralNegativoFinal, Error}

Σ = ASCII, partición P = {{caracter válido}, {caracter no válido}}.

  - Caracter válido = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, +, -, /, *, ' ', \t, \n, .}

  - Caracter no válido = ASCII - Caracter válido

  - Dígito = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}

  - Espaciador = {' ', \t, \n}

  - Operador = {+, -, /, *}

q0 = INICIO

qf = {Sumar, Restar, Dividir, Multiplicar, Resultado, LiteralPositivoFinal, LiteralNegativoFinal, Error}

T = {Inicio => espaciador => Inicio, 

Inicio => / => Dividir, 

Inicio => + => Sumar, 

Inicio => * => Multiplicar, 

Inicio => . => Error,  

Inicio => ^Z => Resultado, 

Inicio => Dígito => Literal Positivo, 

Inicio => - => Caracter menos,

Literal Positivo => Dígito => Literal Positivo, 

Literal Positivo => . => Literal Positivo Flotante,

Literal Positivo => Espaciador u Operando => Litreal Positivo Final, 

Literal Positivo Flotante => Dígito => Literal Positivo Flotante,

Literal Positivo Flotante => Espaciador u Operando => Litreal Positivo Final, 

Literal Positivo Flotante => . => Error, 

Caracter Menos => Espaciador u Operando => Restar, 

Caracter Menos => Dígito => Literal Negativo,

Literal Negativo => Dígito => Literal Negativo,

Literal Negativo => Espaciador u Operando => Literal Negativo Final, 

Literal Negativo => . => Literal Negativo Flotante,

Literal Negativo Flotante => Dígito => Literal Negativo Flotante,

Literal Negativo Flotante => . => Error, 

Literal Negativo Flotante => Espaciador u Operando => Literal Negativo Flotante}

3. Escribir un archivo expresiones.txt para probar la calculadora.

4. Construir el programa Calculator.

5. Ejecutar Calculator < expresiones.txt.

6. Responder:

| Calculadora polaca en C |

a. ¿Es necesario modificar StackModule.h? ¿Por qué?

No, debido a que la implementacion de StackModule.h existente en el libro del lenguaje C es suficiente para satisfacer las necesidades del programa.

b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?

Si, porque no es un modulo que este incluido en el estandar C y se debe compilar para que el programa pueda usarlo.

c. ¿Es necesario que Calculator muestre el lexema que originó el error léxico? Justifique su decisión.

Si, ya que es necesario saber qué es lo que esta mal en la expresión, de esta forma el usuario podrá corregirla.

- i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
  
Se puede mostrar el lexema en el mensaje de error.

Algunas opciones:

  - Tercer componente lexeme en Token ¿De qué tipo de dato es aplicable?


  - Cambiar el tipo de val para que sea un union que pueda representar el valor para Number y valor LexError.

- ii. Implemente la solución según su decisión.
