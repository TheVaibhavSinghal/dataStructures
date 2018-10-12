#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct playlist
{
 struct playlist *prev;
 char song[20];
 struct playlist *next;
};
struct playlist *hptr=NULL;
struct playlist *cur=NULL;

void insert(char s[])
{
 struct playlist *tmp=malloc(sizeof(struct playlist));
 if(tmp==NULL)
 printf("memory full");
 else
 {
 	if(hptr==NULL)
 	{
      	hptr=tmp;
    	strcpy(tmp->song,s);
 	}
 	else
 	{
      strcpy(tmp->song,s);
      tmp->next=hptr;
      hptr->prev=tmp;
      hptr=tmp;
 	}
 }


}

char* Delete(char s[])
{
 struct playlist *thptr=hptr;
 int c=0;
 if(hptr!=NULL)
 {
  while(thptr!=NULL)
  {
   if(strcmp(thptr->song,s)==0)
   { 
    printf("deleted song:%s",thptr->song);
    c=1;
    if(thptr->next!=NULL && thptr->prev!=NULL) //MID 
    {(thptr->prev)->next=thptr->next;
    (thptr->next)->prev=thptr->prev;
    return("\n");
    }
    else if(thptr->prev==NULL) //left is null
    {
     (thptr->next)->prev=NULL;
     hptr=thptr->next;
     return("\n");
    }
    else
    {
     (thptr->prev)->next=NULL;
     return("\n");
    }
   }
   thptr=thptr->next;
  }
  if(c==0)
   return("not present\n");
 }
 else
  return("empty playlist\n");  
}

void previous()
{
 if(cur!=NULL)
 {
 if(cur->prev==NULL)
  printf("not possible\n");
 else
 {
   cur=cur->prev;
   printf("--------------------Currently playing %s--------------------\n",cur->song);
 }
 }
 else
  printf("first play a song\n");
}

void next()
{
 if(cur!=NULL)
 {
 if(cur->next==NULL)
  printf("not possible\n");
 else
 {
   cur=cur->next;
   printf("--------------------Currently playing %s--------------------\n",cur->song);
 }
 }
 else
  printf("first play a song\n");
}

char* search(char s[])
{
 struct playlist *thptr=hptr;
 if(hptr!=NULL)
 {
 while(thptr!=NULL)
 {
  if(strcmp(thptr->song,s)==0)
  {
   cur=thptr;
    printf("present\n");
    printf("--------------------Currently playing %s--------------------\n",cur->song);
    return("\n");
  }
  thptr=thptr->next;
 }
 return("not present\n");
 }
 else
  return("empty playlist\n");  
}

void print()
{ 
 if(hptr==NULL)
  printf("empty playlist\n");
 else
 {
  struct playlist *thptr=hptr;
  while(thptr!=NULL)
  {
   printf("%s\n",thptr->song);
   thptr=thptr->next;
  } 
 }
}
void main()
{
 struct playlist p;
 p.prev=p.next=NULL;
 int ch;
 do
 {
    printf("1.insert\n2.delete\n3.previous\n4.next\n5.search & play \n6.print playlist\n7.exit\nenter the choice ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:{
     printf("enter the song to be inserted ");
     char s[20];
     scanf("%s",s);
     insert(s);
     break;  
    }
   case 2:{
   char s1[20];
   printf("enter the song to be deleted ");
   scanf("%s",s1);
   printf("%s\n",Delete(s1));
   break;
   }
   case 3:
   {
    previous();
   break;
   }
   case 4:
   {
    next();
    break;
   }
   case 5:
   {
    printf("enter the song to be searched ");
    char s3[20];
    scanf("%s",s3);
    printf("%s\n",search(s3));
    break;
  }
  case 6:
  {
   print();
   break;
   }
  }
 }while(ch!=7);
}
 
