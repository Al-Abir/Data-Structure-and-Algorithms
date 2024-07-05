#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    class Node {
    public:
        string data;
        Node* prev;
        Node* next;

        Node(const string& val){
            this->data =val;
            this->prev =NULL;
            this->next =NULL;
        }
    };

    Node* head;
    Node* current;

public:
    BrowserHistory() {
          head = NULL;
          current = NULL;

    }

    void visit(const string& url) {
        Node* newNode = new Node(url);
        if (!head) {
            head = current = newNode;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    void next() {
        if (current && current->next) {
            current = current->next;
            cout << current->data << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void prev() {
        if (current && current->prev) {
            current = current->prev;
            cout << current->data << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void visitAddress(const string& url) {
        Node* temp = head;
        while (temp) {
            if (temp->data == url) {
                current = temp;
                cout << current->data << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Available" << endl;
    }
};

int main() {
    string input;
    BrowserHistory history;

  
    while (cin >> input && input != "end") {
        history.visit(input);
    }

    int Q;
    cin >> Q;
    cin.ignore(); 
    while (Q--) {
        string command, address;
        getline(cin, command);

        if (command.substr(0, 5) == "visit") {
            address = command.substr(6);
            history.visitAddress(address);
        } else if (command == "next") {
            history.next();
        } else if (command == "prev") {
            history.prev();
        }
    }

    return 0;
}
