//Implementation of an Array Dequeue
#include<stdio.h>
//Function Declerations
void enqueueR(int,int);
void enqueueF(int,int);
int  dequeueF(int);
int  dequeueR(int);
void FIFO(int);
void MakeEmpty(int);
bool isEmpty();
bool isFull();
//Global Variables
int front=0;
int rear=-1;
int n;
//Functions
void enqueueR(int t,int a[])
{
	rear++;
	a[rear]=t;
}
void enqueueF(int t,int a[])
{
	front--;
	a[front]=t;
}
int dequeueF(int a[])
{
	int t=a[front];
	front++;
	return t;
}
int dequeueR(int a[])
{
	int t=a[rear];
	rear--;
	return t;
}
void FIFO(int a[])
{
	printf("The Queue-\n");
	for(int i=front;i<=rear;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
void MakeEmpty()
{
	front=0;
	rear=-1;
}
bool isEmpty()
{
	if(rear==-1 || front>rear)
		return true;
	else
		return false;	
}
bool isFull()
{
	if(rear==n-1)
		return true;
	else
		return false;
}
//Driver Function
int main()
{
	printf("Welcome!\nEnter the size of DEQueue\n");
	scanf("%d",&n);
	int a[n];//DEQueue Declaration
	int choice=0;
	//Menu
	printf("\nEnter-\n1\t-\t to enqueue an element in the beggining of the Queue\n2\t-\t to enqueue an element in the end of the Queue\n3\t-\t to dequeue an element from the beggining of the Queue\n4\t-\t to dequeue an element from the end of the Queue\n5\t-\t to empty the Queue\n6-\t-\t to display the Queue\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1:if(front>0 && front<=rear)
					{
						printf("Enter the value\n");
						int t;
						scanf("%d",&t);
						enqueueF(t,a);
					}
					else
						printf("Queue Overflow, Please choose a different option\n");
					break;
			case 2: if(isFull()==false)
					{
						printf("Enter the value\n");
						int t;
						scanf("%d",&t);
						enqueueR(t,a);
					}
					else
						printf("Queue Overflow, Please choose a different option\n");
					break;
			case 3:if(rear>=front)
					{
						int t=dequeueF(a);
						printf("Dequeued Value %d\n",t);
					}
					else
					{
						printf("Queue Underflow, Please choose a different option\n");
						front=0;
						rear=-1;
					}
					break;
			case 4:if(isEmpty()==false)
					{
						int t=dequeueR(a);
						printf("Dequeued Value %d\n",t);
					}
					else
					{
						printf("Queue Underflow, Please choose a different option\n");
						front=0;
						rear=-1;
					}
					break;
			case 5:	MakeEmpty();
					printf("Queue Cleared\n");
					break;
			case 6:	FIFO(a);
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
