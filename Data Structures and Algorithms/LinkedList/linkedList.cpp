#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node* next;
};

node* insertAtBeginning(node* head, int data)
{
    node* newNode = new node();

    newNode->data = data;

    newNode->next = head;
    
    head = newNode;
    return newNode;
}

node* insertInTheMiddle(node* prev_node, int data)
{
    if(prev_node == NULL)
    {
        cout << "Previous Node Cannot be NULL" << endl;
    }

    node* newNode = new node();

    newNode->data = data;

    newNode->next = prev_node->next;

    prev_node->next = newNode;
    return newNode;
}

node* insertAtEnd(node* head, int data)
{
    node* newNode = new node();

    node* current  = head;

    newNode->data = data;

    if(head == NULL)
    {
        head = newNode;
    }
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = NULL;

    return newNode;
}

node* deleteFromBeginning(node** head)
{
    node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return *head;
}

node* deleteFromMiddle(node** head, int position)
{
    node* current = *head;
    node* prev = *head;

    for(int i=0; i<position; i++)
    {
        if(i==0 && position == 1)
        {
            *head = (*head)->next;
            free(current);
        }
        else{
            if(i == position -1 && current != NULL)
            {
                prev->next = current->next;
                free(current);
            }
            else{
                prev = current;
                if(prev == NULL)
                {
                    break;
                }
                current = current->next;
            }
        }
    }
}

node* deleteFromEnd(node** head)
{
    node* current = *head;
    node* prev = NULL;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    delete current;

    return *head;
}


void printLinkedList(node* head)
{
    while(head !=NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
        node* head = NULL;
        head = insertAtBeginning(head, 4);
        head = insertAtBeginning(head, 2);
        head = insertAtBeginning(head, 1);

        node* secondNode = head->next;
        insertInTheMiddle(secondNode, 3);

        insertAtEnd(head, 5);
        insertAtEnd(head, 6);

        deleteFromBeginning(&head);

        deleteFromMiddle(&head, 3);

        deleteFromEnd(&head);

        printLinkedList(head);

        
}