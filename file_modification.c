/* 
    Renaming and Removing files
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



int main(int argc, char* argv[])
{

    const char* filename = "test.txt";
    const char* filename2 = "test2.txt";
    /* Creating file */
    FILE* test;
    printf("Creating file %s\n", filename);
    test = fopen(filename, "w");
    if (test == NULL){
        printf("Error Creating %s!\n", filename);
        fclose(test);
        return 1;

    }
    printf("%s creation successfull \n", filename);
    fclose(test);

    printf("Renaming %s to %s \n", filename, filename2);
    int res = rename(filename, filename2);
    if (res != 0){
        printf ("Error renaming %s\n%s\n", filename, strerror(errno));
        return 2;
    }
    printf("Renaming successfull\n");

    /* Rename function doesnt only return a value, but it also sets a global variabel
       called errno to a specific number.
       we can use the strerror() function to map errno , to some text which represents
       the corresponding error.
    */

    /* Intentionally causing an error
        res = rename("some_file", filename2);
        if (res != 0){
            printf ("Error renaming %s\n%s\n", filename, strerror(errno));
            return 2;
        }
    */

    /* intentionally causing erro*/
    res = remove(filename);
    if (res != 0){
        printf ("Error removing %s\n%s\n", filename, strerror(errno));
    }

    return 0;
}