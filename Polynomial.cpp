#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
struct node
{
	int coeff;
	int pow;	
	struct node *next;
};
struct node *poly1;
struct node *poly2;
struct node *result;
void input()
{
	//Polynomial one
	printf("Enter the number of terms in Polynomial 1\n");
	int n;
	scanf("%d",&n);
	printf("Enter the Polynomial 1 as f(x)=0, by entering the coefficients and powers of each term seperated by a space eg- 2 2 => 2(x^2)\n");
	int t1=0;
	int t2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&t1,&t2);
		struct node *temp=poly1;
		if(temp==NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->coeff=t1;
			temp->pow=t2;
			temp->next=NULL;
			poly1=temp;
		}
		else
		{
			struct node *temp1=(struct node*)malloc(sizeof(struct node));
			temp1->coeff=t1;
			temp1->pow=t2;
			temp1->next=NULL;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=temp1;
		}
	}
	printf("Enter the number of terms in Polynomial 2\n");
	scanf("%d",&n);
	printf("Enter the Polynomial 2 as f(x)=0, by entering the coefficients and powers of each term seperated by a space eg- 2 2 => 2(x^2)\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&t1,&t2);
		struct node *temp=poly2;
		if(temp==NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->coeff=t1;
			temp->pow=t2;
			temp->next=NULL;
			poly2=temp;
		}
		else
		{
			struct node *temp1=(struct node*)malloc(sizeof(struct node));
			temp1->coeff=t1;
			temp1->pow=t2;
			temp1->next=NULL;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=temp1;
		}
	}
}
void addpoly()
{
	struct node *t1=poly1;
	struct node *t2=poly2;
	while(t1!=NULL && t2!=NULL)
	{
		struct node *t3=(struct node*)malloc(sizeof(struct node));
		if(t1->pow==t2->pow)
		{
			t3->pow=t1->pow;
			t3->coeff=t1->coeff+t2->coeff;
			struct node *temp=result;
			if(temp==NULL)
			{
				temp=t3;
				t3->next=NULL;
				result=t3;
			}
			else
			{
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=t3;
			}
		}
		else
		{
			struct node *temp=result;
			while(temp->next!=NULL)
				temp=temp->next;
			struct node *temp1=(struct node*)malloc(sizeof(struct node));
			struct node *temp2=(struct node*)malloc(sizeof(struct node));
			if(t3->pow>t2->pow)
			{
				temp1->coeff=t3->coeff;
				temp1->pow=t3->pow;
				temp2->pow=t2->pow;
				temp2->coeff=t2->coeff;
			}
			else
			{
				temp2->coeff=t3->coeff;
				temp2->pow=t3->pow;
				temp1->pow=t2->pow;
				temp1->coeff=t2->coeff;
			}
			temp->next=temp1;
			temp=temp->next;
			temp->next=temp2;
			temp=temp->next;
			temp->next=NULL;
		}
		t1=t1->next;
		t2=t2->next;
	}
}
void subpoly()
{
	struct node *t1=poly1;
	struct node *t2=poly2;
	while(t1!=NULL && t2!=NULL)
	{
		struct node *t3=(struct node*)malloc(sizeof(struct node));
		if(t1->pow==t2->pow)
		{
			t3->pow=t1->pow;
			t3->coeff=t1->coeff-t2->coeff;
			struct node *temp=result;
			if(temp==NULL)
			{
				temp=t3;
				t3->next=NULL;
				result=t3;
			}
			else
			{
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=t3;
			}
		}
		else
		{
			struct node *temp=result;
			while(temp->next!=NULL)
				temp=temp->next;
			struct node *temp1=(struct node*)malloc(sizeof(struct node));
			struct node *temp2=(struct node*)malloc(sizeof(struct node));
	
			temp1->coeff=t3->coeff;
			temp1->pow=t3->pow;
			temp2->pow=t2->pow;
			temp2->coeff=-t2->coeff;
				
			temp->next=temp1;
			temp=temp->next;
			temp->next=temp2;
			temp=temp->next;
			temp->next=NULL;
		}
		t1=t1->next;
		t2=t2->next;
	}
}
bool check(struct node* t)
{
	struct node* temp=result;
	while(temp!=NULL)
	{
		if(temp->pow==t->pow)
		{
			temp->coeff+=t->coeff;
			return true;
		}
		else 
			temp=temp->next;
	}
	return false;	
}
void multipoly()
{
	struct node *temp1=poly1;
	while(temp1!=NULL)
	{
		struct node *temp2=poly2;
		while(temp2!=NULL)
		{
			struct node *temp3=(struct node*)(malloc(sizeof(struct node)));
			temp3->coeff=temp1->coeff*temp2->coeff;
			temp3->pow=temp1->pow+temp2->coeff;
			temp3->next=NULL;
			if(check(temp3))
				temp2=temp2->next;
			else
			{
				int flag=0;
				struct node* temp=result;
				while(temp->next!=NULL)
				{
					if(temp->next->pow > temp3->pow)	
						continue;
					else
					{
							temp3->next=temp->next;
							temp->next=temp3;
							flag++;
							break;
						}	
						temp=temp->next;
					}
					if(flag==0)
						temp->next=temp3;
					temp2=temp2->next;
				}	
			}
			temp1=temp1->next;
		}
		
	}
	void divpoly()
	{
			
	}
	void display(struct node* h)
	{
		printf("\n\n");
		printf("Answer->\nH(x)= ");
		struct node *temp=h;
		int flag=0;
		while(temp!=NULL)
		{
			int t1=temp->coeff;
			int t2=temp->pow;
			char ch='+';
			if(t1<0)
				ch='-';
			abs(t2);
			if(t1!=0)
			{
				
				if(temp==h)
					printf("%d(x^%d)",t1,t2);
				else
					printf("%c%d(x^%d)",ch,t1,t2);
				flag++;
			
			}
			else
			{
				if(flag==0 && temp->next==NULL)
					printf("0");
			}
			temp=temp->next;			
		}	
	}
	int main()
	{
		printf("Enter the two polynomials\n");
		input();
		printf("Welcome!\nEnter-\n1\t-\t to perform addition \n2\t-\t to perform Subtraction(A-B)\n3\t-\t to perform multiplication\n4\t-\t to perform division\nOr Any other character to exit\n");
		int choice;
		scanf("%d",&choice);
		int flag=0;
		switch(choice)
			{
				case 1: 
						{
							addpoly();
							display(result);
							break;
						}
				case 2: {
							subpoly();
							display(result);
							break;	
				
						}
				case 3:	{
							multipoly();
							display(result);
							break;
						}	
				case 4: {
							divpoly();
							display(result);
							break;
						}
		       default:printf("Thank You!\n");
	
			}
		return 1;
	}
