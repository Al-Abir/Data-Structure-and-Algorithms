#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAttail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void inseratPosition(Node*& head, Node*& tail, int pos, int data) {
    if (head == NULL || pos == 1) {  // If list is empty or inserting at the head
        insertathead(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {  // If position is out of bounds, insert at the tail
        insertAttail(head, tail, data);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {  // Update tail if newNode is inserted at the end
            tail = newNode;
        }
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val, pos;
    while (true) {
        cin >> val >> pos;

        if (val == -1) {
            break;
        }

        inseratPosition(head, tail, pos, val);
    }

    print(head);

    return 0;
}
