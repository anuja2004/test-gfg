//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> map{
          {'I', 1},
          {'V', 5},
          {'X', 10},
          {'L', 50},
          {'C', 100},
          {'D', 500},
          {'M', 1000}
        };
        int pval=0;
         int cval=0;
         int ans=0;
        for(int i=str.size()-1;i>=0;i--){
            cval=map[str[i]];
            if(cval<pval){
                ans-=cval;
            }
            else{
                ans+=cval;
            }
            pval=cval;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends