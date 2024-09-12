//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
       std::set<int> distinctElements(arr.begin(), arr.end());

    // If the set has fewer than 2 elements, return -1
    if (distinctElements.size() < 2) {
        return -1;
    }

    // Get the second largest element by iterating backwards through the set
    auto it = distinctElements.rbegin();
    ++it;  // Move to the second largest element

    return *it; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends