//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> st;
        int n=S.length();
        string word;
        stringstream ss(S);
        while(getline(ss,word,'.')){
            st.push_back(word);
        }
        reverse(st.begin(),st.end());
        
        string rs=st[0];
        for(int i=1;i<st.size();i++){
            rs+='.'+st[i];
        }
        return rs;
    } 
};


//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends