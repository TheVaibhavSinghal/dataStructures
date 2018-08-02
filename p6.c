#include<stdio.h>
#include<stdlib.h>

/*
for(i=0;i<n;i++)
 for(j=0;j<n-i-1;j++)
  if(a[j]>a[j+1])
    swap(a[j],a[j+1])



*/

void bSort(int a[100],int n)
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
   for(j=0;j<n-i-1;j++)
   {
     if(a[j]>a[j+1])
     {
	temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
     }
   }
 }

}


void sSort(int a[100],int n)
{
 int i,j,max,imax,temp;
 for(i=0;i<n;i++)
 {
   max=a[0];
   imax=0;
   for(j=1;j<n-i;j++)
     if(a[j]>max) 
       {
         max=a[j];
	 imax=j;
       }
   temp=a[n-i];
   a[n-i]=a[imax];
   a[imax]=temp;
 } 
}
void main()
{
 int n[10]={10,20,30,40,50,60,70,80,90,100},i,j;
 int a[10][100];

 for(i=0;i<10;i++)
 {
  for(j=0;j<n[i];j++)
    {
    	a[i][j]=rand()%10;
    }
 } 
 
 printf("the given array is:\n");
 for(i=0;i<10;i++)
 {
   for(j=0;j<n[i];j++)
     printf(" %d",a[i][j]);
   printf("\n");
 }



 printf("the sorted array is:\n");
 for(i=0;i<10;i++)
  {
    sSort(a[i],n[i]);
    for(j=0;j<n[i];j++)
		printf(" %d",a[i][j]);
    printf("\n");
  }



 /*printf("number of inputs\t\tnumber of comparison for search an item\n");
 for(i=0;i<20;i++)
 {
   for(j=0;j<n[i];j++)
     if(a[i][j]==num[i])
 	   break;
 
  printf("%d\t\t\t%d\n",n[i],j+1);
  wAvgNum += n[i]*(j+1);
 } 

 wAvg=wAvgNum/wAvgDen;

 printf("\n\nWeighted Average is %f",wAvg);

*/






}
