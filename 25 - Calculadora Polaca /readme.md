25
Calculadora Polaca — Léxico
Este trabajo está basado en el la sección 4.3 de [KR1988]: Calculadora con
notación polaca inversa.
25.1. Objetivos
• Estudiar los fundamentos de los scanner aplicados a una calculadora con
notación polaca inversa que utiliza un stack.
• Implementar modularización mediante los módulos Calculator,
StackOfDoublesModule, y Scanner.
25.2. Temas
• Módulos.
• Interfaz.
• Stack.
• Ocultamiento de información.
• Encapsulamiento.
• Análisis léxico.
• Lexema.
• Token.
• Scanner.
• enum.
25.3. Tareas
1. Estudiar la implementación de las sección 4.3 de [KR1988].
2. Construir los siguientes componentes, con las siguientes entidades públicas:
Calculator StackOfDoublesModule Scanner
• Qué hace: Procesa
entrada y muestra
resultado.
• Qué usa:
◦ Biblioteca
Estándar
▪ EOF
▪ printf
▪ atof
◦ StackOfDoublesModule
▪ StackItem
▪ Push
▪ Pop
▪ IsEmpty
▪ IsFull
◦ Scanner
▪ GetNextToken
▪ Token
▪ TokenType
▪ TokenValue
• Qué exporta:
◦ StackItem
◦ Push
◦ Pop
◦ IsEmpty
◦ IsFull
• Qué hace: Obtiene
operadores y
operandos.
• Qué usa:
◦ Biblioteca
Estándar
▪ getchar
▪ EOF
▪ isdigit
▪ ungetc
• Qué exporta:
◦ GetNextToken
◦ Token
◦ TokenType
◦ TokenValue
1. Diagramar en Dot las dependencias entre los componentes e interfaces.
2. Definir formalmente y con digrafo en Dot la máquina de estados que
implementa GetNextToken, utilizar estados finales para diferentes para cada
clase de tokens.
3. Escribir un archivo expresiones.txt para probar la calculadora.
4. Construir el programa Calculator.
5. Ejecutar Calculator < expresiones.txt.
6. Responder:
a. ¿Es necesario modificar StackModule.h? ¿Por qué?
b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?
c. ¿Es necesario que Calculator muestre el lexema que originó el error
léxico? Justifique su decisión.
i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
Algunas opciones:
• Tercer componente lexeme en Token¿De qué tipo de dato es
aplicable?
• Cambiar el tipo de val para que sea un union que pueda
representar el valor para Number y valor LexError.
ii. Implemente la solución según su decisión.
25.4. Restricciones
• Aplicar los conceptos de modularización, componentes, e interfaces.
• En Calculator.c la variable token del tipo Token, que es asignada por
GetNextToken.
• Codificar StackOfDoublesModule.h a partir de la implementación contigua y
estática de StackModule, StackModuleContiguousStatic.c, del trabajo #4, y
modificar StackItem.
• Codificar Scanner.h y Scanner.c, para que usen las siguientes declaraciones:
enum TokenType {
 Number,
 Addition='+',Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};
typedef enum TokenType TokenType;
typedef double TokenValue;
struct Token{
 TokenType type;
 TokenValue val;
};
bool GetNextToken(Token *t /*out*/); // Retorna si pudo leer,
 almacena en t el token leido.
• GetNextToken debe usar una variable llamada lexeme para almacenar el
lexema leído.
• Usar las siguientes entidades de la biblioteca estándar:
◦ stdio.h
▪ getchar
▪ EOF
▪ stdin
▪ printf
▪ stdout
▪ getchar
▪ ungetc
◦ ctype.h
▪ isdigit
◦ stdlib.h
▪ atof
25.5. Productos
• Sufijo del nombre de la carpeta: PolCalc.
• /Readme.md◦ Preguntas y Respuestas.
• /expresiones.txt
• /Dependencias.gv
• /Calculator.c
• /StackOfDoublesModule.h
• /StackOfDoublesModule.c
• /Scanner.gv
• /Scanner.h
• /Scanner.c
• /Makefile
