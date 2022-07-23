
/*
	
	Basic Letter Swapping program
	
	 
	--> Program to swap two characters in a file
	--> File name will be provided by user, as an arguement by the user
	--> File will be mapped Using mmap
	--> Letters will be Swapped, and the final output will be Saved in a new file called "EditedFile.txt"
*/

// LIBS
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define MAX_ARGS 4

void PrintManual(){
	printf("\n--------------------------------------------------\n");
	printf("Please provide a file name, along with the two characters you want to swap\n");
	printf("EXAMPLE: \n --> [Swap filename letter1 letter2]\n");
	printf("letter1 will be swapped by letter2 in the provided file\n");	
	printf("After Completion, The program will create a new file called EditedFile.txt, which will be the final outcome\n");
	printf("Arg Count Must be 4(Including File Name)\n");
}	

int main(int argc, char* argv[]){
	//printf("%d\n", argc);

	if (argc != MAX_ARGS)
			PrintManual();
	
	const char* First_Letter = argv[2];
	const char* Second_Letter = argv[3];
	if(strlen(First_Letter) > 1){
		printf("Word 1 has to be a Character not a string...\n");
		PrintManual();
		exit(1);
	}
	
	if(strlen(Second_Letter) > 1){
		printf("Word 2 has to be a Character not a string...\n");
		PrintManual();
		exit(1);
	}
	const char* FileName = argv[1];
	// Opening file, to get FileDescriptor
 	int FileDesc = open(FileName, O_RDONLY);
	if (FileDesc < 0){
		printf("Error While opening file....\n");
		printf("Make Sure file name/path is correct..\n");
		exit(1);
	}

	// Getting File Size
	struct stat statbuf;
	int Error = fstat(FileDesc, &statbuf);
	if (Error == -1){
		printf("Error Getting File Statistics...\n");
		exit(1);
	}
	//Lets map the file
	char *Text =  mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, 
						MAP_PRIVATE,
                  FileDesc, 0);

   // Incase maping Failed
	if (Text == MAP_FAILED){
		printf("Mapping Failed..\n");
		exit(1);
	}
	close(FileDesc);
	
	// Lets Start Swapping...
	int j =0;
	char* CpyText = Text;
	int FileDesc2 = open("EditedFile.txt", O_CREAT | O_RDWR);
	for (j = 0; j< statbuf.st_size; j++){
		if (*(CpyText + j) == *First_Letter)
			*(CpyText + j) = *Second_Letter;
	}
	
	//Writing Swapped characters to new fileDesc
	ssize_t read = write(FileDesc2, Text, statbuf.st_size);
	close(FileDesc2);
	
	//Unmapping
	int error_unmap = munmap(Text, statbuf.st_size);
	if (error_unmap < 0){
		printf("Unmapping Failed...\n");
		exit(1);
	}

	return 0;
}
