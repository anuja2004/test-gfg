//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here

    sort(A.begin(), A.end());  // Sort A in non-increasing order
    sort(B.begin(), B.end());  // Sort B in non-increasing order

    vector<int> ans;
    priority_queue<pair<int,int>>PQ;
    for(int i=0;i<N;i++){
        int sum=A[i]+B[N-1];
        PQ.push({sum,N-1});
    }
    while(!PQ.empty() and K--){
        int S=PQ.top().first;
        int Idx=PQ.top().second;
        PQ.pop();
        ans.push_back(S);
        if(Idx-1>=0){
            PQ.push({S-B[Idx]+B[Idx-1],Idx-1});
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends