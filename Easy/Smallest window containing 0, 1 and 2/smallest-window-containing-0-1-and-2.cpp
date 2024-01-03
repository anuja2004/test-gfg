//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int n = s.length();
    int charCount[3] = {0};  // To store the count of each character ('0', '1', '2')
    int count = 0;  // To track the count of unique characters in the current window
    int left = 0, right = 0;  // Pointers for the sliding window
    int minLen = INT_MAX;  // Initialize the minimum length to a large value

    while (right < n) {
        if (charCount[s[right] - '0'] == 0) {
            count++;
        }
        charCount[s[right] - '0']++;

        // Move the left pointer to minimize the length
        while (count == 3) {
            minLen = min(minLen, right - left + 1);
            charCount[s[left] - '0']--;
            if (charCount[s[left] - '0'] == 0) {
                count--;
            }
            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? -1 : minLen;
    // return (minLen == INT_MAX) ? -1 : minLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends