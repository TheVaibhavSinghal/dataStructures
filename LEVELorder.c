#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *lcptr;
 int data;
 struct node *rcptr;
}*rptr=NULL;

struct queue
{
struct node* ptr;
};
struct queue* front=NULL;
struct queue* rear=NULL; 

void insert()
{
 struct node *tmp=malloc(sizeof(struct node));
 if(tmp==NULL)
  printf("memory is full\n");
 else 
 {
   scanf("%d",&tmp->data);
   if(rptr==NULL)
    rptr=tmp;
   else
   {
     struct node *ptr=rptr,*pptr=rptr;
     while(ptr!=NULL)
     {
      pptr=ptr;
      if(ptr->data>tmp->data)
       ptr=ptr->lcptr;
      else
       ptr=ptr->rcptr; 
     }
     if(tmp->data<pptr->data)
      pptr->lcptr=tmp;
     else
      pptr->rcptr=tmp; 
   }
 
 }
}    

void print(struct node *ptr)
{
 if(ptr!=NULL)
 {
  printf("%d\n",ptr->data);
  print(ptr->lcptr);
  print(ptr->rcptr);
 }
}

void min()
{
 struct node *ptr=rptr;
 if(ptr==NULL)
  printf("empty\n");
 else
 { while(ptr->lcptr!=NULL)
   ptr=ptr->lcptr;
  printf("the min element is %d\n",ptr->data);
 }   
} 

void max()
{
 struct node *ptr=rptr;
 if(ptr==NULL)
  printf("empty\n");
 else
 { while(ptr->rcptr!=NULL)
   ptr=ptr->rcptr;
  printf("the max element is %d\n",ptr->data);
 }   
}

int left=0,right=0;
void printleftright(struct node *ptr)
{
 if(ptr->lcptr!=NULL)
  printf("%d ",ptr->lcptr->data);
 if(ptr->rcptr!=NULL)
  printf("%d ",ptr->rcptr->data);
}
void printlevel( struct node *trptr)
{
 
 if(trptr==rptr)
  printf("%d\n",trptr->data);
  
 printleftright(trptr);  
 
 printf("\n");
 
 printleftright(trptr->lcptr);
 printleftright(trptr->rcptr);
 
 printf("\n");
 
 printleftright(trptr->lcptr->lcptr);
 printleftright(trptr->lcptr->rcptr);
 printleftright(trptr->rcptr->lcptr);
 printleftright(trptr->rcptr->rcptr);
 
}
void main()
{
 int ch;
 do
 {
 printf("1.insert\n2.print in topological order\n3.min\n4.max\n5.quit\n6.print in level order\nenter the choice\n"); 
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: insert();break;
  case 2: print(rptr);break;
  case 3: min();break;
  case 4:max(); break;
  case 5:printlevel(rptr);break;
 }
 }while(ch!=5);
 
}
