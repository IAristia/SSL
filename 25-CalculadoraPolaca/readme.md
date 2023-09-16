## ◦ Preguntas y Respuestas
a. ¿Es necesario modificar StackModule.h? ¿Por qué?

b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?

c. ¿Es necesario que Calculator muestre el lexema que originó el error léxico? Justifique su decisión.

- i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
Algunas opciones:

  - Tercer componente lexeme en Token ¿De qué tipo de dato es aplicable?

  - Cambiar el tipo de val para que sea un union que pueda
representar el valor para Number y valor LexError.

- ii. Implemente la solución según su decisión.
