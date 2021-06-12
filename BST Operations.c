#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
int c=0;
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key==key)
        return root;
    // Key is greater than root's key
    else if (root->key>key)
        return search(root->right, key);
 	else// Key is smaller than root's key
        return search(root->left, key);
}
// A utility function to insert a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
/* Given a non-empty binary search tree, return the node with minimum key value found in
   that tree. Note that the entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
//Given a binary search tree and a key, this function deletes the key and returns the new root 
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
void min_max(struct node* node)
{
		struct node* min=node;
		struct node* max=node;
		while(min->left!=NULL)
			min=min->left;
		while(max->right!=NULL)
			max=max->right;
		printf("\nThe minimum value present in the given BST is: %d ",min->key);
		printf("\nThe maximum value present in the given BST is: %d ",max->key);	
}
void kth_min(struct node* root, int k)
{
	if(root==NULL)
		return;
	else
	{
		kth_min(root->left,k);
		c++;
		if(c==k)
			printf("\nThe Kth minimum value in the BST for k=%d is: %d",k,root->key);
		kth_min(root->right,k);
	}
}
// Driver Code
int main()
{
    /* Let us create a default BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the default Binary Search Tree \n");
    inorder(root);
 	printf("\nWelcome!\nPlease Enter\n1 - To insert element in the BST\n2 - To delete element in the BST\n3 - To determine the Minimum and maximum element in the BST\n4 - To determine the kth minimum element\nOr any other number to exit\n");
	int choice;
 	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: if(root!=NULL)
					{
						printf("Enter the value to be inserted\n");
						int t;
						scanf("%d",&t);
						struct node* temp=search(root,t);
						if(temp==NULL)						
						{
							insert(root,t);
							printf("\nInserted\n");
							printf("\nInorder traversal of the BST \n");
							inorder(root);
							printf("\n");
						}
						else
						printf("Value already present\n");
					}
					break;
			case 2: if(root!=NULL)
					{
						printf("Enter the value to be deleted\n");
						int t;
						scanf("%d",&t);
						struct node* temp=search(root,t);
						deleteNode(root,t);
						printf("\nDeleted\n");
						printf("\nInorder traversal of the BST \n");
						inorder(root);
						printf("\n");
					}
					break;
			case 3: min_max(root);
					printf("\n");
					break;
			case 4:	printf("Enter the value of k\n");
					int k;
					scanf("%d",&k);
					kth_min(root,k);
					printf("\n");
					break;
			default:printf("\nThank You!\n");
					flag=1;
		}
		if(flag==0)
		{
			printf("\nEnter Choice\n");
			scanf("%d",&choice);
		}
	} 	
    return 0;
}
