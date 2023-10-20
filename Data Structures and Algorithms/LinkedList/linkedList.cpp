#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node* next;
};

node* createANode(int data)
{
    node * newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* insertAtEnd(node* root, int data)
{
    node* current = (node*)malloc(sizeof(node));
    current = root;
    if(root == NULL)
    {
        return createANode(data);
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode = createANode(data);
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return root;

}

void printLinkedList(node* root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

int main(){
    node* root = NULL;

    root = insertAtEnd(root,1);
    root = insertAtEnd(root,2);
    root = insertAtEnd(root,3);
    root = insertAtEnd(root,4);
    root = insertAtEnd(root,5);

    printLinkedList(root);
}