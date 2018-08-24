#include<stdio.h>
struct book
{
 int accNo;
 char bookTitle[20];
 char author[20];
};
struct library
{
 int top;
 struct book b[100];
};

void push(struct library *l)
{
 if(l->top<100)
 {
   l->top++;
   printf("Enter the account no, book title, author");
   scanf("%d %s %s",&l->b[l->top].accNo,l->b[l->top].bookTitle,l->b[l->top].author);
 }
 else
  printf("\nPush not possible");
}

void pop(struct library *l)
{
 if(l->top>-1)
  l->top--;
 else
  printf("\nPop not possible");
}

int isEmpty(struct library l)
{
  if(l.top==-1)
   return(1);
  else 
   return(0);
}

int isFull(struct library l)
{
  if(l.top==99)
   return(1);
  else 
   return(0);
}

void search(struct library l,int n)   //by accNo
{
 int i=0,flag=0;
  
 for(;i<=l.top;i++)
  if(isEmpty(l)==0)
  {
   if(l.b[i].accNo==n)
   {
     printf("\n%d\t%s\t%s",l.b[i].accNo,l.b[i].bookTitle,l.b[i].author);
     flag++;
   }
  }
  else
   printf("Search not possible");
   if(flag==0)
   printf("book not found");
}

void print(struct library l)
{
 int i;
 if(l.top>-1)
 {
 printf("\nAccNo\t\tBookTitle\t\tAuthor\n");
 for(i=l.top;i>=0;i--)
  printf("%d\t\t%s\t\t\t%s\n",l.b[i].accNo,l.b[i].bookTitle,l.b[i].author);
 }
 else
  printf("\nprint not possible\n");
}


void main()
{
struct library l;

int ch;
l.top=-1;
do
{
printf("\n1.Push\n2.Pop\n3.Print\n4.Search\n5.isEmpty\n6.isFull\n7.quit\nEnter the choice");
scanf("%d",&ch);
switch(ch)
 {
  case 1:
  {
   push(&l);
   break; 
  }
  case 2:
  {
   pop(&l);
   break;
  }
  case 3:
  {
   print(l);
   break;
  }
  case 5:
  {
   if(isEmpty(l)==1)
   printf("\nThe stack is empty");
   else
   printf("\nThe stack is not empty");
   break;
  }
  case 6:
  {
   if(isFull(l)==1)
   printf("\nThe stack is full");
   else
      printf("\nThe stack is not full");

   break;
  }
  case 4:
  {
   int acc;
   printf("enter the account number to be searched");
   scanf("%d",&acc);
   search(l,acc); 
   break;
  }
  }
 }while(ch!=7);
   

 }

