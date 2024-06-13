//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int num){
        // code here
        int n=num;
        int sum=0,a=0;
        while(num>0){
            a=num%10;
            sum+=pow(a,3);
            num=num/10;
        }
        if(n==sum){
            return "Yes";
        }
        else{
            return "No";
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends