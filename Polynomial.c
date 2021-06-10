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
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&t1,&t2);
        struct node * temp=poly1;
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
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&t1,&t2);
        struct node * temp=poly2;
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
	struct node* temp = (struct node*)malloc(sizeof(struct node));
 	temp->next = NULL;
 	result = temp;
 	struct node *first=poly1;
 	struct node *second=poly2;
	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct node*)malloc(sizeof(struct node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct node*)malloc(sizeof(struct node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}	

void subpoly()
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
 	temp->next = NULL;
 	result = temp;
 	struct node *first=poly1;
 	struct node *second=poly2;
	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff - second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct node*)malloc(sizeof(struct node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct node*)malloc(sizeof(struct node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}
int check(struct node* t)
{
    struct node* temp=result;
    while(temp!=NULL)
    {
        if(temp->pow==t->pow)
        {
            temp->coeff+=t->coeff;
            return 1;
        }
        else 
            temp=temp->next;
    }
    return 0;
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
            temp3->pow=temp1->pow+temp2->pow;
            temp3->next=NULL;
            if(check(temp3)==1)
                temp2=temp2->next;
            else
            {
                int flag=0;
                struct node *temp=result;
                if(result==NULL)
                    result=temp3;
                else if(result->next==NULL)
                {
                    if(result->pow>temp3->pow)
                        result->next=temp3;
                    else
                    {
                        temp3->next=result;
                        result=temp3;
                    }
                }
                else
                {
                    while(temp->next!=NULL)
                    {
                        if(temp->next->pow > temp3->pow)
                            temp=temp->next;
                        else
                        {
                            temp3->next=temp->next;
                            temp->next=temp3;
                            flag++;
                            break;
                        }
                    }
                    if(flag==0)
                            temp->next=temp3;
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void divpoly()
{
	//ONLY FOR SINGLE TERMS
	struct node * temp1=poly1;
	struct node * temp2=poly2;
	result=(struct node*)malloc(sizeof(struct node));
	result->coeff=temp1->coeff/temp2->coeff;
	result->pow=temp1->pow-temp2->pow;
	result->next=NULL;
}
void display(struct node* h)
{
    struct node *temp=h;
    int flag=0;
    while(temp!=NULL)
    {
        int t1=temp->coeff;
        int t2=temp->pow;
        char ch='+';
        if(t1<0)
            ch='-';
        t1=abs(t1);
        if(t1!=0)
        {
            if(t2!=0)
            {
                if(flag==0)
                    printf("%d(x^%d)",t1,t2);
                else
                    printf("%c%d(x^%d)",ch,t1,t2);
                flag++;
            }
            else
            {
                if(flag==0 && ch=='+')
                    printf("%d(x^%d)",t1,t2);
                else
                    printf("%c%d",ch,t1);
                flag++;
            }
        }
        else
        {
            if(flag==0 && temp->next==NULL)
                printf("0");
        }
        temp=temp->next;
    }
    printf("\n\n");
}
int main()
{
		printf("Enter the two polynomials in ascending order of powers\n");
		input();
		//print 
		printf("Polynomial 1->\nf(x)= ");
		display(poly1);
		printf("Polynomial 2->\ng(x)= ");
		display(poly2);
		printf("Welcome!\nEnter-\n1\t-\t to perform addition \n2\t-\t to perform Subtraction(A-B)\n3\t-\t to perform multiplication\n4\t-\t to perform division\nOr Any other character to exit\n");
		int choice;
		scanf("%d",&choice);
		int flag=0;
		switch(choice)
			{
				case 1: 
						{
							addpoly();
							printf("Answer->\nH(x)= ");
							display(result);
							break;
						}
				case 2: {
							subpoly();
							printf("Answer->\nH(x)= ");
							display(result);
							break;	
				
						}
				case 3:	{
							multipoly();
							printf("Answer->\nH(x)= ");
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
