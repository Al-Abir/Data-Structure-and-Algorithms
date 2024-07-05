#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
         this->data = data;
          this->next = NULL;
          this->prev =NULL;
    }
};
void insertathead(Node*&head, Node* &tail, int value){
        
        Node* newNode = new Node(value);
        if (head==NULL) {
            head =  newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
}


bool isPalindrome(Node* head, Node* tail) {
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int value;


    while (cin >> value && value != -1) {
           insertathead(head, tail, value);
    }

    if (isPalindrome(head, tail)) {
         cout << "YES" << endl;
    } else {
         cout << "NO" <<endl;
    }

 

    return 0;
}
