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

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void remove_duplicate_values(Node* head) {
    if (head == NULL) return;

    Node* cur = head;

    while (cur != NULL) {
        Node* prev = cur;
        while (prev->next != NULL) {
            if (prev->next->data == cur->data) {
                Node* temp = prev->next;
                prev->next = prev->next->next;
                delete temp;
            } else {
                 prev = prev->next;
            }
        }
        cur = cur->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
        insertAtTail(head, tail, val);
    }
    remove_duplicate_values(head);
    printList(head);

    return 0;
}
