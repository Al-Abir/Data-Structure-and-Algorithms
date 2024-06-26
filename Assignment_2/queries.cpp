#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node*& head, int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node*& head, int v) {
    Node* newNode = new Node(v);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void delete_from_position(Node*& head, int pos) {
    if (head == NULL) return;
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* tmp = head;
    for (int i = 0; tmp != NULL && i < pos - 1; i++) {
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL) return;
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}


void print_linked_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < t; i++) {
        int op, data;
        cin >> op >> data;
        if (op == 0) {
            insert_at_head(head, data);
            print_linked_list(head);
        } else if (op == 1) {
            insert_at_tail(head, data);
             print_linked_list(head);
        } else if (op == 2) {
             delete_from_position(head, data);
             print_linked_list(head);
        }
       
    }
    return 0;
}
