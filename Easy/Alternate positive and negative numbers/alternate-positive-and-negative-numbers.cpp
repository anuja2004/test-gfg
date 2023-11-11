//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	   
    if (n <= 1) {
        return; // No need to process if the array has 0 or 1 elements.
    }

    vector<int> positive, negative;
    
    // Separate positive and negative numbers into separate arrays.
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }
    
     int i = 0, j = 0, k = 0;
    
    // Merge positive and negative arrays alternately.
    while (i < positive.size() && j < negative.size()) {
        arr[k++] = positive[i++];
        arr[k++] = negative[j++];
    }

    // // If there are any remaining positive numbers, add them.
    while (i < positive.size()) {
        arr[k++] = positive[i++];
    }

    // If there are any remaining negative numbers, add them.
    while (j < negative.size()) {
        arr[k++] = negative[j++];
    }

	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends