#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
};

node* createANode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insert(node* root, int key)
{
    if(root == NULL)
    {
        return createANode(key);
    }

    if(key < root->key)
    {
        root->left = insert(root->left,key);
    }
    else if(key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(node*root)
{
    if(root != NULL){
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
    }
}

int main()
{
    node * root = NULL;

    root = insert(root,50);
    insert(root,40);
    insert(root,30);
    insert(root,20);
    insert(root,10);
    insert(root,0);
    insert(root,60);
    insert(root,70);
    insert(root,80);
    insert(root,90);
    insert(root,100);

    inorder(root);
    return 0;
}