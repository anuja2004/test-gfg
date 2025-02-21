//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& x) {
        // code here
        stack<char> st;
        for(char ch:x){
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else if(ch==')' || ch==']' || ch=='}'){
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if((ch==')' && top!='(') || (ch==']' && top!='[') || (ch=='}' && top!='{')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends