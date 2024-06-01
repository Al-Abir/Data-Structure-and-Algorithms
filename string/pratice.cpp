#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string word;
    string target_word;
    cin >> target_word;

    stringstream ss(s);

    int cnt = 0;
    while (ss >> word) {
        if (word == target_word) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
