#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
/* 
	--> Program to swap two words in a file
	--> File name will be provided by user, as an arguement by the user
	--> File will be mapped Using mmap
*/


#define MAX_ARGS 4

void PrintManual(){
	printf("\n--------------------------------------------------\n");
	printf("Please provide a file name, along with the two words you want to swap\n");
	printf("EXAMPLE: \n --> [Swap -f filename word1 word2]\n");
	printf("word1 will be swapped by word2 in the provided file\n");	
}



int main(int argc, char* argv[]){
	//printf("%d\n", argc);

	if (argc < MAX_ARGS){	
		PrintManual();
		printf("\n\nERROR: Not enough arguements provided...\n");
		exit(1);
	}
	int i;
	for (i = 1; i < argc; i++){
		printf("Arg[%d]: %s\n", i, argv[i]);
	}
	
	//char* Word1 = argv[3];
	//char* word2 = argv[4];
	
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
	void *Pointer =  mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, 
						MAP_PRIVATE,
                  FileDesc, 0);

   // Incase maping Failed
	if (Pointer == MAP_FAILED){
		printf("Mapping Failed..\n");
		exit(1);
	}
	close(FileDesc);
	int size_read = write(1, Pointer, statbuf.st_size);
	if (size_read != statbuf.st_size){
		printf("Size read != size provided\n");
		exit(1);
	}
	int error_unmap = munmap(Pointer, statbuf.st_size);
	if (error_unmap < 0){
		printf("Unmapping Failed...\n");
		exit(1);
	}

	
	return 0;
}
