#include <stdio.h>
#include <stdlib.h>

// Global Vars
#define MAX_NAME 20
#define MAX_STUDENTS 2

// Basic Struct
struct Student{

	char name[MAX_NAME];
	int age;
};


char* bigger(struct Student *ptr){

	int i, max = 0;

	for (i = 0; i< MAX_STUDENTS; i++){
		if (ptr[i].age > max){
			max = ptr[i].age;
		}
	}
	for(i = 0; i < MAX_STUDENTS; i++){
		if (ptr[i].age == max){
			/*
				Two ways to use pointers to structs
				(ptr+i)->name
				or
				ptr[i].name

			*/
			return ptr[i].name;
		}
	}
}

int main()
{
	struct Student *ptr;

	// Allocating an array of Students
	ptr = (struct Student*) malloc(MAX_STUDENTS * sizeof(struct Student));
	int i;

	for (i = 0; i<MAX_STUDENTS; i++){
		printf("\nEnter Student[%d] name: ", i);
		scanf("%s", (ptr+i)->name);
		printf("\nEnter Age[%d]: ", i);
		scanf("%d", &(ptr+i)->age);
	}

	//for(i=0; i<MAX_STUDENTS;i++)
		//printf("Student [%d]\nName: %s\nAge: %d\n", i, (ptr+i)->name,(ptr+i)->age); 

	char *oldest;
	oldest = bigger(ptr);
	printf("%s is oldest\n",oldest);
	// free(ptr);
	ptr = (struct Student *) realloc(ptr, 0);
	return 0;
}
