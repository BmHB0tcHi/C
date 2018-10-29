#include<stdio.h>

int main() {
	
	double a[5], e, c;
	e = 0;
	int i, k;
	for (i=0; i<5;  i++){	
	
	 printf(" \nEnter a value my friend : ");
	 scanf("%lf", &a[i]);
	 e=e+a[i];
         
          	
	}
	c= e/5;
    printf(" \nThe average value of the value u entered is : %lf", c);
	
	
	
    for (k=0; k<5; k++)
  
	 printf("\nyour value is : %lf  ", a[k]);
    
    
    
    
	return 0; 

}
