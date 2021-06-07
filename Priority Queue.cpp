//Implementation of an Array Priority Queue
#include<stdio.h>
//Function Declerations
void enqueue(int,int,int,int);
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
void enqueue(int t,int a[],int p[], int pp)
{
	rear++;
	a[rear]=t;
	p[rear]=pp;
}
int dequeue(int a[],int p[])
{
	int t;
	int ind=0;
	for(int i=0;i<rear;i++)
	{
		if(p[ind]<p[i])
			ind=i;
	}
	
	t=a[ind];
	for(int j=ind;j<rear;j++)
	{
		a[j]=a[j+1];
		p[j]=p[j+1];
	}
	a[rear]=0;
	p[rear]=0;
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
	printf("Welcome!\nEnter the size of Queue\n");
	scanf("%d",&n);
	int a[n];//Queue Declaration
	int p[n];
	int choice=0;
	//Menu
	printf("\nEnter-\n1\t-\t to enqueue an element in the  Priority Queue\n2\t-\t to dequeue an element from the Priority Queue\n3\t-\t to empty the Priority Queue\n4-\t-\t to display the Priority Queue\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: if(isFull()==false)
					{
						printf("Enter the value\n");
						int t1,t2;
						scanf("%d",&t1);
						printf("Enter the Priority\n");
						scanf("%d",&t2);
						enqueue(t1,a,p,t2);
					}
					else
						printf("Queue Overflow, Please choose a different option\n");
					break;
			case 2:if(isEmpty()==false)
					{
						int t=dequeue(a,p);
						printf("Dequeued Value %d\n",t);
					}
					else
					{
						printf("Queue Underflow, Please choose a different option\n");
						front=0;
						rear=-1;
					}
					break;
			case 3:	MakeEmpty();
					printf("Queue Cleared\n");
					break;
			case 4:	FIFO(a);
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
