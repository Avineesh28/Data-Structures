//Implementation of an Array Stack
#include<stdio.h>
//Function Declerations
void push(int,int[]);
int  pop(int[]);
void LIFO(int[]);
void MakeEmpty();
int isEmpty();
int  isFull();
//Global Variables
int top=-1;
int n;
//Functions
void push(int t,int a[])
{
	top++;
	a[top]=t;
}
int pop(int a[])
{
	int t=a[top];
	top--;
	return t;
}
void LIFO(int a[])
{
	printf("The Stack-\n");
	int i;
	for(i=top;i>=0;i--)
		printf("%d\t",a[i]);
	printf("\n");
}
void MakeEmpty()
{
	top=-1;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;	
}
int isFull()
{
	if(top==n-1)
		return 1;
	else
		return 0;
}
//Driver Function
int main()
{
	printf("Welcome!\nEnter the expression\n");
	scanf("%d",&n);
	int a[n];//Stack Declaration
	int choice=0;
	//Menu
	printf("\nEnter-\n1\t-\t to push an element in the Stack\n2\t-\t to pop an element from the Stack\n3\t-\t to empty the Stack\n4-\t-\t to display the Stack\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: if(isFull()==0)
					{
						printf("Enter the value\n");
						int t;
						scanf("%d",&t);
						push(t,a);
					}
					else
						printf("Stack Overflow, Please choose a different option\n");
					break;
			case 2:if(isEmpty()==0)
					{
						int t=pop(a);
						printf("Popped Value %d\n",t);
					}
					else
						printf("Stack Underflow, Please choose a different option\n");
					break;
			case 3:	MakeEmpty();
					printf("Stack Cleared\n");
					break;
			case 4:	LIFO(a);
					break;
			default:printf("Thank You!\n");
					flag=1;
		}
		if(flag==0)
		{
			printf("Enter Choice\n");
			scanf("%d",&choice);
		}
	}
	return 1;
}

