#include<stdio.h>
struct stack
{
 int a[10];
 int top;
};


void invert(struct stack *stack1,struct stack *stack2)
{
 int i,j;
 stack2->top=stack1->top;
 for(i=stack1->top,j=0;i>=0;i--,j++)
   stack2->a[j]=stack1->a[i];
}   
 

void enqueue(struct stack *s1,int x)
{
 if(s1->top==4)
  printf("enqueue not possible");
 else if(s1->top==-1)
 {
   s1->top=0;
   s1->a[0]=x;   
 }
 else
 {
  s1->top++;
  s1->a[s1->top]=x;
 }
}

void dequeue(struct stack *s1)
{ 
 struct stack s2;
 if(s1->top==-1)
  printf("dequeue not possible"); 
 else if(s1->top==0) 
 {  
   s1->top=-1;
 }
 else
 {
  invert(s1,&s2);
  s2.top--;
  invert(&s2,s1);
 }
}
 

void print(struct stack s1)
{
 int i;
 struct stack s2;
 if(s1.top==-1)
  printf("print not possible"); 
 else
 {
  invert(&s1,&s2);
  for(i=s2.top;i>=0;i--)
    printf("%d\n",s2.a[i]);
 }
} 
 
void main()
{
 struct stack s1;
 s1.top=-1; 
 int ch;
 do
 {
   printf("1.Enqueue\n2.Dequeue\n3.print\n4.quit\n");               
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
    {
     int x;
     printf("enter the element to be inserted ");
     scanf("%d",&x);
     enqueue(&s1,x); 
    }break;
    case 2:
    {
      dequeue(&s1); 
    }break;
    case 3:
    {
     print(s1);
    } break;
   
  }
  }while(ch!=4);
 }
