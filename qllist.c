#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node * nptr;
}*rear=NULL,*front=NULL;
 
int isempty()
{
 if(rear==NULL)
  return(1);
 else
  return(0);
}  

int isfull()
{
 if(malloc(sizeof(struct node))==NULL)
  return(1);
 else
  return(0);
}

void enqueue(int x)
{
 if(isfull())
  printf("enqueue not possible");
 else
 {
   struct node *tmp=malloc(sizeof(struct node));
   tmp->data=x;
   if(rear!=NULL)
   {
    rear->nptr=tmp;
    rear=tmp;
   }
   else
   {
    front=tmp;
    rear=tmp;
   } 
 } 
}

int dequeue()
{
 int x=front->data;
 front=front->nptr;
 if(front==NULL)
  rear=NULL;
 return(x);
}

void search(int x)
{
 if(!isempty())
  {
    int f=0;
    struct node *tmp=front;
    while(tmp!=NULL)
    {
     
     if(tmp->data==x)
     {
      f=1;
      break;
     }
     tmp=tmp->nptr; 
    }
    if(f==1)
     printf("Present\n");
    else
     printf("Not present\n"); 
  }
  else
   printf("search not possible");

}

void print()
{
 if(!isempty())
  {
    struct node *tmp=front;
    while(tmp!=NULL)
    {
     printf("%d ",tmp->data);
     tmp=tmp->nptr; 
    } 
  }
  else
   printf("print not possible");
  printf("\n");
}



void main()
{
 int ch;
 do
 {
 
 printf("1.enqueue\n2.dequeue\n3.search\n4.print\n5.isempty\n6.isfull\n7.quit\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: {
  if(!isfull())
  {
  printf("enter the element to be insert\n");
  int x;
  scanf("%d",&x);
  enqueue(x);
  }
  else
  printf("enqueue not possible\n");
  break;
  }
  case 2:
  {
  if(!isempty())
   printf("the deleted element is %d\n",dequeue());
  else
   printf("dequeue not possible\n");
  break;
  } 
  case 3:
  {
   if(!isempty())
   {
   printf("enter the element to be searched");
   int x;
   scanf("%d",&x);
   search(x);
   }
   else
    printf("print not possible\n");
   break;
  }
 case 4:
 {
 print();break;
 }
 case 5:
 {
  if(isempty())
   printf("empty\n");
  else
   printf("not empty\n");
  break;
 }
 case 6:
 { 
  if(isfull())
   printf("full\n");
  else
   printf("not full\n");
  break;
 }
}
 }while(ch!=7);


}
