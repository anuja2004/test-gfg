//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int set(int m){
        int c=0;
        while(m){
            c++;
            if(m&1){
                return c;
            }
            m=m>>1;
        }
    }
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m==n){
            return -1;
        }
        else{
            
        return set(m^n);
        }
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends