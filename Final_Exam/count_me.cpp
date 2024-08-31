#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        istringstream ss(s);
        string word;
        map<string, int> count;
        int max = 0;
        string frq;
        while (ss >> word)
        {
            count[word]++;
            if (count[word] > max)
            {
                max = count[word];
                frq = word;
            }
        }
        cout << frq << " " << max << endl;
        ;
    }

    return 0;
}