/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two.
 * At the end the source code  should compile without warnings to the variant selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };	/* Recomendacion ARR02-C */
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s1 = "foo( \
Hello \
World \
)foo";		/* String literal multilinea acorde con los estandares (sin la variable 'R') */
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return;
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;					
  slash = (char*)malloc(sizeof(strrchr(pathname, '/'))); 	
  if (slash) {					
    *slash = '\0'; 	/* Regla STR30-C */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	fgets(response, sizeof(response), stdin);  	/* Recomendacion STR03-C (en funcion gets()) -Corregida- */	/* Regla STR31-C */ /* Regla MSC24-C (en funcion gets()) -Corregida- */

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = (char*)malloc(sizeof(char));	/* Recomendacion STR05-C */
    strcpy(ptr_char, "new string literal");
    //int size_array1 = strlen("аналитик");	//Unused variable
    //int size_array2 = 100;			//Unused variable
    
    // char analitic1[size_array1]="аналитик";	//Unused variable	/* Recomendacion STR11-C y ARR02-C */
    // char analitic2[size_array2]="аналитик";	//Unused variable	/* Recomendacion STR11-C  y ARR02-C*/
    //char analitic3[100]="аналитик";		//Unused variable	/* Recomendacion STR11-C  y ARR02-C*/

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);	/* Recomendacion STR03-C */	/* Recomendacion STR07-C */
    strcat(key, " = ");  	/* Recomendacion STR03-C */	/* Recomendacion STR07-C */
    strcat(key, argv[2]);	/* Recomendacion STR03-C */	/* Recomendacion STR07-C */


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));	/* Recomendacion STR07-C */
    strncpy(array4, array3, strlen(array3));	/* Recomendacion STR07-C */
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';		/* Regla STR30-C */
    
    array3[sizeof(array3)-1]='\0';	
    
    
    return 0;
}
