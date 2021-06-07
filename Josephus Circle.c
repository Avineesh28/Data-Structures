#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
	int info;
	struct node* next;
};
void setup();
void delNode();
struct node* head = NULL; 
int n=0;
int m=0;
void setup()
{
	struct node* prev;
	int i;
	for(i=1;i<=n;i++)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->info=i;
		if(i==1)
		{
			head=temp;
			prev=temp;
		}
		else
		{
			prev->next=temp;
			prev=temp;
		}
	}
	prev->next=head;
}
void execute()
{
	int e=0;
	int c=1;
	int f=e;
	struct node *temp=head;
	while(e<n-1)
	{
		while(c!=m-1)
		{
			temp=temp->next;
			c++;
		}
		c=1;
		temp->next=temp->next->next;
		temp=temp->next;
		struct node* temp1=head;
		while(f!=n-1)
		{
			temp1=temp1->next;
			f++;
		}
		e++;
		f=e;
	}
	head=temp;
}
void display()
{
	printf("The safe position in the circle is %d",head->info);
}
int main()
{
	printf("Please enter the number of people in the circle (n) and the number of people to be skipped (m)\n");
	scanf("%d\n%d",&n,&m);
	setup();
	execute();
	display();
	return 1;
}
