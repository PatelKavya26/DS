#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBeg(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertEnd(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after a given node
void insertAfter(int given, int value)
{
    Node *temp = head;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Node not found." << endl;
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}

// Display
void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
   insertBeg(5);
   insertEnd(10);
   display();  
   insertBeg(3);
   insertEnd(20);
   display();  
   insertAfter(5, 15);
   display();   

    return 0;
}