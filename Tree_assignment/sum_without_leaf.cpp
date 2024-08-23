#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
           this->data = data;
           this->left = NULL;
           this->right= NULL;
           
        }
        
   
};


Node* buildTree() {
    int val;
    cin >> val;
    
    if (val == -1) {

        return nullptr;

    }
    
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cin >> val;
        if (val != -1) {
            curr->left = new Node(val);
            q.push(curr->left);
        }

        cin >> val;
        if (val != -1) {
            curr->right = new Node(val);
            q.push(curr->right);
        }
    }

    return root;
}


int sum(Node* root) {
    if (root == nullptr) return 0;

    int sum = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left != nullptr || curr->right != nullptr) {
            sum += curr->data;
        }

        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }

    return sum;
}

int main() {
    
    Node* root = buildTree();
   
    int result = sum(root);

    cout << result << endl;

    return 0;
}
