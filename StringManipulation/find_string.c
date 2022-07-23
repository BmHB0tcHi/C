/*
	[Beta-version]
	--> Find String in a text
	--> returns word_count in a give text

*/

#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){

	char *text = "hello dog cat loin cat bee snake dog dog";
	printf("Text: %s\n", text);
	char *word = "cat";
	int lenght_word = strlen(word);

	int i = 0;
	int letter_count = 0;
	int word_count = 0;
	
	char first_char = *(word+0);

	while (*text)
	{
		text = strchr(text, first_char);
		if (text == NULL)
			break;
		for (i=0;i<lenght_word;i++){
			if (*(text+i) == *(word+i))
				letter_count+=1;
		}
		
		if (letter_count == lenght_word)
				word_count+=1;
			
		else{
			letter_count = 0;
			text +=1;
		}
	}

	printf("Word[%s] Count: %d\n", word, word_count);
	return 0;
}
