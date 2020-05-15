#include <stdio.h>
int main()
{
    printf("Note: Using Insertion Method\n");
    int array[100],c,n,d,key_val;
    printf("Enter Number of Elements:\n");
    scanf("%d",&n);
    printf("Enter %d Integers\n", n);
    for(c=0;c<n;c++)
    {
        printf("Element %d: ",c);
        scanf("%d",&array[c]);
    }

    for(c=1;c<n;c++)
    {
        key_val=array[c];
        d = c - 1;
        while(d>=0 && array[d]> key_val)
        {
            array[d+1] = array[d];
            d = d-1;
        }
        array[d+1] = key_val; 
    }
    printf("Sorting Array in Ascending order  ......\n");
    for(c=0;c<n;c++)
    {
        printf("%d\n",array[c]);
    }

    return 0;
}