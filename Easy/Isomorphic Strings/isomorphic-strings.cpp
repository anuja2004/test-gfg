//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
       if(str1.length()!=str2.length()){
           return false;
       }
       map<char,char> mp;
       set<char> up;
       for(int i=0;i<str1.length();i++){
           char c1=str1[i];
           char c2=str2[i];
           
           if(mp.find(c1)!=mp.end()){
               if(mp[c1]!=c2){
                   return false;
               }
           }
           else{
               if(up.find(c2)!=up.end()){
                   return false;
               }
               mp[c1]=c2;
               up.insert(c2);
           }
       }
       return true;
       
        
    }
};


//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends