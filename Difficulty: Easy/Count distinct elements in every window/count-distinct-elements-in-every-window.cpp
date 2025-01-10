//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n=arr.size();
        vector<int> ans;
        map<int,int> vk;
        
        for(int i=0;i<k;i++){
            vk[arr[i]]++;
        }
        ans.push_back(vk.size());
        
        for(int i=k;i<n;i++){
            
            vk[arr[i-k]]--;
            if(vk[arr[i-k]]==0){
                vk.erase(arr[i-k]);
            }
            
            vk[arr[i]]++;
            ans.push_back(vk.size());
        }
        return ans;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends