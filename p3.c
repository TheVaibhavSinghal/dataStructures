/*Program to find factorial*/
#include<stdio.h>
void main()
{
 int n,i,f=1;
 printf("Enter the number whose factorial is to be determined ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  f*=i;
 printf("The factorial of %d is %d\n",n,f);




}

