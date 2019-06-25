#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
    int age;
}*header=NULL;

void book(int val,int ag )
{
   struct node *n;
   n=(struct node *)malloc(sizeof(struct node));
   n->data=val;
   n->link=NULL;
   if(header==NULL)
   {
       header=n;
       n->age=ag;
   }
   else
   {
       n->link=header;
       header=n;
       n->age=ag;
   }
   printf("\n\t\tPassenger Details:");
   printf("\n\t\tPNR number:%d",n->data);
   printf("\n\t\tAge:%d",n->age);
}

int cancel(int val)
{
    struct node *p,*q;
    if(header==NULL)
    {
        printf("NO TICKET BOOKED YET.!!!!!!");
        return -1;
    }
    p=header;
    q=NULL;

    if(p->data==val)
    {
        header=p->link;
        return p->data;
    }

    while(p!=val)
    {
        if(p->data==val)
        {
           q->link=p->link;
           return p->data;
        }
        q=p;
        p=p->link;
    }
  printf("PLEASE CHECK YOUR PNR number:");
  return -1;

}

void main()
{
    int val,ch,no=100,ag;
    static int p=0,i=0,q=70;
    printf("\n**********************WELCOME TO INDIAN RAILWAYS*****************");
    do
    {
         printf("\n1.BOOK TICKETS \n 2.CANCEL TICKETS \n 3.CHECK TOUR STATUS:");
         printf("\n Enter your choice:");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1: if(i>70)
                    {
                        p++;
                        printf("SEATS NOT AVAILABLE:");
                    }
                    if(q>i)
                     {
                         printf("\n\t\t\tAVAILABLE %d",(q-i));
                         printf("\n\t\t\tEnter your age:");
                         scanf("%d",&ag);
                     }
                    no=no+i;
                    i++;
                    book(no,ag);

                    break;
             case 2:printf("Enter your PNR number:");
                    scanf("%d",&val);
                    cancel(val);
                    break;
         }
    }while(ch<4);
}
