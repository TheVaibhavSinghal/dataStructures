#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node * nptr;
}*top=NULL;
 
int isempty()
{
 if(top==NULL)
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

void push(int x)
{
 if(isfull())
  printf("push not possible");
 else
 {
   struct node *tmp=malloc(sizeof(struct node));
   if(top!=NULL);
     tmp->nptr=top;
   tmp->data=x;
   top=tmp;
   
 } 
}

int pop()
{
 int x=top->data;
 top=top->nptr;
 return(x);
}

void search(int x)
{
 if(!isempty())
  {
    int f=0;
    struct node *tmp=top;
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
    struct node *tmp=top;
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
 int n;
 float fact=1;
 printf("enter the number ");
 scanf("%d",&n);
 while(n!=0)
 {
  push(n--);
 }
 while(top!=NULL)
 {
  fact*=pop();
 
 }
 printf("the factorial is %.0f\n",fact);
 
/*do
 { printf("1.push\n2.pop\n3.search\n4.print\n5.isempty\n6.isfull\n7.quit\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: {
  if(!isfull())
  {
  printf("enter the element to be insert\n");
  int x;
  scanf("%d",&x);
  push(x);
  }
  else
  printf("push not possible\n");
  break;
  }
  case 2:
  {
  if(!isempty())
   printf("the deleted element is %d\n",pop());
  else
   printf("pop not possible\n");
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

*/
}
