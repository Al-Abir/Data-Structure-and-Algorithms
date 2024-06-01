#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);  // Read the entire input line

    stringstream ss;
    ss << s;  // Load the input string into a stringstream
    string word;
    bool first = true;  // Initialize the flag to true
    while (ss >> word)  // Extract each word from the stringstream
    {
        if (!first)  // Check if this is not the first word
        {
            cout << " ";  // Print a space before the current word
        }
        first = false;  // Set the flag to false after the first word

        int n = word.length();  // Get the length of the current word
        for (int i = 0; i < n / 2; i++)  // Reverse the word in place
        {
            swap(word[i], word[n - i - 1]);
        }
        cout << word;  // Print the reversed word
    }

            
         //   reverse(word.begin(),word.end());
         // for(int i = n-1; i>=0; i--){
         //     cout<<word[i];
         // } 

    return 0;
}
