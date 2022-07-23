#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGHT 30

void parse_by_space(char *str, int words){


	int i = 1;
	for (i = 1; i <= words; i++)
	{
		printf("Arg[%d]\n", i);
		while(*str != ' '){
			printf("%c", *str);
			str++;
		}
		printf("\n");
		if  (*str == ' ')
		str++;


		if(*str == '\0')
			break;
	}
	printf("\n");
}

int main()
{
	 char string[14] = "Hello im Cool\n";
    char* text = string;
	 parse_by_space(text, 2);
    return 0;
}
