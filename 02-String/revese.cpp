#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "I love you";
    cout << a << endl;
    
    for (int  i = a.size() - 1; i >= 0; i--) {
           cout<<a[i];
    }
    
    return 0;
}
