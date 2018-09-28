#include<stdio.h>
struct cqueue
{
 int front,rear;
 int a[5];
};

void enqueue(struct cqueue *c,int x)
{
 if((c->rear+1)%5==c->front)
  printf("enqueue not possible");
 else if(c->rear==-1)
 {
  c->rear=c->front=0;
  c->a[0]=x;
 }
 else
 {
   c->rear=(c->rear+1)%5;
  c->a[c->rear]=x;
 
 }
}

void dequeue(struct cqueue *c)
{
 if(c->front==-1)
  printf("dequeue not possible"); 
 else if(c->front==c->rear) 
 {  
   c->front=c->rear=-1;
 }
 else
 {
  c->front=(c->front+1)%5;
 }
}

void print(struct cqueue c)
{
 int i;
 /*if(c.rear>=c.front)
 {
   for(i=c.front;i<=c.rear;i++)
    printf("%d\n",c.a[i]);
 }
 else
 {
   for(i=c.front;i<5;i++)
     printf("%d\n",c.a[i]);
   for(i=0;i<=c.rear;i++)
     printf("%d\n",c.a[i]);*/
     for(i=c.front;((c.rear>=c.front) && (i<=c.rear)) || i!=c.rear ;i=(i+1)%5)
      printf("%d\n",c.a[i]);
 
}


int search(struct cqueue c,int x)
{
 int i;
 int flag=0;
 if(c.rear>=c.front)
 {
   for(i=c.front;i<=c.rear;i++)
    if(c.a[i]==x)
     flag++;
 }
 else
 {
   for(i=c.front;i<5;i++)
     if(c.a[i]==x)
      flag++;
   for(i=0;i<=c.rear;i++)
     if(c.a[i]==x)
      flag++;
      
 }
   return(flag);
}

int isEmpty(struct cqueue c)
{
 if(c.rear==-1)
  return(1);
 return(0);
}

int isFull(struct cqueue c)
{
 if(c.rear==c.front)
  return(1);
 return(0);
} 
 

void main()
{
 struct cqueue c;
 c.front=c.rear=-1;
 int ch;
 do
 {
   printf("1.Enqueue\n2.Dequeue\n3.Print\n4.Search\n5.Is empty\n6.Is full\n7.quit\n");               
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
    {
     int x;
     printf("enter the element to be inserted ");
     scanf("%d",&x);
     enqueue(&c,x); 
    }break;
    case 2:
    {
      dequeue(&c); 
    }break;
    case 3:
    {
     print(c); 
    }break;
    case 4:
    {
     int x;
     printf("enter the element to be searched ");
     scanf("%d",&x);
     if(search(c,x))
      printf("%d is present\n",x);
     else
      printf("%d not present\n",x); 
 
    }break;
    case 5:
    {
     if(isEmpty(c))
      printf("Array is empty\n");
     else
      printf("Array is not empty\n"); 
    }break;
    case 6:
    {
     if(isFull(c))
      printf("Array is full\n");
     else
      printf("Array is not full\n"); 
    }break;
    
  }
  }while(ch!=7);
 }

            
