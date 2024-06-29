#include <iostream>
using namespace std;

int top = -1;

void push(int stack[], int n, int data) {
    if (top == n - 1) {
        cout << "Stack is full" << endl;
    } else {
        top++;
        stack[top] = data;
    }
}

void pop(int stack[], int n) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
}

void display(int stack[], int n, int top) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;
    int stack[n];

    push(stack, n, 10);
    push(stack, n, 20);
    
    cout << "Stack after pushing elements:" << endl;
    display(stack, n, top);

    pop(stack, n);
    
    cout << "Stack after popping an element:" << endl;
    display(stack, n, top);

    return 0;
}
