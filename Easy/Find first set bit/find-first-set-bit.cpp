//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        vector<int> ans;
        while(n!=0){
            int a=n%2;
            ans.push_back(a);
            n=n/2;
        }
        // reverse(ans.begin(), ans.end());
        int b=ans.size();
        
        for(int i=0;i<b;i++){
            if(ans[i]==1){
                return i+1;
            }
        }
        return 0;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends