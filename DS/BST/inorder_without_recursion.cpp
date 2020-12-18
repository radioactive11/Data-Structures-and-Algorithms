#include <iostream>
#include <stack>

using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;

    public:
    Node();
    Node(int value);
    Node* insert(Node* root, int data);
    void inorder(Node* root);
};

Node::Node()
{
    data = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

Node* Node::insert(Node* root, int value)
{
    if(!root)
    {
        return new Node(value);
    }

    else if(value > root -> data)
    {
        root -> right = insert(root -> right, value);
    }

    else
    {
        root -> left = insert(root -> left, value);
    }
    
    return root;
}

void Node::inorder(Node* root)
{
    cout << "Without recursion: \n";
    Node* curr = root;
    stack <Node*> s;

    while(curr != nullptr || s.empty() == false)
    {
        while(curr != nullptr)
        {
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top();
        s.pop();

        cout << curr -> data << endl;

        curr = curr -> right;
    }
}

int main()
{
    Node bst, *root=nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 30);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 10);
    root = bst.insert(root, 90);
    root = bst.insert(root, 20);
    bst.inorder(root);
    return 0;
}