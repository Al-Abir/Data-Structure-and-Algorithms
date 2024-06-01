#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n
    for (int i = 0; i < n; i++)
    {
        string s, x;
        getline(cin, s); // Read the entire line
        cin >> x;
        int pos = s.find(x); // Fix typo: remove extra '='

        while (pos != -1) // Fix typo: remove extra '('
        {
            s.replace(pos, x.size(), "#"); // Fix syntax error: remove extra ','
            pos = s.find(x, pos + 1); // Find the next occurrence after the last replacement
        }

        cout << s << endl;
    }

    return 0;
}