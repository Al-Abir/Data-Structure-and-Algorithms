#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *tree(vector<int> &level) {
    if (level.empty() || level[0] == -1)
        return NULL;

    Node *root = new Node(level[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (i < level.size()) {
        Node *node = q.front();
        q.pop();

        if (i < level.size() && level[i] != -1) {
            node->left = new Node(level[i]);
            q.push(node->left);
        }
        i++;

        if (i < level.size() && level[i] != -1) {
            node->right = new Node(level[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

int countNodes(Node *root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int calculateDepth(Node *root) {
    if (!root) return 0;
    return 1 + calculateDepth(root->left);
}

bool isPerfectCheck(Node *root) {
    if (!root) return true;

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);


    if (leftDepth != rightDepth) return false;


    int totalNodes = countNodes(root);
    return totalNodes == (1 << (leftDepth + 1)) - 1;  
}

int main() {
    vector<int> level;
    int value;
    while (cin >> value) {
        level.push_back(value);
    }

    Node *root = tree(level);

    bool result = isPerfectCheck(root);
    cout << (result ? "YES" : "NO") << endl;

    return 0;
}
