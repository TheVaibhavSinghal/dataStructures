#include<stdio.h>

int assignPnr=1;
int Index=0;
struct Passenger
{
 int pnr;
 char name[20];
 int fare;
};

struct waitingListQueue
{
 struct Passenger w[100];
 int front;
 int rear;
};
 
void enqueue(struct waitingListQueue *q)
{
  if(q->rear==99)
   printf("queue is already full\n");
  else
  {
   q->rear++;
   if(q->front==-1)
    q->front++;
   printf("Enter name,fare\n");
   scanf("%s %d",q->w[q->rear].name,&q->w[q->rear].fare);
   q->w[q->rear].pnr=assignPnr++;
  }

}

void dequeue(struct waitingListQueue *q,struct Passenger cp[ ])
{
 if(q->rear==-1)
  printf("queue is empty\n");
 else if(q->front==q->rear)
   { 
    cp[Index++]=q->w[q->front];
    q->front=q->rear=-1;
   }
 else
 {
  cp[Index++]=q->w[q->front];
  q->front++;
 }
 
}

void search(struct waitingListQueue q,int pnr)
{
 int flag=0;
 
  for(int i=q.front;i<=q.rear;i++)
   if(q.w[i].pnr==pnr)
    {
     printf("%d\t%s\t%d\n",q.w[i].pnr,q.w[i].name,q.w[i].fare);
     flag++;
     break;
    }
    if(flag==0)
     printf("record not found\n");
 
}
void print(struct waitingListQueue q)
{
 if(q.rear==-1)
 printf("print not possible\n");
 else
 {
  for(int i=q.front;i<=q.rear;i++)
   printf("%d\t%s\t%d\n",q.w[i].pnr,q.w[i].name,q.w[i].fare);
 }
 
}

int isFull(struct waitingListQueue q)
{
 if(q.rear==99)
  return 1;
 else
  return 0;
}

int isEmpty(struct waitingListQueue q)
{
 if(q.rear==-1)
  return 1;
 else
  return 0;
}

void printConfirmedList(struct Passenger cp[ ])
{
 if(Index==0)
 printf("print not possible\n");
 else
 {
  for(int i=0;i<Index;i++)
   printf("%d\t%s\t%d\n",cp[i].pnr,cp[i].name,cp[i].fare);
 }
 
}
void main()
{
 struct waitingListQueue q;
 struct Passenger cp[100];
 int ch;
 q.rear=q.front=-1;
 do
 {
 printf("1.New Passenger\n2.Confirm ticket\n3.Check whether queue is full\n4.Check whether queue is empty\n5.Search\n6.Print waiting list\n7.Print confirmed list\n8.Quit\nEnter the choice ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  {
   enqueue(&q); break;
  }
  case 2: 
  {
   dequeue(&q,cp);break;
  }
  case 3: 
  {
  if(isFull(q)==1)
  printf("the queue is full\n");
  else
  printf("the queue is not full\n");
  break;
  }
  case 4:
  {
   if(isEmpty(q)==1)
   printf("the queue is empty\n");
   else
   printf("the queue in not empty\n");
   break;
  }
  case 5: 
  {
  if(isEmpty(q)==0)
  {
   int pnr;
   printf("enter the pnr number\n");
   scanf("%d",&pnr); 
   search(q,pnr);
  }
  else
   printf("search not possible\n");
  break;
  }
  case 6: print(q);break;
  case 7: printConfirmedList(cp);break;
 }
 }while(ch!=8);







}
