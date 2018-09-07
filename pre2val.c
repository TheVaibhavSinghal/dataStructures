#include<stdio.h>
struct Post
{
 char a[100];
 int top;
};
void push(struct Post *p,char a)
{
 p->top++;
 p->top=a;
}
char pop(struct Post *p)
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
for(i=0;exp[i]!='\n';i++)
 {
   if(exp[i]>=0 && exp[i]<=9)
    push(&p,exp[i]);
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
 printf("\nthe value of expression is %c ",pop(&p));  
} 
