//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
    //Your code here
    int ans=0;
    int mul=1;
    while(n>0){
        int d=n%10;
        if(d==0){
            ans+=5*mul;
        }
        else{
            ans+=d*mul;
        }
        n/=10;
        mul*=10;
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends