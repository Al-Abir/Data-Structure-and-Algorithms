#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){

        int n; // length of the string
        cin >> n;
        string s;
        cin >> s;

        int balloons = 0;
        bool first_solved[26] = {false}; // to track if a problem has been solved for the first time

        for (int i = 0; i < n; i++) {
            // not quals means the kew slove koreni ==0 same
            if (!first_solved[s[i] - 'A']) {
                // first time solving this problem
                balloons += 2;
                first_solved[s[i] - 'A'] = true;
            } else {
                // already solved this problem before
                balloons += 1;
            }
        }

        cout << balloons << endl;
    }
     
    return 0;
}