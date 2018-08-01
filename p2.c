#include<stdio.h>
int counter=0;
int fibo(int n)
{
  counter++;
  if(n>2)
  return(fibo(n-1)+fibo(n-2));
  else if(n==1)
  return 0;
  else if(n==2)
  return 1;
}  
  
  
  void main()
{
 int n;
 printf("\nEnter the value ");
 scanf("%d",&n);
 printf("\nFibonacci number %d",fibo(n));
 printf("\nNumber of recursions %d",counter);
}
