#include <stdio.h>

int main(void) {
	
	char str1[50], str2[50];
	int i,k;
	k=0;
	printf("enter the sentence with spaces : ");
	gets(str1);
	
	for (i=0; str1[i]!= '\0'; ++i)
	 {
		    
		 if(str1[i+k]==' ')
		  {
		    k++;
		}
		    str2[i]=str1[i+k]; 
	  	
	}
	printf("your sentence without space is : ");
	puts(str2);
	
	
	return 0;
	
}
