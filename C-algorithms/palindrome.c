#include<stdio.h>
#include<math.h>

int main(){
	
	int input, b, f, l, x, o;
	
	
	b=1;
	
	printf("Enter your input: ");
	scanf("%d", &input);
	o=input;
	
		   while(input>9){
               input=input/10;
 	            b++; 
	}
    printf("B = %d",b);
	
	x=pow(10,b-1);
	
	f=o/x;
	l=o%10;
	
	printf("\nF = %d",f);
	printf("\nl = %d",l);
	
	while(f=l){
		
		
		
		
		
	}
	
	

	
	
	
	return 0;
}
