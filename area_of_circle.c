#include<stdio.h>

int main(void)
{
   float raduis;
   float circumference = 0.0f;
   float area = 0.0f;
   float pi = 3.14159265f;
  

   printf("Enter the raduis of the Circle : ");
   scanf("%f", &raduis);

   circumference=(2*pi*raduis);
   printf("The circumference of the circle is : %.2f \n", circumference);
     
   area=pi*raduis*raduis;
   printf("The area of the circle is : %.1f\n", area);



}
