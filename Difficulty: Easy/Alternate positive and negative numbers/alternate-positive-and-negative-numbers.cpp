//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> po,ne;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                po.push_back(arr[i]);
            }
            else{
                ne.push_back(arr[i]);
            }
        }
        int i=0,j=0,k=0;
        while(i<po.size() && j<ne.size()){
            arr[k++]=po[i++];
            arr[k++]=ne[j++];
        }
        while(i<po.size()){
            arr[k++]=po[i++];
        }
        while(j<ne.size()){
            arr[k++]=ne[j++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends