#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head;
void insertion_begining();
void insertion_last();
void insertion_specified();
void deletion_begining();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
int choice=0;
while(choice!=9)
{
printf("\n**********MENU**********\n");
printf("\nChoose one from the following list...\n");
printf("\n==========================\n");
printf("\n1.Insert at the begining\n");
printf("\n2.Insert at the last\n");
printf("\n3.Insert at any random location\n");
printf("\n4.Delete from begining\n");
printf("\n5.Delete from last\n");
printf("\n6.Delete the node after given data\n");
printf("\n7.Search\n");
printf("\n8.Show\n");
printf("\n9.Exit\n");
printf("\nEnter your Choice:\n");
scanf("\n%d",&choice);
switch(choice)
{
case 1:insertion_begining();
break;
case 2:insertion_last();
break;
case 3:insertion_specified(); 
break;
case 4:deletion_begining();
break;
case 5:deletion_last();
break;
case 6:deletion_specified();
break;
case 7:search();
break;
case 8:display();
break;
case 9:exit(0);
break;
default:printf("\nPlease enter valid choice\n");
}
}
}
void insertion_begining()
{
struct node *ptr;
int item;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOverflow\n");
}
else
{
printf("\nEnter item value");
scanf("%d",&item);
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->next=head;
ptr->prev=ptr;
head=ptr;
}
printf("\nNode inserted\n");
}
}
void insertion_last()
{
struct node *ptr,*temp;
int item;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOverflow\n");
}
else
{
printf("\nEnter item value");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
ptr->next=NULL;
}
}
printf("\nNode inserted\n");
}
void insertion_specified()
{
struct node *ptr,*temp;
int item,loc,i;
ptr=(struct node*)malloc (sizeof(struct node));
if(ptr==NULL)
{
printf("\nOverflow\n");
}
else
{
temp=head;
printf("\nEnter the location:");
scanf("%d",&loc);
for(i=1;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("\n There are less than %d elements",loc);
return;
}
}
printf("\nEnter value:");
scanf("%d",&item);
ptr->data=item;
ptr->next=temp->next;
ptr->prev=temp;
temp->next=ptr;
temp->next->prev=ptr;
printf("\nNode inserted\n");
}
}
void deletion_begining()
{
struct node *ptr;
if(head==NULL)
{
printf("\nunderflow\n");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\nNode Deleted\n");
}
else
{
ptr=head;
head=head->next;
head->prev=NULL;
free(ptr);
printf("\nNode deleted\n");
}
}
void deletion_last()
{
struct node *ptr;
if(head==NULL)
{
printf("\nunderflow\n");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\nNode Deleted\n");
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->prev->next=NULL;
free(ptr);
printf("\nNode Deleted\n");
}
}
void deletion_specified()
{
struct node *ptr,*temp;
int val;
printf("\nEnter the data after the node is to be deleted:");
scanf("%d",&val);
ptr=head;
while(ptr->data!=val)
ptr=ptr->next;
if(ptr->next==NULL)
{
printf("\nCan't Delete\n");
}
else if(ptr->next->next==NULL)
{
ptr->next=NULL;
}
else
{
temp=ptr->next;
ptr->next=temp->next;
temp->next->prev=ptr;
free(temp);
printf("\nNode Deleted\n");
}
}
void display()
{
struct node *ptr;
printf("\nPrinting values....\n");
ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("\nEmpty List\n");
}
else
{
printf("\nEnter item you want to search?\n");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\nitem found at location %d",i+1);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("\nItem not found\n");
}
}
}
