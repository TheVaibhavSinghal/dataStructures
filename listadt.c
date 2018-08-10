#include<stdio.h>
struct list
{
    int a[20];
    int size;
};

int isFull(struct list l)
{
 if(l.size==19)
  return 1;
 else 
  return 0;


}


int isEmpty(struct list l)
{
 if(l.size==0)
  return 1;
 else 
  return 0;
}


void insert(struct list *l,int pos,int x)
{
    if(pos<= l->size)   
    {
        if(isFull(*l)==0)
        {
        int i;
        for(i=l->size-1;i>=pos;i--)
        {
            l->a[i+1]=l->a[i];
        }
        l->a[pos]=x;
        l->size++;
        }
        else
        printf("The array is full");
    }
    else
    printf("The position given is out of range\n");
}


void delete(struct list *l,int pos)
{
    if(pos<l->size && pos>=0)
    {
        if(isEmpty(*l)==0)
        {
        int i;
        for(i=pos;i<l->size;i++)
         l->a[i]=l->a[i+1];
        l->size--;
        }
        else
        printf("The array is empty");
    }
    
    else
    printf("The position given is out of range\n");

}


int search(struct list l,int x)
{
    int i;
    for(i=0;i<l.size;i++)
    if (l.a[i]==x)
     return(i);
    return(-1);



}



void print(struct list *l)
{
    int i;
    for(i=0;i<l->size;i++)
    printf("%d ",l->a[i]);
    printf("\n");
}


void main()
{
    struct list l;
    int ch=0;
    l.size=0;
    do
    {
    printf("\n1.insert\n2.delete\n3.search\n4.print\n5.isfull\n6.isempty\n0.exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: 
    {
    int pos,val;
    printf("enter the pos and val to be inserted");
    scanf("%d %d",&pos,&val);
    insert(&l,pos,val);
    break;
    }
    case 2: 
    {
    int pos;
    printf("enter the pos to be deleted");
    scanf("%d",&pos);
    delete(&l,pos);
    break;
    }
    case 3: 
    {
    int val;
    printf("enter the val to be searched");
    scanf("%d ",&val);
    printf("%d\n",search(l,val));
    break;
    }
    case 4:      
    {
    print(&l);
    break;
    }
    case 5:
    {
    printf("%d",isFull(l));    
    break;
    }
    case 6:
    {
    printf("%d",isFull(l));    
    break;
    }
    } 
    }while(ch!=0);
}
