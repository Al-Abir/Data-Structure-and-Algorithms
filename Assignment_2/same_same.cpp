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

bool ListsEqual(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1 == NULL && temp2 == NULL;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int val;


    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insertAtTail(head1, tail1, val);
    }
    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insertAtTail(head2, tail2, val);
    }
    if (ListsEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
