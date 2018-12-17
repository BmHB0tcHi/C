#include <stdio.h>

int main(void) {
	
	char str[1000] , ch;
	int i , frequency=0;
	
	
	printf("Enter a string: ");
	gets(str);
	
	printf("Enter the Character you want to find the frequency of : ");
	scanf("%c", &ch);
	
	for (i=0; str[i] != '\0'; ++i){
		
		if(ch==str[i])
        ++frequency;		
		
	}

printf("The frequency of the character you entered is : %d", frequency);	
	
	
return 0;	
	
	
}
