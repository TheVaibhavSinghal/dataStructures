/*To find e^x*/
#include<stdio.h>
#include<math.h>

int factorial(int n)
{
 int f=1;
 for(int i=1;i<=n;i++)
  f*=i;
 return(f);

}

void main()
{ 
 int n,i,x;
 float eX=0;
 printf("Enter the value of the x and the number of terms");
 scanf("%d%d",&x,&n);
 for(i=0;i<n;i++)
    eX+=pow(x,i)/factorial(i);
 printf("The value of e^x = %f", eX);

}
 
 
