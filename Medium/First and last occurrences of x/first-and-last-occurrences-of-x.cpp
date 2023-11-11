//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int lowerbound(int arr[], int n , int x){
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
        int mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperbound(int arr[], int n , int x){
        int low=0,high=n-1;
        int ans1=-1;
        while(low<=high){
        int mid=(low+high)/2;
            if(arr[mid]>x){
                ans1=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans1;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>res;
         int lb=lowerbound(arr,n,x);
         int ub=upperbound(arr,n,x);
         if(lb==n || arr[lb]!=x){
         res.push_back(-1);
        res.push_back(-1);
        return res;
    }
     else if(lb==n-1 && ub==-1){
         res.push_back(lb);
        res.push_back(lb);
      return res;
         
     }
    else if(ub==-1) {
        res.push_back(lb);
        res.push_back(n-1);
        return res;
    }
    else{
        res.push_back(lb);
        res.push_back(ub-1);
        return res;
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
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends