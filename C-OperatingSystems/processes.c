#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ARRAY_LENGHT 5

int main(){

	int array[ARRAY_LENGHT] = { 0 };
	pid_t pid;
	int i;
	printf("Enter random Numbers.\n");

	for (i = 0; i< ARRAY_LENGHT; i++ ){
		printf("\nIndex[%d] = ", i);
		scanf("%d", &array[i]);

	}
	pid = fork();
	if (pid == -1){
		printf("Error While forking\n");
		exit(1);
	}

	if(pid == 0)
	{
		printf("Child proccess..\n");
		int max =0;
		for (i = 0; i < ARRAY_LENGHT; i++){
				if (array[i] > max)
				max = array[i];
		}
		printf("MAX : %d\n", max);
	}
	else{
		wait(NULL);
	}

	return 0;
}
