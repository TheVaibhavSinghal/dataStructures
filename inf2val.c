#include<stdio.h>
struct Post
{
 char a[100];
 int top;
};

int precedence(char a)
{
 switch(a)
 {
  case '+':
  case '-': return(1);break;
  case '*':
  case '/':return(2);break;
  //default:return(3);
 }
}
void push(struct Post *p,char b)
{
 p->top++;
 p->a[p->top]=b;
}
void pop(struct Post *p)
{
 
  if(p->a[p->top]!='(')
   printf("%c",p->a[p->top]);
  p->top--;
 
}


void main()
{
 struct Post p;
 int i=0;
char exp[100]; 
 p.top=-1;
 
 printf("Enter the infix expression ");
 scanf("%s",exp);


for(i=0;exp[i]!='\0';i++)
 {
   
   if(exp[i]>=48 && exp[i]<=57)
    {
      printf("%d",exp[i]-48);
    }
   else if(exp[i]=='(')
    push(&p,'(');
   else if(exp[i]==')')
   {
    while(p.a[p.top]!='(')
     pop(&p);
   pop(&p);
   }
   else if(exp[i]=='+')
   {
    while (precedence('+')<precedence(p.a[p.top]) && p.a[p.top]!='(')
    {
        pop(&p);
    }
    push(&p,'+');
   }
   else if(exp[i]=='-')
   {
    while (precedence('-')<precedence(p.a[p.top])&& p.a[p.top]!='(')
    {
        pop(&p);
    }
    push(&p,'-');
   }
   else if(exp[i]=='*')
   {
    while (precedence('*')<precedence(p.a[p.top]) && p.a[p.top]!='(' )
    {
        pop(&p);
    }
    push(&p,'*');
   }
   else if(exp[i]=='/')
   {
    while (precedence('/')<precedence(p.a[p.top]) && p.a[p.top]!='(')
    {
        pop(&p);
    }
    push(&p,'/');
   }
 }
  while(p.top!=-1)
   pop(&p);
}
 


