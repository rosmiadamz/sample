#include <stdio.h>
#define MAXSIZE 5
struct stack
{
int stk[MAXSIZE];
int top;
};
typedef struct stack STACK;
STACK s;
void push(void);
int pop(void);
void display(void);
void main()
{
int choice;
int option=1;
s.top=-1;
printf("STACK OPERATION\n");
while(option)
{
printf("..............\n");
printf("1-->Push \n");
printf("2-->Pop \n");
printf("3-->Display \n");
printf("4-->Exit\n");
printf("................\n");
printf("Enter your choice \n");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
return;
}
fflush(stdin);
printf("Do You Want To Continue(0 or 1): \n");
scanf("%d",&option);
}
}
/*function to add an element to the stack */
void push()
{
int num;
if(s.top==(MAXSIZE-1))
{
printf("stack is full \n");
return;
}
else
{
printf("\n Enter the element to be push \n");
scanf("%d",&num);
s.top=s.top+1;
s.stk[s.top]=num;
}
return;
}
/*function to delete an element from the stack */
int pop()
{
int num;
if(s.top==-1)
{
printf("/n stack is empty");
return(s.top);
}
else
{
num=s.stk[s.top];
printf("poped element is =%d\n",s.stk[s.top]);
s.top=s.top-1;
}
return(num);
}
/*function to display the status of the stack */
void display()
{
int i;
if(s.top==-1)
{
printf("stack is empty \n");
return;
}
else
{
printf("\nthe status of the stack is\n");
for(i=s.top;i>=0;i--)
{
printf("%d\n",s.stk[i]);
}
}
printf("\n");
}

