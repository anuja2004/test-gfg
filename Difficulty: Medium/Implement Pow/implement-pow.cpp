//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
         double result = 1.0;
        int absExponent = std::abs(e);
    
        while (absExponent > 0) {
            if (absExponent % 2 == 1) {
                result *= b;
            }
            b *= b;
            absExponent /= 2;
        }
    
        // If the exponent is negative, take the reciprocal
        if (e < 0) {
            result = 1.0 / result;
        }
    
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends