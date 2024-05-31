#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    auto pos = s.find("EGYPT");
    while (pos != string::npos) {
        s.replace(pos, 5, " "); // 5 is the length of "EGYPT"
        pos = s.find("EGYPT", pos + 1);
    }

    cout << s << endl;

    return 0;
}
