//Selection Method
#include <stdio.h>
//int swapping(int x, int y)
//{
    //int swap = x;
    //x = y;
    //y = swap;
//}
int main()
{
    printf("Note: Using Selection Method\n");
    int array[100],c,n,d,min,swap;
    printf("Enter Number of Elements:\n");
    scanf("%d",&n);
    printf("Enter %d Integers\n", n);
    for(c=0;c<n;c++)
    {
        printf("Element %d: ",c);
        scanf("%d",&array[c]);
    }

    for(c=0;c<(n-1);c++)
    {
        min = c;
        for(d=c+1;d<n;d++)
        {
            if(array[d]>array[min])
            {
                min = d;
            }
         
        }
         swap = array[c];
          array[c] =array[min];
          array[min] = swap;
    
   
    }
    printf("Sorting Array in Descending order  ......\n");
    for(c=0;c<n;c++)
    {
        printf("%d\n",array[c]);
    }
    return 0;
}