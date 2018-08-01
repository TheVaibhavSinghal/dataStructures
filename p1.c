#include<stdlib.h>
#include<stdio.h>
void main()
{
int n[20]={10,20,30,40,50,60,70,80,90,100,110,120,125,130,135,140,145,150,155,160},i,j,num[20],wAvgNum=0,wAvgDen=0,randomIndex;
float wAvg;
int a[20][160];

for(i=0;i<20;i++)
{
  for(j=0;j<n[i];j++)
    {
    	a[i][j]=rand()%100;
    }
    wAvgDen+=n[i];
  randomIndex=rand()%n[i];
  num[i]=a[i][randomIndex];

}

printf("number of inputs\t\tnumber of comparison for search an item\n");
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



}  
    
   
   
   
   


