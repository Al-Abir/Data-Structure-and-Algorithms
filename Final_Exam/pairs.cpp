#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cin >> n;

    map<string, vector<int>> data;

    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        data[s].push_back(x);
    }

    
    for (const auto& entry : data) {
        const string& str = entry.first;
        vector<int> nums = entry.second;
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int num : nums) {
            cout << str << " " << num << endl;
        }
    }

    return 0;
}

