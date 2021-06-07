#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
	int info;
	struct node* next;
};
int c=0;
void addNodeB();
void addNodeP(int);
void addNodeE();
void delNodeB();
void delNodeP(int);
void delNodeE();
void display();
struct node* head = NULL; 
void addNodeB()
{
	int t;
	printf("Enter the value\n");
	scanf("%d",&t);
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->info=t;
	if(head!=NULL)
	{
		struct node* temp1=head;
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
		temp->next=head;
		head=temp;
	}
	else
	{
		temp->next=temp;
		head=temp;
	}
	c++;
}
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
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
		temp->next=head;	
	} 
	c++;	
}
void addNodeP(int p)
{
	int t;
	printf("Enter the value\n");
	scanf("%d",&t);
	int c=1;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->info=t;
	if(head != NULL)
	{
		struct node* temp1=head;
		while(c<p-1)
		{
			temp1=temp1->next;
			c++;
		}
		c--;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	else
		temp->next=temp;	
	c++;
}
void delNodeB()
{
	struct node *temp=head;
	if(head!=NULL)
	{
		while(temp->next!=head)
			temp=temp->next;
		temp->next=head->next;
		head=head->next;
	}
	else
		printf("List Empty\n");
	c--;
				
}
void delNodeE()
{
	if(head!=NULL)
	{
		struct node *temp1=head;	
		while(temp1->next->next!=head)
			temp1=temp1->next;
		temp1->next=head;
	}
	else if(c==1)
	{
		head=head->next;
	}
	else
		printf("List Empty\n");
		c--;
}
void delNodeP(int p)
{
	int c=1;
	struct node *temp=head;
	while(c!=p-1)
	{
		temp=temp->next;
		c++;
	}
	c=1;
	temp->next=temp->next->next;
	c--;
}
void display()
{
	printf("Circular Linked List:\n\t==>");
	struct node *temp=head;
	while(temp->next!=head)
	{
		printf("%d-->",temp->info);
		temp=temp->next;
	}
	printf("%d==>\n",temp->info);
}
int main()
{
	int choice;
	printf("Welcome!\nEnter-\n1\t-\t to Add a Node in the beggining\n2\t-\t to Add a Node in the end\n3\t-\t to Add a Node at a specific position\n4\t-\t to Delete a Node from the beggining \n5\t-\t to Delete a Node from the end \n6-\t-\t to Delete a Node at a specific position\n7-\t-\t to display the list\nOr Any character to exit\n");
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
			case 3: 
					{
						int p;
						printf("Enter the desired positon\n");
						display();
						scanf("%d",&p);
						if(p>c)
							printf("Invalid position\n");
						else	
						{
							if(p==1)
								addNodeB();
							else if(p==c)
								addNodeE();
							else
								addNodeP(p);
						}
						break;
					}
			case 4:	delNodeB();
					break;
			case 5: delNodeE();
					break;
			case 6: 
					{
						int p;
						printf("Enter the desired positon\n");
						display();
						scanf("%d",&p);
						if(p>c+1)
							printf("Invalid position\n");
						else	
						{
							if(p==1)
								delNodeB();
							else if(p==c+1)
								delNodeE();
							else
								delNodeP(p);
						}
						break;
					}
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
