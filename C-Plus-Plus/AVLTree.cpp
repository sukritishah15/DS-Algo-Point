#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height;
};

// Height of Tree
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node *newNode(int value)
{
    Node *node = new Node();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

Node *insert(Node *node, int value)
{
    /* 1. Perform the normal BST rotation */
    if (node == NULL)
        return (newNode(value));

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Equal values not allowed
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // then there are 4 cases

    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    if (balance > 1 && value > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int value)
{

    if (root == NULL)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);

    else if (value > root->value)
        root->right = deleteNode(root->right, value);

    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               
                *root = *temp;
                             
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);

            root->value = temp->value;

            root->right = deleteNode(root->right,
                                     temp->value);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//Preorder Traversal of AVL TREE
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int choice = 1;
    int node_value;
    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout<<"Enter your choice"<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value of Node ";
            cin >> node_value;
            root = insert(root, node_value);
            cout << endl;
            break;
        case 2:
            cout << "Enter value of Node to be deleted ";
            cin >> node_value;
            root = deleteNode(root, node_value);
            cout << endl;
            break;
        case 3:
            cout << "Preorder traversal of the constructed AVL tree is \n";
            preOrder(root);
            cout << endl;
            break;

        default:
            choice=4;
            break;
        }
    } while (choice != 4);

    return 0;
}


/*

    AVL, named after inventors Adelson-Velsky and Landis.
    Is a binary tree that​ self-balances by keeping a check on the balance factor of every node.

    Sample Input Output -

    Insert - 10 20 30 40 50 25
    Output:
    Preorder Traversal after insertion -
    30 20 10 25 40 50 

    Delete - 10
    Preorder Traversal after deletion -
    30 20 25 40 50  

    Time Complexity -
        Insertion : O(Log n)
        Deltetion : O(Log n)
        
    Space Complexity: O(n)

*/