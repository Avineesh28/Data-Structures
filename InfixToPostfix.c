//To convert an Infix Expression to Postfix
//The preprocessor Directives required
#include <stdio.h>
#include <string.h>
//Global Variables needed
char stack[20];
int top;
//Function to push in the stack
void push(char t)
{
	top++;
	stack[top]=t;
}
//Function to pop from the stack
char pop()
{
	char t=stack[top];
	top--;
	return t;
}
//driver main() funtion
int main()
{
	top=-1;
	char c[50];//Orignal expression
	char f[50];//Converted expression
	int ind;//Indexing for second array
	printf("Enter the Experession(with proper parenthesis)\n");
	scanf("%s",&c);//input
	int n=strlen(c);
	int i;
	for(i=0;i<n;i++)//Character by character processing using Array traversal loop
	{
		if(c[i]==')')	
		{
			f[ind++]=pop();
		}
		else if(c[i]<=90 && c[i]>=65)
			f[ind++]=c[i];
		else if(c[i]=='(')
			continue;
		else
			push(c[i]);
	}
	//display
	printf("%s",f);
	return 1;
}

