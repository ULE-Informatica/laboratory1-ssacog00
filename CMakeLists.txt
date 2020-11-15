#Para compilar con el fichero CMakeLists.txt:
#	- Crear directorio build
#	- Desde este directorio, ejecutar los sigientes comandos:
#		- cmake ..
#		- cmake --build .
#		- ./nombreEjecutable "argc1" "argc2"

cmake_minimum_required(VERSION 2.6)

project(Laboratory1)

set(CMAKE_CXX_STANDARD 99)
add_executable(exampleStrings exampleStrings.c)

