#include <iostream>
using namespace std;

// Definition of a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        this->data = val;
        this->prev = NULL;
        this->next =  NULL;
    }
};

void insertAtIndex(Node*& head, Node*& tail, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Invalid" << endl;
        return;
    }

    Node* newNode = new Node(value);

    if (index == 0) {
        if (head == NULL) {
            head =newNode;
             tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    } else if (index == size) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    ++size;
    printList(head, tail);
}


void printList(Node* head, Node* tail) {
    
    cout << "L -> ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "R -> ";
    current = tail;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;
        insertAtIndex(head, tail, size, X, V);
    }

    return 0;
}
