## ◦ Preguntas y Respuestas
| calculadora polaca en C |
a. ¿Es necesario modificar StackModule.h? ¿Por qué?
no, porque no se necesita modificar nada de la implementacion de StackModule.h, ya que el stackModule que esta en el libro del lenguaje C es suficiente para las necesidades del programa.

b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?
si, porque no es un modulo que este incluido en el estandar C y se debe compilar para que el programa pueda usarlo.

c. ¿Es necesario que Calculator muestre el lexema que originó el error léxico? Justifique su decisión.
si, porque es necesario saber que es lo que esta mal en la expresion, para que el usuario pueda corregirla.

- i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
se puede mostrar el lexema en el mensaje de error.

Algunas opciones:

  - Tercer componente lexeme en Token ¿De qué tipo de dato es aplicable?


  - Cambiar el tipo de val para que sea un union que pueda
representar el valor para Number y valor LexError.

- ii. Implemente la solución según su decisión.
