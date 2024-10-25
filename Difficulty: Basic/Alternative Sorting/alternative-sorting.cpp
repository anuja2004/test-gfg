//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        // int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> result(arr.size());

        int start = 0;               // Pointer to the smallest element
        int end = arr.size() - 1;     // Pointer to the largest element
        bool flag = true;             // Flag to alternate between max and min
    
        // Iterate over the array and rearrange
        for (int i = 0; i < arr.size(); i++) {
            if (flag) {
                result[i] = arr[end--];  
            } else {
                result[i] = arr[start++]; 
            }
            flag = !flag; 
        }
    
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends