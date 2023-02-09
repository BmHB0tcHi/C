#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * Exploring different function to read/write to files
*/


#define FORMAT " %d,%d "
#define MAX_BUFFER_LEN 30

typedef struct Point{
    int x, y;

} Point;

int main(int argc, char* argv[]){

    Point p1 = {12, 3};
    Point p2 = {0, 0};
    
    /* Init file descriptors */
    FILE* in;
    FILE* out;

    /* Init Buffers to write and read */
    char buffer_in[MAX_BUFFER_LEN];
    char buffer_out[MAX_BUFFER_LEN];

    /*we can also use w+ to write and read for the same fd , but we will need to handle the file cursor*/
    out = fopen("Hello.txt", "w"); 
    in = fopen("Hello.txt", "r");
    
    /* fopen returns NULL , if there was an error while opening the file */
    if ((out == NULL) || (in == NULL)){
        printf("Error Opening File \n");
        return 1;
    }
    
    snprintf(buffer_out, MAX_BUFFER_LEN, FORMAT, p1.x, p1.y);
    printf("%s\n", buffer_out);

    //fprintf(out, buffer_out);

    /* 
        fwrite syntax
        fwrite(buffer, size_of_element, len_of_buffer, fd_write)
        --> returns number of bytes written
    */

    size_t byte_wrote = fwrite(buffer_out , sizeof(char), strlen(buffer_out), out);
    if (byte_wrote != strlen(buffer_out)){
        printf("Error writing to file!");
        fclose(out);
        return 2;
    }
    
    /* Reseting the cursor back to the begining of the file(by adding 0 bytes to SEEK_SET), 
        evetually overwriting the previouse bytes written 
        SEEK_SET = Beginning of file
        SEEK_END = end of file
        SEEK_CUR = current cursor location
    */
    snprintf(buffer_out, MAX_BUFFER_LEN, FORMAT, 18, 10);
    /* comment out fseek to write both points to file */
    fseek(out, 0, SEEK_SET);

    byte_wrote = fwrite(buffer_out , sizeof(char), strlen(buffer_out), out);
    if (byte_wrote != strlen(buffer_out)){
        printf("Error writing to file!");
        fclose(out);
        return 1;
    }

    
    fclose(out);
    /*Reading from file can also be done using

        fgets(buffer, max_byte_to_read, fd)
        fgets(buffer_in, 100, in) returns bytes read
        sscanf(buffer, format, ...variable_pointers)
        
    */
    
    size_t bytes_read = (size_t)fgets(buffer_in, MAX_BUFFER_LEN, in);
    sscanf(buffer_in, FORMAT, &p2.x, &p2.y); 

    
    
    printf("Point2 %d:%d\n", p2.x, p2.y);
    
    fclose(in);
    return 0;
}