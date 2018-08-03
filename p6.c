#include<stdio.h>
#include<stdlib.h>


int bSort(int a[100],int n)
{
 int i,j,temp,nocB=0;
 for(i=1;i<n;i++)
 {
  
   for(j=0;j<n-i;j++)
   {
     nocB++;
     if(a[j]>a[j+1])
     {
	    temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        
     }
   }
    }
return nocB;
}


int sSort(int a[100],int n)
{
 int i,j,max,imax,temp,nocS=0;
 for(i=1;i<n;i++)
 {
   max=a[0];
   imax=0;
   for(j=1;j<=n-i;j++)
   {
     nocS++;
     if(a[j]>max) 
       {
         max=a[j];
	     imax=j;
       }
   
   }
   temp=a[n-i];
   a[n-i]=a[imax];
   a[imax]=temp;
 } 
 return nocS;
}


int iSort(int a[100],int n)
{
 int i,j,temp,nocI=0;
 for(i=1;i<n;i++)
  {
    for(j=i;j>0;j--)
    {
     nocI++;
     if(a[j]<a[j-1])
     {
       temp=a[j];
       a[j]=a[j-1];
       a[j-1]=temp;
     }
     else break;
    }
   }
   return nocI;    
}

  
  
  
  






void main()
{
 int n[10]={10,20,30,40,50,60,70,80,90,100},i,j,nocB,nocS,nocI;
 int a[10][100];

 for(i=0;i<10;i++)
 {
  for(j=0;j<n[i];j++)
    {
    	a[i][j]=rand()%100;
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
    bSort(a[i],n[i]);
    for(j=0;j<n[i];j++)
		printf(" %d",a[i][j]);
    printf("\n");
  }



 printf("number of inputs\tbSort\tsSort\tiSort\n");
 
 for(i=0;i<10;i++)
 {
   nocB=bSort(a[i],n[i]);
   nocS=sSort(a[i],n[i]);
   nocI=iSort(a[i],n[i]);
   printf("\t%d\t\t%d\t%d\t%d\n",n[i],nocB,nocS,nocI);
 } 

}
