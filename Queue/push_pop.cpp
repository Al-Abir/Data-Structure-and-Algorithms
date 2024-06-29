#include <iostream>
using namespace std;

// Global variable declarations
int queue[5], n = 5, front = -1, rear = -1;

void insert() {
    if (rear == n - 1) {
        cout << "Queue is full" << endl;
    } else {
        int x;
        cout << "Enter value to insert: ";
        cin >> x;
        
        if (front == -1) {
            front = 0;
        }
        
        rear++;
        queue[rear] = x;
    }
}

void del() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Element deleted from queue is: " << queue[front] << endl;
        front++;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    insert();
    insert();
    display();
    del();
    display();
    return 0;
}
/*
#include <iostream>
using namespace std;

void insert(int queue[], int& front, int& rear, int n) {
    if (rear == n - 1) {
        cout << "Queue is full" << endl;
    } else {
        int x;
        cout << "Enter value to insert: ";
        cin >> x;
        
        if (front == -1) {
            front = 0;
        }
        
        rear++;
        queue[rear] = x;
    }
}

void del(int queue[], int& front, int rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Element deleted from queue is: " << queue[front] << endl;
        front++;
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    int queue[n];
    int front = -1, rear = -1;
    
    insert(queue, front, rear, n);
    insert(queue, front, rear, n);
    display(queue, front, rear);
    del(queue, front, rear);
    display(queue, front, rear);
    
    return 0;
}
*/