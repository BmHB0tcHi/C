#include<stdio.h>

int main() {
	
	int a, i;
	
	printf("Enter a value for A : ");
	scanf("%d", &a);
	
	
	for (i=2; i<a;  i++)
	{
	if(a%i == 0)
	  printf("  %d, ", i);
}
	
	
	return 0;
}
