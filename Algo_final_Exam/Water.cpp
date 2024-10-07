#include <iostream>
#include <vector>
using namespace std;

pair<int, int> maxWaterContainer(const vector<int>& heights, int N) {
    int left = 0, right = N - 1; // Initialize two pointers
    int maxArea = 0;
    pair<int, int> result;

    while (left < right) {
        // Calculate height and width
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int area = height * width;

        // Update maxArea and result if we found a new max
        if (area > maxArea) {
            maxArea = area;
            result = {left, right}; // Store the indices
        }

        // Move the pointer of the shorter line towards the center
        if (heights[left] < heights[right]) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Number of lines
        vector<int> heights(N);
        
        // Input the heights
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        // Find the result for this test case
        pair<int, int> result = maxWaterContainer(heights, N);
        cout << result.first << " " << result.second << endl; // Output the result
    }

    return 0;
}
