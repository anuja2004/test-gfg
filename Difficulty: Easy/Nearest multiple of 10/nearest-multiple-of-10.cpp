//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n=str.length();
        int last=str[n-1]-'0';
        if(last<=5){
            str[n-1]='0';
            return str;
        }
        str[n-1]='0';
        for(int i=n-2;i>=0;i--){
            if(str[i]=='9'){
                str[i]='0';
            }
            else{
                str[i]++;
                return str;
            }
        }
        return '1'+str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends