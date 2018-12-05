#include<stdio.h>
int primenum (int a);
int main()

{
 
    int k[3];
 
  k[0]=5;
  k[1]=10;
  k[2]=3;
 
     if(primenum(k[1])==0)
	printf(" %d is a Prime Number", k[1]);
       
   
	



return 0;

}


int primenum(int a){

int b,i;

       b=0;

      for(i=1; i<a; i++){
         
	      if(a%i == 0)
		      b=b+1;
	 }

      if(b==2)
	return 0;

	else
	return 1;
}


