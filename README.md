# dps-lab-1
Laboratory 1 - Sergio Saco García


##Compilacion normal (sin estandares):
###gcc -Wall exampleStrings.c

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
/tmp/ccxionRy.o: En la función `get_y_or_n':
exampleStrings.c:(.text+0xd8): aviso: the `gets' function is dangerous and should not be used.



##Compilacion con estandar c11:
###gcc -Wall exampleStrings.c -std=c11

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



##Compilacion con estandar c99:
###gcc -Wall exampleStrings.c -std=c99

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



##Compilacion con g++:
###g++ -Wall exampleStrings.c

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



##Analisis de resultados:
	Como podemos observar la compilación realizada sin especificar ningún estándar muestra una cantidad más reducidad de errores y 'warnings' que aquellas que si los especifican. 
	
	En el primer ejemplo mostrado ('gcc -Wall exampleStrings.c'), se muestra solamente avisos relacionados con:
	- Una función 'void' que retorna un entero.
	- Un aviso sobre la funcioón 'gets()', ya que, como hemos visto previamente, el uso de esta función no esta recomendado.
	- Tres avisos sobre tres variables que son declaradas pero no usadas.

	En el segundo ejemplo (gcc -Wall exampleStrings.c -std=c11), se muestran una mayor cantidad de 'warnings', entre los cuales se encuentran los detallados en el ejemplo anterior. El resto corresponden a lo siguiente:
	- Los primeros warnings y el primer error asociado corresponde a la declaracion de un 'string literal' en varias lineas con la ayuda de la letra 'R', la cual a partir del estandar c++11 permite la declaracion de 'raw string' en varias lineas, pero no esta contemplado en este estandar.
	- El resto de 'warnings' son los mismos que el primer ejemplo.

	En el tercer ejemplo (gcc -Wall exampleStrings.c -std=c99) muestra los mismos 'warning' y errores que el segundo ejemplo, a diferecia de que.
	- En este entandar el 'warning' sobre la función 'gets()' no hace referencia a que no es recomendad, si no que para este estandar, esta función ya se encuentra en estado 'deprecated'.

	Por último, el cuarto ejemplo (g++ -Wall exampleStrings.c), en el cual se utiliza el comando g++ para realizar la compilacion se obtiene lo siguiente:
	- Los mismos avisos que en el primer ejemplo.
	- Un error en la conversion de ‘const char*’ a ‘char*’, la cual se soluciona con el casteo de dicha conversión (char*).
	- Un aviso a la hora de almacenar un string en un puntero de tipo char.






