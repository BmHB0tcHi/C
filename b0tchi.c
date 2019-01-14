#include<stdio.h>
 
 struct studentinfo
 {
 int age;
 char name[50];
 float grade;	
 	};
  int main()
{
   struct studentinfo s[4];
   int i; 
    
	for(i=1; i<5; i++){
	 
	 printf("Student %d age : ", i);
       scanf("%d", &s[i].age);
     printf("Student %d  Name  : ", i);
       scanf("%s", &s[i].name);
     printf("Student %d Grade :", i);
       scanf("%f", &s[i].grade);
       
    }
  
 
  
 
 
 
 
return 0;
}

