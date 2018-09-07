#include<stdio.h>
struct Post
{
 int a[100];
 int top;
};
void push(struct Post *p,int b)
{
 p->top++;
 p->a[p->top]=b;
}
int pop(struct Post *p)
{
 p->top--;
 return(p->a[p->top+1]);

}

void main()
{
struct Post p;
char exp[100];
p.top=-1;
int i=0;
printf("Enter the postfix expression ");
scanf("%s",exp);

for(i=0;exp[i]!='\0';i++)
 {
   
   if(exp[i]>=48 && exp[i]<=57)
    {
      push(&p,exp[i]-48);
    }
   else if(exp[i]=='+')
   {
    int b=pop(&p);
    int a=pop(&p);
    push(&p,a+b);
   }
   else if(exp[i]=='-')
   {
    int b=pop(&p);
    int a=pop(&p);
    push(&p,a-b);
   }
   else if(exp[i]=='*')
   {
    int b=pop(&p);
    int a=pop(&p);
    push(&p,a*b);
   }
   else if(exp[i]=='/')
   {
    int b=pop(&p);
    int a=pop(&p);
    push(&p,a/b);
   }
 }
 printf("The value of expression is %d\n ",pop(&p));  
} 
