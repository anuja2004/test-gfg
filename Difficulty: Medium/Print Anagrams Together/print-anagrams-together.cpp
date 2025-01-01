//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
         unordered_map<string, vector<string>> anagramMap;
    vector<string> sortedKeys;

    // Step 1: Group strings by their sorted version
    for (const string& str : arr) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end()); // Sort the string
        if (anagramMap.find(sortedStr) == anagramMap.end()) {
            sortedKeys.push_back(sortedStr); // Maintain insertion order
        }
        anagramMap[sortedStr].push_back(str);
    }

    // Step 2: Collect groups in the order of their first appearance
    vector<vector<string>> result;
    for (const string& key : sortedKeys) {
        vector<string> group = anagramMap[key];

        // Preserve the order of appearance in the input array
        result.push_back(group);
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends