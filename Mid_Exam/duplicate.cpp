#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    list<int> l1;
    int value;

    while (cin >> value && value != -1) {
        l1.push_back(value);
    }

   
    l1.sort();

    l1.unique();

    for (int v : l1) {
        cout << v << " ";
    }
     cout <<endl;

    return 0;
}
