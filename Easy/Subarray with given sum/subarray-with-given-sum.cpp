//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> v;
        int left=0,right=0;
        int currentsum=0;
        while(right<arr.size()){
            currentsum+=arr[right];
            while(currentsum>s){
                currentsum-=arr[left];
                left++;
            }
            if(currentsum==s && s!=0){
                v.push_back(left+1);
                v.push_back(right+1);
                return v;
                
            }
            else if(s==0){
                return vector<int> {-1};
            }
            right++;
        }
        return vector<int> {-1};
        
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends