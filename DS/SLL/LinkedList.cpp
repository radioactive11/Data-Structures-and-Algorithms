#include <iostream>

using namespace std;

 class Node
 {
     public:
     int data;
     Node* next;
 };

Node* head = nullptr;


void insert_front(int inp)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = inp;
    newNode -> next = head;
    head = newNode;
}

void insert_end(int inp)
{
    Node* temp = head;
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    while(temp -> next != nullptr)
        temp = temp -> next;

    newNode -> data = inp;
    newNode -> next = nullptr;
    temp -> next = newNode;
}

void insert_at_n(int inp, int n)
{
    Node* temp = head;
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = inp;

    for(int i=0; i<n; i++)
        if(temp != nullptr)
            temp = temp -> next;
    newNode -> next = temp -> next;
    temp ->next = newNode;
}

void display()
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp = head;
    while(true)
    {
        if(temp == nullptr)
        {
            cout << "null";
            break;
        }
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
}

int main()
{
    insert_front(2);
    insert_front(3);
    insert_front(5);
    insert_front(6);
    insert_end(1);
    insert_at_n(10, 1);
    display();
}
