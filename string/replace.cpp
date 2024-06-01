#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    size_t h = s.find("EGYPT");
    while (h != string::npos) {
        s.replace(h, 5, " "); // 5 is the length of "EGYPT"
        h = s.find("EGYPT", h + 1);
    }

    cout << s << endl;

    return 0;
}
