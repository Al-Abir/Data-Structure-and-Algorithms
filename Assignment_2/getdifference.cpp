#include <iostream>
#include <limits.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printDifference(Node *&head) {
    int min = INT_MAX;
    int max = INT_MIN;
    Node *temp = head;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    cout << max - min << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insertTail(head, tail, val);
    }

    if (head != NULL) {
        printDifference(head);
    } else {
        cout << "0" << endl;
    }

    return 0;
}
