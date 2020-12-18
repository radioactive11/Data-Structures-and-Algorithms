#ifndef SLL
#define SLL


struct Node
{
    int data;
    Node* next;
};

// insert data at start

Node* insert_at_start(Node* head, int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
    return head;
}

//insert data at n

void insert_at_n(Node* head, int data, int n)
{
    Node* temp = head;
    for(int i=0; i<n; i++)
        temp = temp -> next;


    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = temp -> next;
    temp -> next = newNode;

}

// search for data in ll

Node* search(Node* head, int data)
{
    Node* temp = head;
    while(temp)
    {
        if(temp -> data == data)
        {
            std::cout << "element found";
            return temp;
        }
        temp = temp -> next;
    }
    return nullptr;
}

void delete(Node* head, int data)
{
    // Node* temp = head;
    Node* ptr = search(head, data);

    if(ptr == nullptr){return;}

    
}

// print the linked list

void print(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        std::cout << temp -> data << std::endl;
        temp = temp -> next;
    }
}

#endif