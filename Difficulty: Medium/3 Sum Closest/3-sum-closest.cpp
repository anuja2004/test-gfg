//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mindiff=INT_MAX;
        int closestsum=INT_MIN;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                
                int diff=abs(sum-target);
                if(diff<mindiff || (diff==mindiff && sum>closestsum)){
                    mindiff=diff;
                    closestsum=sum;
                }
                
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return closestsum;
        
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
        getline(cin, input);
        int target = stoi(input);

        Solution obj;
        cout << obj.closest3Sum(arr, target) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends