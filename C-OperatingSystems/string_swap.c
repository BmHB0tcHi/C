#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_STRING_LENGHT 20


int main(int argc, char* argv[]){


	assert(argc > 1);
	char *first_arg = argv[1];
	char *second_arg = argv[2];
	

	int i = 0;
	printf("First Arg : %s\n", first_arg);
	printf("Second Arg : %s\n", second_arg);
	
	int len_2 = strlen(second_arg);
	printf("String Lenght{2}: %d\n", len_2);
	printf("Swapping..\n");
	char *temp = first_arg;

	for (i = 0; i <= len_2; i++){
		temp[i] = second_arg[i];
		//temp = temp+1;
		//second_arg= second_arg +1;

	}
	
	printf("First Arg{Swapped}: %s\n", first_arg);

	
	
	return 0;
}
