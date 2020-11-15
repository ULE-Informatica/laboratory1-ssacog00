# dps-lab-1
Laboratory 1 - Sergio Saco García

## Apartado 1

A continuación se detallarán todas las reglas y recomendaciones establececidas por el SEI CERT que se incumplen. En primer lugar se indica la línea de código del fichero 'exampleStrings.c' al que pertenece el ejemplo corregido, a continuación la regla o recomendación y por último, el porqué se incumple dicha regla o recomendación y cual es su solución:

### Buffer Overflows and strings

- Línea 41 -> Incumple la regla STR30-C. Do not attempt to modify string literals.
  + La funcion strrchr se utiliza para modificar el objeto al que apunta 'pathname', dado que el argumento apunta a un string literal el comportamiento es indefinido.
- Línea 51 -> Incumple la recomendación STR03-C. Do not inadvertently truncate a string.
  + Uso de la función 'gets()' en lugar de 'fgets()'. 
- Línea 51 -> Se incumple la regla STR31-C. Guarantee that storage for strings has sufficient space for character data and the null terminator.
  + La funcion gets() no comprueba el tamaño de los datos leidos, por lo que podria provocar un "buffer overflow". Se debe usar fgets() o gets_s().
- Línea 67 -> Incumple la recomendación STR05-C. Use pointers to const when referring to string literals.
  + Declaración de 'char *pointer' sin el uso del modificador 'const'.
- Líneas 72, 73 y 74 -> Incumple la recomendación STR11-C. Do not specify the bound of a character array initialized with a string literal.
  + No de debe declarar el tamaño de un array char si se inicializa con un string literal.
- Líneas 79, 80 y 81 -> Incumple la recomendación STR03-C. Do not inadvertently truncate a string.
  + Se deben realizar comprobaciones adicionales para asegurarse de que el buffer sea lo suficientemente grande.
- Líneas 79, 80, 81, 98 y 99 -> Incumple la recomendación STR07-C. Use the bounds-checking interfaces for string manipulation.
  + Se debeían utilizar las funciones alternativas a las mismas (`strcpy_s(), strcat_s(), strncpy_s(), and strncat_s()`) que permiten comprobar si la operación se puede o no realizar.
- Línea 102 -> Incumple la regla STR30-C. Do not attempt to modify string literals.
  + Se modifica un string literal


### Arrays

- Línea 18 -> Incumple la recomendación ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer.
  + En la declaracion de un array se debe especificar un valor correspondiente con el valor de incializacion.
- Líneas 72, 73 y 74 -> Incumple la recomendación ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer.
  + Esta recomendacion tiene una excepcion; ARR02-C-EX1: STR11-C. Do not specify the bound of a character array initialized with a string literal. Por lo que no es necesario especificar dicho valor cuando se inicializa el array con un string literal.
- Línea 72 -> Incumple la recomendacion ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer.
  + Aparte de que no necesario especificar este valor, este no se corresponde con el tamaño del string literal, por lo que de nuevo, se estaría incumpliendo esta recomendación.

### Miscellaneous

- Línea 51 -> Incumple la regla MSC24-C. Do not use deprecated or obsolescent functions.
  + La función 'gets()' en el estandar c99 se encuentra en estado 'deprecated'.


## Apartado 2

A continuación se mostrará la salida de pantalla obtenida en consola al compilar el fichero fuente dependiendo del compilador y estandar utilizado, así como un ánalisis de estos mensajes, en los cuales se detallan las diferencias que existen entre los mismos.

### Compilacion sin estandares:	 `$gcc -Wall exampleStrings.c`

```
exampleStrings.c: In function ‘gets_example_func’:
exampleStrings.c:32:16: warning: ‘return’ with a value, in function returning void
         return 1;
                ^
exampleStrings.c:28:6: note: declared here
 void gets_example_func(void) {
      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function ‘get_y_or_n’:
exampleStrings.c:51:2: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
  gets(response);
  ^~~~
  fgets
exampleStrings.c: In function ‘main’:
exampleStrings.c:73:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
     char analitic3[100]="аналитик";
          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
     int size_array2 = 100;
         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
     int size_array1 = strlen("аналитик");
         ^~~~~~~~~~~
/tmp/ccxionRy.o: En la función ‘get_y_or_n’:
exampleStrings.c:(.text+0xd8): aviso: the ‘gets’ function is dangerous and should not be used.
```

 
### Compilacion con estandar c11:  `$gcc -Wall exampleStrings.c -std=c11`

```
exampleStrings.c:22:19: warning: missing terminating " character
 const char* s1 = R"foo(
                   ^
exampleStrings.c:22:19: error: missing terminating " character
 const char* s1 = R"foo(
                   ^~~~~
exampleStrings.c:22:18: error: ‘R’ undeclared here (not in a function)
 const char* s1 = R"foo(
                  ^
exampleStrings.c:23:1: error: expected ‘,’ or ‘;’ before ‘Hello’
 Hello
 ^~~~~
exampleStrings.c:25:5: warning: missing terminating " character
 )foo";
     ^
exampleStrings.c:25:5: error: missing terminating " character
 )foo";
     ^~
exampleStrings.c: In function ‘gets_example_func’:
exampleStrings.c:32:16: warning: ‘return’ with a value, in function returning void
         return 1;
                ^
exampleStrings.c:28:6: note: declared here
 void gets_example_func(void) {
      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function ‘get_y_or_n’:
exampleStrings.c:51:2: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
  gets(response);
  ^~~~
  fgets
exampleStrings.c: In function ‘main’:
exampleStrings.c:94:11: error: ‘s2’ undeclared (first use in this function); did you mean ‘s1’?
     puts (s2);
           ^~
           s1
exampleStrings.c:94:11: note: each undeclared identifier is reported only once for each function it appears in
exampleStrings.c:73:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
     char analitic3[100]="аналитик";
          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
     int size_array2 = 100;
         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
     int size_array1 = strlen("аналитик");
         ^~~~~~~~~~~
```



### Compilacion con estandar c99:  `$gcc -Wall exampleStrings.c -std=c99`

```
exampleStrings.c:22:19: warning: missing terminating " character
 const char* s1 = R"foo(
                   ^
exampleStrings.c:22:19: error: missing terminating " character
 const char* s1 = R"foo(
                   ^~~~~
exampleStrings.c:22:18: error: ‘R’ undeclared here (not in a function)
 const char* s1 = R"foo(
                  ^
exampleStrings.c:23:1: error: expected ‘,’ or ‘;’ before ‘Hello’
 Hello
 ^~~~~
exampleStrings.c:25:5: warning: missing terminating " character
 )foo";
     ^
exampleStrings.c:25:5: error: missing terminating " character
 )foo";
     ^~
exampleStrings.c: In function ‘gets_example_func’:
exampleStrings.c:32:16: warning: ‘return’ with a value, in function returning void
         return 1;
                ^
exampleStrings.c:28:6: note: declared here
 void gets_example_func(void) {
      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function ‘get_y_or_n’:
exampleStrings.c:51:2: warning: ‘gets’ is deprecated [-Wdeprecated-declarations]
  gets(response);
  ^~~~
In file included from exampleStrings.c:13:0:
/usr/include/stdio.h:577:14: note: declared here
 extern char *gets (char *__s) __wur __attribute_deprecated__;
              ^~~~
exampleStrings.c: In function ‘main’:
exampleStrings.c:94:11: error: ‘s2’ undeclared (first use in this function); did you mean ‘s1’?
     puts (s2);
           ^~
           s1
exampleStrings.c:94:11: note: each undeclared identifier is reported only once for each function it appears in
exampleStrings.c:73:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
     char analitic3[100]="аналитик";
          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
     int size_array2 = 100;
         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
     int size_array1 = strlen("аналитик");
         ^~~~~~~~~~~
```



### Compilacion con g++:  `$g++ -Wall exampleStrings.c`

```
exampleStrings.c: In function ‘void gets_example_func()’:
exampleStrings.c:32:16: error: return-statement with a value, in function returning 'void' [-fpermissive]
         return 1;
                ^
exampleStrings.c: In function ‘const char* get_dirname(const char*)’:
exampleStrings.c:39:18: error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
   slash = strrchr(pathname, '/');
           ~~~~~~~^~~~~~~~~~~~~~~
exampleStrings.c: In function ‘void get_y_or_n()’:
exampleStrings.c:51:2: error: ‘gets’ was not declared in this scope
  gets(response);
  ^~~~
exampleStrings.c:51:2: note: suggested alternative: ‘fgets’
  gets(response);
  ^~~~
  fgets
exampleStrings.c: In function ‘int main(int, char**)’:
exampleStrings.c:67:23: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
     char *ptr_char  = "new string literal";
                       ^~~~~~~~~~~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
     int size_array1 = strlen("аналитик");
         ^~~~~~~~~~~
exampleStrings.c:69:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
     int size_array2 = 100;
         ^~~~~~~~~~~
exampleStrings.c:73:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
     char analitic3[100]="аналитик";
          ^~~~~~~~~
```


## Analisis de resultados:
	
En el primer ejemplo mostrado ('gcc -Wall exampleStrings.c'), se muestra solamente avisos relacionados con:
- Una función 'void' que retorna un entero.
- Un aviso sobre la funcioón 'gets()', ya que, como hemos visto previamente, el uso de esta función no esta recomendado.
- Tres avisos sobre tres variables que son declaradas pero no usadas.

En el segundo ejemplo (gcc -Wall exampleStrings.c -std=c11), se muestran una mayor cantidad de 'warnings', entre los cuales se encuentran los detallados en el ejemplo anterior. El resto corresponden a lo siguiente:
- Los primeros warnings y el primer error asociado corresponde a la declaracion de un 'string literal' en varias lineas con la ayuda de la letra 'R', la cual a partir del estandar c++11 permite la declaracion de 'raw string' en varias lineas, pero no esta contemplado en este estandar.
- El resto de 'warnings' son los mismos que el primer ejemplo.

En el tercer ejemplo (gcc -Wall exampleStrings.c -std=c99) muestra los mismos 'warning' y errores que el segundo ejemplo, a diferecia de que.
- En este entandar el 'warning' sobre la función 'gets()' no hace referencia a que no es recomendada, si no que para este estandar, esta función ya se encuentra en estado 'deprecated'.

Por último, el cuarto ejemplo (g++ -Wall exampleStrings.c), en el cual se utiliza el comando g++ para realizar la compilacion se obtiene lo siguiente:
- Los mismos avisos que en el primer ejemplo.
- Un error en la conversion de ‘const char*’ a ‘char*’, la cual se soluciona con el casteo de dicha conversión (char*).
- Un aviso a la hora de almacenar un string en un puntero de tipo char.






