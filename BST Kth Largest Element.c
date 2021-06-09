// C program to find the Kth maximum element in a binary search tree

#include
#include

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *newNode(int data)
{
struct node *temp = (struct node *) malloc(sizeof(struct node));
temp -> data = data;
temp -> left = NULL;
temp -> right = NULL;
return temp;
};

// Function to find k’th maximum element
void kth_largest(node *root, int k, int &c)
{
// Base cases
if (root == NULL || c >= k)
return;

// largest element is visited first
kth_largest(root->right, k, c);

c++; // Increment count of visited nodes

// If c == k, then this is the k’th largest
if (c == k)
{
printf(“\nK’th largest element is %d\n”,root->data);
return;
}

// Recursion for left subtree
kth_largest(root->left, k, c);
}

// Function to find k’th maximum element
void kth_largest_element(node *root, int k)
{
int c = 0;

// c is passed by reference
kth_largest(root, k, c);
}

void insert_node(struct node *root, int n1, int n2, char lr)
{
if(root == NULL)
return;
if(root -> data == n1)
{
switch(lr)
{
case ‘l’ :root -> left = newNode(n2);
break;
case ‘r’ : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root -> left, n1, n2, lr);
insert_node(root -> right, n1, n2, lr);
}
}

void inorder(struct node *root)
{
if(root == NULL)
return;
inorder(root -> left);
printf(“%d “, root -> data);
inorder(root -> right);
}

int main()
{
struct node *root = NULL;
int n;
printf(“\nEnter the number of edges : “);
scanf(“%d”,&n);
printf(“\nInput the tree : \n”);
while(n–)
{
char lr;
int n1,n2;
scanf(“%d”,&n1);
scanf(“%d”,&n2);
scanf(” %c”,&lr);
if(root == NULL)
{
root = newNode(n1);
switch(lr)
{
case ‘l’ :root -> left = newNode(n2);
break;
case ‘r’ : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root,n1,n2,lr);
}
}
printf(“Inorder Tree Traversal : “);
inorder(root);
printf(“\n”);
int c = 0;
int k;
printf(“\nEnter the value of k : “);
scanf(“%d”,&k);
kth_largest_element(root, k);
return 0;
}