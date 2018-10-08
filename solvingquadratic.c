#include <stdio.h>
#include <math.h>
int main(){

   
	float a, b, c, d, e, f, g;

        printf("Enter Values for coefficient of x^2 , x and a constant term > ");
	scanf ("%f %f %f", &a, &b, &c);

        d = b*b - 4*a*c;

	if (d<0)
		printf("There are no real roots");

	if (d=0)
		printf("Both roots are equal");
             e= -b/(2*a);
	     printf("\nRoot is : %f ", e  );

	if (d>0)
	       printf("There are 2 distinct Roots..");

              f= (-b+sqrt(d))/(2*a);
              g= (-b-sqrt(d))/(2*a);

	      printf("the Roots are : %f and %f", f, g  );

return(0);
}


