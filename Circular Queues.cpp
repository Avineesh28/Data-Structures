//Implementation of an Array Circular Queue
#include<stdio.h>
//Function Declerations
void enqueue(int,int);
int  dequeue(int);
void FIFO(int);
void MakeEmpty(int);
bool isEmpty();
bool isFull();
//Global Variables
int front=0;
int rear=-1;
int n;
//Functions
void enqueue(int t,int a[])
{
	if(rear==n-1)
		rear=0;
	else
		rear++;
	a[rear]=t;
}
int dequeue(int a[])
{
	int t=a[front];
	if (front==rear)
	{
		front=0;
		rear=-1;
	}
	else if(front==n-1)
		front=0;
	else
		front++;
	return t;
}
void FIFO(int a[])
{
	printf("The Queue-\n");
	if(front<rear)
	{
		for(int i=front;i<=rear;i++)
		printf("%d\t",a[i]);
		printf("\n");
	}
	else if(front==rear)
		printf("%d\n",a[front]);
	else if(front==0 && rear==-1)
		printf("Circular Queue Empty\n");
	else
	{
		for(int i=front;i<n;i++)
			printf("%d\t",a[i]);
		for(int i=0;i<=rear;i++)
			printf("%d\t",a[i]);
		printf("\n");
	}
}
void MakeEmpty()
{
	front=0;
	rear=-1;
}
bool isEmpty()
{
	if( front==0 && rear==-1)
		return true;
	else
		return false;	
}
bool isFull()
{
	if(rear==front-1 && (rear!=-1 && front!=0) || (rear==n-1 && front==0))
		return true;
	else
		return false;
}
//Driver Function
int main()
{
	printf("Welcome!\nEnter the size of Circular Queue\n");
	scanf("%d",&n);
	int a[n];//Circular Queue Declaration
	int choice=0;
	//Menu
	printf("\nEnter-\n1\t-\t to enqueue an element in the Circular Queue\n2\t-\t to dequeue an element from the Circular Queue\n3\t-\t to empty the Circular Queue\n4-\t-\t to display the Circular Queue\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: if(isFull()==false)
					{
						printf("Enter the value\n");
						int t;
						scanf("%d",&t);
						enqueue(t,a);
					}
					else
						printf("Circular Queue Overflow, Please choose a different option\n");
					break;
			case 2:if(isEmpty()==false)
					{
						int t=dequeue(a);
						printf("Dequeued Value %d\n",t);
					}
					else
						printf("Circular Queue Underflow, Please choose a different option\n");
					break;
			case 3:	MakeEmpty();
					printf("Circular Queue Cleared\n");
					break;
			case 4:	FIFO(a);
					break;
			case 5: printf("%d\t%d\n",front,rear);
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
