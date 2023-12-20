//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	for (int i = 0; i < 32; i += 2) {
        // Get the bit at position i
        unsigned int oddBit = (n >> i) & 1;

        // Get the bit at position i+1
        unsigned int evenBit = (n >> (i + 1)) & 1;

        // If adjacent bits are different, swap them
        if (oddBit != evenBit) {
            // XOR to swap bits: Toggle odd and even bits
            n ^= (1 << i);      // Toggle odd bit
            n ^= (1 << (i + 1)); // Toggle even bit
        }
    }
    return n;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends