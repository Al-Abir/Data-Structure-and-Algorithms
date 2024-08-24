#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left= nullptr;
        this->right = nullptr;
    }
};


Node* input_tree() {
    int val;
    cin >> val;
    Node* root = (val == -1) ? NULL : new Node(val);
    if (!root) return NULL;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l == -1)
            p->left = NULL;
        else {
            p->left = new Node(l);
            q.push(p->left);
        }

        if (r == -1)
            p->right = NULL;
        else {
            p->right = new Node(r);
            q.push(p->right);
        }
    }

    return root;
}


void collectLeafNodes(Node* root, vector<int>& leafNodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        leafNodes.push_back(root->val);
    }

    if (root->left) collectLeafNodes(root->left, leafNodes);
    if (root->right) collectLeafNodes(root->right, leafNodes);
}

int main() {
    Node* root = input_tree();
    vector<int> leafNodes;
    collectLeafNodes(root, leafNodes);
    sort(leafNodes.begin(), leafNodes.end(), greater<int>());

    for (int val : leafNodes) {
        cout << val << " ";
    }

    return 0;
}
