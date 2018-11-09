#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;//aadhar
    int phone;
    int height;
    struct node *lcptr;
    struct node *rcptr;
}*rptr=NULL;
int findheight(struct node *ptr)
{
	int h1,h2;
	if(ptr==NULL)
	 return -1;
	else
	{
	 h1=findheight(ptr->lcptr);
	 h2=findheight(ptr->rcptr);
	 if(h1 < h2)
	  return(h2+1);
	 else
	  return(h1+1);
	}
}
void updateheight(struct node *ptr)
{
	int h1,h2;
	if(ptr->lcptr==NULL)
	{
	  h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	if(ptr->rcptr==NULL)
	{
	h2=-1;
	}
	else
	h2=ptr->rcptr->height;
	if(h1<h2)
	 ptr->height=h2+1;
	else
	 ptr->height=h1+1;
}
struct node *rotateright(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->lcptr;
 jptr->lcptr=kptr->rcptr;
 kptr->rcptr=jptr;
 updateheight(jptr);
 updateheight(kptr);
 return kptr;
}
struct node *rotateleft(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->rcptr;
 jptr->rcptr=kptr->lcptr;
 kptr->lcptr=jptr;
 updateheight(jptr);
 updateheight(kptr);
 return kptr;
}
struct node *leftright(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->lcptr;
 ptr->lcptr=rotateleft(kptr);
 return(rotateright(jptr));
}
struct node *rightleft(struct node *ptr)
{
 struct node *jptr=ptr;
 struct node *kptr=ptr->rcptr;
 ptr->rcptr=rotateright(kptr);
 return(rotateleft(jptr));
}

struct node* insert(struct node *ptr,int d,int phone)
{
    if(ptr==NULL)
    {
      ptr=malloc(sizeof(struct node));
      ptr->data=d;
      ptr->phone=phone;
    ptr->height=0;
    ptr->lcptr=NULL;
    ptr->rcptr=NULL;
    }
    else
    {
            if(d<ptr->data)
            {  
              
              ptr->lcptr=insert(ptr->lcptr,d,phone); 
              if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==2))
              {
              	if(d<ptr->lcptr->data)
              	   ptr=rotateright(ptr);
              	else
              	   ptr=leftright(ptr);
              }
            }
            else
             {
               
                ptr->rcptr=insert(ptr->rcptr,d,phone);
             	if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2))
              {
              	if(d>ptr->rcptr->data)
              	   ptr=rotateleft(ptr);
              	else
              	   ptr=rightleft(ptr);
              }
             }
    }
     updateheight(ptr);
     return ptr;
}
void print(struct node *ptr)
{
	if(ptr!=NULL)
	{
	  print(ptr->lcptr);
	  printf("%d \t %d \t%d\t%d\n",ptr->data,ptr->phone,ptr->height,findheight(ptr->lcptr)-findheight(ptr->rcptr));
	  print(ptr->rcptr);
	}
}

void search()
{
	int x,flag=0;
	printf("Enter aadhar to be searched ");
	scanf("%d",&x);
	struct node *ptr=rptr;
	while(ptr!=NULL)
	{
	  if(ptr->data==x)
	  { printf("present\n"); flag++;break;
	  }
	  else if(x<ptr->data)
	   ptr=ptr->lcptr;
	  else
	   ptr=ptr->rcptr;
	}
	if(flag==0)
	 printf("not present\n");
}	 
void main()
{
 int ch,data,phone;
 do 
 {
 printf("1.Insert\n2.Print\n3.Search\n4.Exit\nEnter the choice ");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:
       printf("Enter the data and phone no to be inserted\n");
    scanf("%d %d",&data,&phone);
    rptr=insert(rptr,data,phone);break;
   case 2:print(rptr);break;
   case 3:search();break;
 }
 }while(ch!=4);
 }
