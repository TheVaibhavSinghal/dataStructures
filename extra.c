#include<stdio.h>
struct stack
{
 char a[100];
 int top;
 int isError;
};

void push(struct stack *s)
{
 s->top++;
 s->a[s->top]='(';
}

void pop(struct stack *s)
{
 if(s->top>-1)
  s->top--;
 else
  s->isError=1;
}

void main()
{
struct stack s;
char a[100];
s.top=-1;
s.isError=0;
printf("enter the expression");
scanf("%s",a);
for(int i=0;a[i]!='\0';i++)
{ 
 if(a[i]=='(')
  push(&s);
 else if(a[i]==')')
  pop(&s);
}
 if(s.top==-1 && s.isError==0)
  printf("All brackets matched");
 else
  printf("Brackets not matched");
}

