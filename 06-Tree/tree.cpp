#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int main() {
    // Initialize and allocate memory for tree nodes
    Node* firstNode = new Node(2);
    Node* secondNode = new Node(3);
    Node* thirdNode = new Node(4);
    Node* fourNode = new Node(5);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourNode;

    // Example output
    cout << "Root Node: " << firstNode->data << endl;
    cout << "Left Child of Root: " << firstNode->left->data << endl;
    cout << "Right Child of Root: " << firstNode->right->data << endl;
    cout << "Left Child of Second Node: " << secondNode->left->data << endl;

    return 0;
}
