//C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
    char key[20];
    char value[20];
    struct node *left, *right;
};
 // A utility function to create a new BST node
struct node* newNode(char item[20])
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 // A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) 
	{
        inorder(root->left);
        printf("%s : %s\n", root->key,root->value);
        inorder(root->right);
    }
}
 // A utility function to insert a new node with given key in BST 
 // C function to search a given key in a given BST
struct node* search(struct node* root, char key[20])
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcomp(root->key,key)==0)
       return root;
    
    // Key is greater than root's key
    if (strcomp(root->key,key)<0)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
struct node* insert(struct node* node,char key[20],char value[20])
{
    // If the tree is empty, return a new node 
    if (node == NULL)
        return newNode(key);
    // Otherwise, recur down the tree 
    if (strcomp(root->key,key)<0)
        node->left = insert(node->left, key, value);
    else if (strcomp(root->key,key)>0)
        node->right = insert(node->right, key, value);
 	//return the (unchanged) node pointer
	return node;
}
// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // print inoder traversal of the BST
    inorder(root);
 
    return 0;
}
