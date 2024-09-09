#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height;

    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    Node *root;

    int getHeight(Node *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalanceFactor(Node *node)
    {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate values are not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->value)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
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
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *root, int value)
    {
        if (root == nullptr)
            return root;

        if (value < root->value)
            root->left = deleteNode(root->left, value);
        else if (value > root->value)
            root->right = deleteNode(root->right, value);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->value);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node *search(Node *root, int value)
    {
        if (root == nullptr || root->value == value)
            return root;

        if (root->value < value)
            return search(root->right, value);

        return search(root->left, value);
    }

    void printTree(Node *root, string indent, bool last)
    {
        if (root != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "└─";
                indent += "  ";
            }
            else
            {
                cout << "├─";
                indent += "│ ";
            }
            cout << root->value << endl;

            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    bool search(int value)
    {
        return search(root, value) != nullptr;
    }

    void display()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        printTree(root, "", true);
    }
};

int main()
{
    AVLTree avl;
    int choice, value;

    while (true)
    {
        cout << "\nAVL Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            avl.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            avl.remove(value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (avl.search(value))
                cout << "Value found in the tree." << endl;
            else
                cout << "Value not found in the tree." << endl;
            break;
        case 4:
            cout << "AVL Tree Structure:" << endl;
            avl.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
