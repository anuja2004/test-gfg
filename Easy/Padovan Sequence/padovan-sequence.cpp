//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       const int MOD = 1e9 + 7;
       vector<int> p(n+1);
       if(n==0 || n==1 || n==2){
           return 1;
       }
       p[0]=p[1]=p[2]=1;
       for(int i=3;i<=n;i++){
           p[i]=(p[i-2]+p[i-3])%MOD;
       }
       return p[n];
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends