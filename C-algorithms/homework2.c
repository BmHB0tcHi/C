//Bubble Sorting Method
#include <stdio.h>
int swapping(int x, int y) // This is not working for some reason :(
{
    int swap = x;
    x = y;
    y = swap;
}
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
    printf("Unsorted Array >> ");
    for(c = 0; c<n; c++) printf(" %d;",array[c]);// printing initial array
    printf("\n--------------------\n");
    for(c=0;c<(n-1);c++)
    {
        for(d=0;d<(n-c-1);d++)
        {
            if(array[d] < array[d+1] )
            {
                swap = array[d];
                array[d]= array[d+1];
                array[d+1] = swap;
            }
        }
    }
    printf("Sorting Array in Descending order......\n");
    printf("Sorted Array >> ");
    for(c=0;c<n;c++)
    {
        printf("%d,",array[c]);
    }
    printf("\n--------------------\n");
    return 0;
}