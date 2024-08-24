#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void levelOrderTraversal(Node* root, int level) {
    if (root == nullptr) {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    int currentLevel = 0;
    bool levelFound = false;

    while (!q.empty()) {
        int size = q.size();

        if (currentLevel == level) {
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                cout << node->data << " ";
            }
            cout << endl;
            levelFound = true;
            break;
        }

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        currentLevel++;
    }

    if (!levelFound) {
        cout << "Invalid" << endl;
    }
}

int main() {
    int data;
    queue<Node*> q;

    cin >> data;
    Node* root = createNode(data);
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

     
        cin >> data;
        if (data != -1) {
            node->left = createNode(data);
            q.push(node->left);
        }
        cin >> data;
        if (data != -1) {
            node->right = createNode(data);
            q.push(node->right);
        }
    }

    int level;
    cin >> level;

    levelOrderTraversal(root, level);

    return 0;
}