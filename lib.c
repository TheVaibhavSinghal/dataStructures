#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 struct node *lcptr;
 int no;
 char title[100],name[100];
 struct node *rcptr;
}*rptr=NULL;


void insert()
{
 struct node *temp=malloc(sizeof(struct node));
 if(temp==NULL)
   printf("memory full");
  else
  {
    printf("enter the no,title,name of the record to be inserted ");
    scanf("%d %s %s",&temp->no,temp->title,temp->name);
    if(rptr==NULL)
    {
      rptr=temp;
     }
    else 
    {
     struct node *trptr=rptr;
     struct node *pptr=rptr;
     while(trptr!=NULL)
     {
      pptr=trptr;
      if(strcmp(temp->title,trptr->title)>=0)
       trptr=trptr->rcptr;
      else 
       trptr=trptr->lcptr;
       
     }
     if(strcmp(temp->title,pptr->title)>=0)
      pptr->rcptr=temp;
     else
      pptr->lcptr=temp;     }
    } 
}

void print(struct node *ptr)
{
 if(ptr!=NULL)
 {
  print(ptr->lcptr);
  printf("%s\n",ptr->title);
  print(ptr->rcptr);
 }
}

void search( )
{
  char title[100],c=0;
   printf("enter the title to be searched ");
    scanf("%s",title);
  struct node *trptr=rptr,*sptr;
   while(trptr!=NULL)
   {
     
      if(strcmp(title,trptr->title)==0)
      {
        sptr=trptr;
        c++;
        break;
      }
      else if(strcmp(title,trptr->title)>0)
       trptr=trptr->rcptr;
      else 
       trptr=trptr->lcptr;
   }
   if(c==0)
   printf("not present\n");
   else
   printf("%d\t%s\t%s\n",sptr->no,sptr->title,sptr->name);
}    
  
void Delete()
{
 char title[100],c=0;
   printf("enter the title to be deleted ");
   scanf("%s",title);
  struct node *ptr=rptr,*pptr=rptr;
   while(ptr!=NULL && c==0)
   {
     
      if(strcmp(title,ptr->title)==0)
      {
        if(ptr->lcptr==NULL && ptr->rcptr==NULL)
        {
         if(pptr->lcptr==ptr)
          pptr->lcptr=NULL;
         else
         pptr->rcptr=NULL;
         c++;break;
        }
        else if( ptr->lcptr!=NULL && ptr->rcptr==NULL || ptr->lcptr==NULL && ptr->rcptr!=NULL)
        {
         if(pptr->lcptr==ptr)
         {
          if(ptr->lcptr!=NULL)
           pptr->lcptr=ptr->lcptr;
          else
           pptr->lcptr=ptr->rcptr;
          c++;break;
         }
         else
         {
         if(ptr->lcptr!=NULL)
           pptr->rcptr=ptr->lcptr;
          else
           pptr->rcptr=ptr->rcptr;
          c++;break;
         }
        }
        else
        {
         struct node *kptr=ptr,*jptr=ptr->lcptr;   //kptr - parent , jptr-to be deleted
         while(jptr->rcptr!=NULL)
         {
          kptr=jptr;
          jptr=jptr->rcptr;
         }
         strcpy(ptr->title,jptr->title);
         strcpy(ptr->name,jptr->name);
         ptr->no=jptr->no;
         //delte jptr
          if(jptr->lcptr==NULL && jptr->rcptr==NULL)
        {
         if(kptr->lcptr==jptr)
         kptr->lcptr=NULL;
         else
         kptr->rcptr=NULL;
         c++;break;
         }
        else if( jptr->lcptr!=NULL && jptr->rcptr==NULL || jptr->lcptr==NULL && jptr->rcptr!=NULL)
        {
         if(kptr->lcptr==jptr)
         {
          if(jptr->lcptr!=NULL)
           kptr->lcptr=jptr->lcptr;
          else
           kptr->lcptr=jptr->rcptr;
           c++;break;
         }
         else
         {
         if(jptr->lcptr!=NULL)
           kptr->rcptr=jptr->lcptr;
          else
           kptr->rcptr=jptr->rcptr;
           c++;break;

         }
        }
        }
        
        
        
        
        
        
        
      }
      else if(strcmp(title,ptr->title)>0)
       {
       		pptr=ptr;
       		ptr=ptr->rcptr;
       }
      else 
       {
       		pptr=ptr;	
       		ptr=ptr->lcptr;
       }
       
    
   }
   if(c==0)
   printf("not present\n");
   
}    



void main()
{
 int ch;
 do
 {
 printf("1.Insert\n2.Delete\n3.Search\n4.Print\n5.quit\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: {	insert();
  		break;
  		} 
  case 2: Delete();break; 
  case 3: {
  		if(rptr==NULL)
  			printf("No records present\n");
 		else 
                    search();
                break;
           }     
  case 4: {
    		if(rptr==NULL)
  			printf("No records present\n");
 		else 
 			print(rptr);break;
 	  }
 }
 }while(ch!=5);
 
}
