#include<stdio.h>

int main() {
	
	int i, j, k, e,  rows;
	
	printf("Enter the number of rows : ");
	scanf("%d" ,&rows);
	
	for (i=0; i<rows; i++) {
	   for (k=rows-i; k>0; k--) {
	       printf("  ");
        }
	    
	    for (j=0; j<i+1; j++){
	       printf(" %d", j+1);
	    }
	    
	  	for(e=i; e>0; e--){
          printf(" %d", e); 	
        }
       printf("\n"); 
	}
	
	 
	

	
	
	
	
	
	
	
	return 0;
}
