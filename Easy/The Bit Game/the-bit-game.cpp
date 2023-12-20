//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int set(long long n){
        int c=0;
        while(n){
            if(n&1){
                c++;
            }
            n=n>>1;
        }
        return c;
    }
    int swapBitGame(long long N){
        // code here 
        int a=set(N);
        if(a%2==0){
            return 2;
        }
        else{
            return 1;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends