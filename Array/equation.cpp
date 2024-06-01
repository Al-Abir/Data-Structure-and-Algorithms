#include <iostream>
using namespace std;

long long int Result(int X, int N) {
    long long int  result = 0;
    long long int  current = 1;
    for (int i = 2; i <= N; i += 2) {
        current = 1; // reset current for each new i
        for (int j = 0; j < i; j++) {
            current *= X;
        }
        result += current;
    }
    return result;
}

int main() {
    long long int  x, n;
    cin >> x >> n;
 
  long long int S = Result(x, n);
    cout << S << endl;
 
    return 0;
}
