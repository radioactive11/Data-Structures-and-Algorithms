#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == nullptr)
    {
        root = createNode(data);
    }

    else if(data <= root -> data)
    {
        root -> left = insert(root -> left, data);
    }
    
    else
    {
        root -> right = insert(root -> right, data);
    }

    return root;
}

bool search(Node* root, int data)
{
    if(root == nullptr)
        return false;

    else if(root -> data == data)
        return true;

    else if(data <= root -> data)
        return search(root -> left, data);

    else
        return search(root -> right, data);
}

void inorder(Node* root)
{
    if(root != nullptr)
    {
        inorder(root -> left);
        cout << root -> data << endl;
        inorder(root -> right);
    }
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 11);
    root = insert(root, 18);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 9);

    if(search(root, 22) == true)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    root = insert(root, 100);
    root = insert(root, 12);

    inorder(root);

}