# Árboles de expresión
# Respuestas
## 3B: ¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?
No, hoy en día no tiene ninguna aplicación usar goto, ya que este salto de instrucción no respeta ningún contexto, ni encapsulamiento ni protecciones de seguridad. Además, el código que usa goto es muy difícil de leer y de mantener. Estas sentencias pueden ser simplemente reemplazadas por ciclos y otros condicionales. Por lo tanto, no se recomienda usar goto en ningún lenguaje moderno, ni aunque esté soportado.
Goto actualmente solo es utilizado en los scripts Batch de Windows, ya que estos no soportan ninguna sintaxis de control de flujo más moderna.
## 3C: ¿Es necesario que las funciones accedan a a contadores? Si es así, ¿cómo hacerlo?
No, no es necesario que las funciones accedan a los contadores, ya que estos pueden ser pasados como parámetros a las funciones, y así tampoco se requieren variables globales. El valor de retorno de la función es el mismo int que se pasó como parámetro, lo que le permite a la función que llamó actualizar el valor. El array con las cantidades de palabras es un parámetro que va por referencia, lo que permite que cada iteración lo modifique.
# Benchmark