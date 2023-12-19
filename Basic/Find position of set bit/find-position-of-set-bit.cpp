//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int c=0;
        while(N){
            if(N&1){
                c++;
            }
            N=N>>1;
        }
        return c;
    }
    int set(int n){
        int c=0;
        while(n){
            c++;
            if(n&1){
                return c;
            }
            n=n>>1;
        }
    }
    int findPosition(int N) {
        // code here
        if(setBits(N)==1){
            return set(N);
        }
        else{
            return -1;
        }
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
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends