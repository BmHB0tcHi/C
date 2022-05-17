//Cocktail Sorting Method
#include<stdio.h>
int main()
{
    
    int array[100],n,c,d,swap;
    printf("Enter Number of Elements:\n");
    scanf("%d",&n);
    printf("Enter %d Integers\n", n);
    for(c=0;c<n;c++)
    {
        printf("Element %d: ",c);
        scanf("%d",&array[c]);
    }
    int min = array[0];
    int max = array[n-1];
    printf("Unsorted Array >> ");
    for(c = 0; c<n; c++) printf(" %d;",array[c]); // printing initial array
    printf("\n--------------------\n");
   
    while(min < max)
    {
        for (c=min; c<max; c++)
        {
            if(array[c]<array[c+1])
            {
                swap = array[c+1];
                array[c+1] = array[c];
                array[c] = swap;
            }
        }
        max--;
        for (d=max; d>max; d--)
        {
            if(array[d]>array[d-1])
            {
                swap = array[d-1];
                array[d-1] = array[d];
                array[d] = swap;
            }
        }
        min++;
    }
    printf("Sorting Array in Ascending order......\n");
    printf("Sorted Array >> ");
    for(c=0;c<n;c++)
    {
        printf("%d,",array[c]); //Printing sorted array 
    }
    printf("\n--------------------\n");
    return 0;




}