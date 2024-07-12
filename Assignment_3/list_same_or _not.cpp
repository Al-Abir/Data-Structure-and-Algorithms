#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> s1;
    list<int> q1;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        s1.push_back(value);
    }

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        q1.push_back(value);
    }

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }
    bool isSame = true;
    while (!s1.empty() && !q1.empty()) {
        if (s1.back() != q1.front()) {
            isSame = false;
            break;
        }
        s1.pop_back();
        q1.pop_front();
    }

    if(isSame)
   {    
     cout<<"YES\n";
   } else{
    cout<<"NO\n";
   }   
   
   
   return 0;
}
