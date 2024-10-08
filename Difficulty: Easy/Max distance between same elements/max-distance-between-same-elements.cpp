//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n=arr.size();
        // int dist=0;
        int maxi=0;
        //---brute force----//
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]==arr[j]){
        //             dist=j-i;
        //             maxi=max(maxi,dist);
        //         }
        //     }
        // }
        //---optimized-----//
        //we will store the first occurence of an element nad will find the equal elemtn.
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                int dist=i-mp[arr[i]];
                maxi=max(maxi,dist);
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends