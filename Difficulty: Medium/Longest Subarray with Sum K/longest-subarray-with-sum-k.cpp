//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //     if(sum==k){
        //         ans=max(ans,(j-i+1));
        //     }
        //     }
        // }
        // return ans;
        
        
        //hasing 
        int maxi=0;
        int sum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxi=max(maxi,i+1);
            }
            
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                int len=i-mp[rem];
                maxi=max(maxi,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxi;
        
        //2-pointer approch
        // int left=0,right=0;
        // int maxi=0;
        // int sum=0;
        // while(right<n){
        //     while(left<=right && sum>k){
        //         sum-=arr[left];
        //         left++;
        //     }
        //     if(sum==k){
        //         maxi=max(maxi,(right-left+1));
        //     }
        //     right++;
        //     if(right<n){
                
        //         sum+=arr[right];
        //     }
        // }
        // return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends