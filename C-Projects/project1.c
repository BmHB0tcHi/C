#include<stdio.h>

int main()
{

float perimeter, width, lenght, area;

printf("Enter the total lenght of the fence you have(in metres): ");
scanf("%f", &perimeter);


lenght = perimeter/6;
printf("Maximum Lenght is : %.1f metres \n", lenght);

width =  (perimeter - 3*lenght)/2;
printf("Maximum width  is : %.1f metres \n", width);

printf("Hence Maximum area = Maximum width x Maximum Lenght\n");

area = width*lenght;

printf("The maximum area possible of both rectangles is : %.1f m^2 \n", area);

// Proof that it is max 
printf("If we want to test if it is Maximum , we have to take Second derivative\n");
printf("Second derivative is going to be: -3/2xLenght\n");
printf("As you can see, the value of the second derivative is always going to be negative, which according to calculus book, its always maximum piont \n");








return 0;
}
