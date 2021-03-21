#include <iostream>

using namespace std;

class bst
{
private:
    bst * right;
    bst * left;
    int data;
public:
    bst();
    bst(int data);
    bst* insert_node(bst* root, int value);
    void inorder_traversal(bst* root);
    void preorder_traversal(bst* root);
    bool search_tree(bst* root, int value);
    bst* min_tree(bst* root);
    ~bst();
};

bst::bst()
{
    cout << "Afforestation\n";
}

bst::bst(int data)
{
    this->right = nullptr;
    this->left = nullptr;
    this->data = data;
}

void bst::inorder_traversal(bst* root)
{
    if(root == nullptr)
        return;
    
    else
    {
        inorder_traversal(root->left);
        cout << root->data << "\n";
        inorder_traversal(root->right);
    }
}

bst* bst::insert_node(bst* root, int value)
{
    
    if (root == nullptr)
    {
        return new bst(value);
    }
    
    if(value < root->data)
    {
        root->left = insert_node(root->left, value);
    }

    else
    {
        root->right = insert_node(root->right, value);
    }

    return root;
}

bool bst::search_tree(bst* root, int value)
{
    while (root != nullptr)
    {
        if(value > root->data)
        {
            root = root->right;
        }
        else if(value < root->data)
        {
            root = root->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bst* bst::min_tree(bst* root)
{
    while(root->left != nullptr)
    {
        root = root->left;
    }
    cout << "Minimum value is: " << root->data << "\n";
    return root;
}

bst::~bst()
{
    cout << "Deforestation\n";
}


int main(int argc, char const *argv[])
{
    /* code */
    bst B;
    bst * root = nullptr;
    root = B.insert_node(root, 30);
    root = B.insert_node(root, 20);
    root = B.insert_node(root, 40);
    root = B.insert_node(root, 10);
    root = B.insert_node(root, 80);
    root = B.insert_node(root, 70);
    B.inorder_traversal(root);
    B.min_tree(root);
    if(B.search_tree(root, 50))
        cout << "Value found\n";
    
    else
        cout << "Value not found\n";
    
    return 0;
}
