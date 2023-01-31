#include <stdio.h>
#define N 10


int main()
{
    int m1[N][N], m2[N][N], r1, c1, r2, c2, i, j, k, sum, m3[N][N];
    printf("Matrix 1 --> Rows: ");
    scanf("%d",&r1);
    printf("Matrix 1 --> Columns: ");
    scanf("%d",&c1);
    for (i =0;i<r1;i++){
        for (j=0;j<c1;j++){
            printf("M1[%d][%d]: \n",i,j);
            scanf("%d",&m1[i][j]);
        }
    }

    /// matrix 2
    printf("Matrix 2 --> Rows: ");
    scanf("%d",&r2);
    printf("Matrix 2 --> Columns: ");
    if(c1 != r2) {
        printf("Coloumn of matrix1 != rows of Matrix2\nExiting...\n");
        return 1;
    }

    scanf("%d",&c2);
    for (i =0;i<r2;i++) {
        for (j=0;j<c2;j++) {
            printf("M2[%d][%d]: \n",i,j);
            scanf("%d",&m2[i][j]);
        }
    }
    
    //multiplying matrix
    for(i=0;i<r1;i++) {
        for (j=0;j<c2;j++) {
            sum=0;
            for(k=0;k<c1;k++) {
                sum = sum + (m1[i][k]*m2[k][j]);
            }
            m3[i][j] = sum;
        }
    }

    // printing matrix 3[output]
     for(i=0;i<r1;i++) {
        for (j=0;j<c2;j++) {
            printf("Matrix3[%d][%d]: %d\n",i,j,m3[i][j]);

        }
    }

    return 0;
    
}