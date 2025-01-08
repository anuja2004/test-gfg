//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n < 3) return 0; // Less than 3 elements cannot form a triangle

    // Sort the array
    sort(arr.begin(), arr.end());

    int count = 0;

    // Fix the largest side
    for (int i = n - 1; i >= 2; i--) {
        int left = 0, right = i - 1;

        // Check pairs from left and right for the fixed largest side
        while (left < right) {
            if (arr[left] + arr[right] > arr[i]) {
                // If the sum of two sides is greater than the third side,
                // all pairs between left and right can form triangles.
                count += (right - left);

                // Move the right pointer to check other possibilities
                right--;
            } else {
                // If the sum is not greater, move the left pointer
                left++;
            }
        }
    }

    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends