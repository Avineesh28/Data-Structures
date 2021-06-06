//Implementation of a Linked List
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
	int info;
	struct node* next;
};
void addNodeB();
void addNodeE();
void addNodeP();
void delNodeB();
void delNodeE();
void delNodeP();
struct node* head = NULL; 
int c=0;
//To add a Node at the beggining of the list
void addNodeB()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value\n");
	int v;
	scanf("%d",&v);
	temp->info=v;
	temp->next=head;
	head=temp;
	c++;
}
//To add a Node at the end of the List
void addNodeE()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value\n");
	int v;
	scanf("%d",&v);
	temp->info=v;
	if(c==0)
	{ 
		temp->next=head;
		head=temp;
	}
	else
	{
		struct node *temp1=head;	
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp->next=NULL;	
	} 
	c++;	
}
//To add a Node at a particular position in the List
void addNodeP()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the position\n");
	int p,v;
	scanf("%d",&p);
	printf("Enter the value\n");
	scanf("%d",&v);
	temp->info=v;
	if(c==0)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		struct node *temp1=head;	
		int count=1;
		while(count<p-1)
		{
			temp1=temp1->next;
			count++;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	} 
	c++;
}
//To Delete a Node from the beggining of the List
void delNodeB()
{
	if(head!=NULL)
		head=head->next;
	else
		printf("List Empty\n");
	c--;
				
}
//To delete a Node from the end of a List
void delNodeE()
{
	if(head!=NULL)
	{
		struct node *temp1=head;	
		while(temp1->next->next!=NULL)
			temp1=temp1->next;
		temp1->next=NULL;
	}
	else if(c==1)
	{
		head=head->next;
	}
	else
		printf("List Empty\n");
		c--;
}
//To delete a Node from a specific position in the list
void delNodeP()
{
	if(head!=NULL)
	{
		printf("Enter the position\n");
		int p;
		scanf("%d",&p);
		struct node *temp=head;	
		int count=1;
		while(count<p-1)
		{
			temp=temp->next;
			count++;
		}
		temp->next=temp->next->next;
	}
	else
		printf("List Empty\n");
	c--;
}
void display()
{
	struct node *temp=head;	
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int choice;
	printf("Welcome!\nEnter-\n1\t-\t to Add a Node in the beggining \n2\t-\t to Add a Node in the end\n3\t-\t to Add a Node at a specific position\n4\t-\t to Delete a Node from the beggining \n5\t-\t to Delete a Node from the end \n6-\t-\t to Delete a Node at a specific position\n7-\t-\t to display the list\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: addNodeB();
					break;
			case 2: addNodeE();
					break;	
			case 3: addNodeP();
					break;
			case 4:	delNodeB();
					break;
			case 5: delNodeE();
					break;
			case 6: delNodeP();
					break;
			case 7: display();
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
