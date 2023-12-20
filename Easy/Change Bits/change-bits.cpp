//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int set(int n){
        int c=0;
        while(n){
            if(!(n&1)){
                c++;
            }
            n=n>>1;
        }
        return c;
    }
    int set1(int n){
        int c=0;
        while(n){
            if((n&1)){
                c++;
            }
            n=n>>1;
        }
        return c;
    }
    vector<int> changeBits(int N) {
        // code here
        vector<int> v;
        int a=set(N)+set1(N);
        int b=pow(2,a)-1;
        v.push_back(abs(N-b));
        v.push_back(b);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends