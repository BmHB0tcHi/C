#include <stdio.h>
#include <stdlib.h>

/*
    Demonstrating the several versions of printf() and how they are used
*/

int main(void){

    char buffer[100];
    int test = 3;
    printf("Test = %d\n", test);
    
    /* sprintf can be used to print to a certain buffer instead of stdout
        sprintf(buffer, "Test = %d", test);
        printf("%s\n", buffer);
    */
    // -------------------------------------------
    /*snprintf() can be used same as without the 'n', but the 'n' actually specifies the maximum
      amount of bytes to write
    */
    snprintf(buffer, 100, "Test = %d\n", test);
    printf("%s", buffer);

    /* fprintf , write to a stream / fd */
    fprintf(stderr, "test:%d\n", test);


    printf("Enter Character: ");
    /* getchar() === getc(stdin) === fgetc(stdin) */
    char c = getc(stdin);
  //char c2 = getchar();

    printf("%c\n", c);
  //printf("%c\n", c2);
    return 0;
}