#include <iostream>
#include <queue>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void InOrder(Node *root)
{

    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{

    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void PreOrder(Node *root)
{

    if (root == NULL)
        return;
    cout << root->data << " ";
    PostOrder(root->left);
    PostOrder(root->right);
}

void level(Node *root)
{

    if (root == nullptr)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {

        Node *node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }
}
int main()
{

    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);

    // inOrder
    cout << "InOder DFS : ";

    InOrder(root);

    cout << endl;
    // post Order

    cout << "Post Order DFS : ";
    PostOrder(root);
    cout << endl;
    // pre Order
    cout << "Pre Order DFS : ";
    PreOrder(root);

    cout << endl;

    cout << "Level Order : ";
    level(root);
    cout << endl;

    return 0;
}