//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
         pair<int, int> price_day[n];

    for (int i = 0; i < n; ++i) {
        price_day[i] = make_pair(price[i], i);
    }

    sort(price_day, price_day + n);

    int stocks = 0;
    for (int i = 0; i < n; ++i) {
        int price = price_day[i].first;
        int day = price_day[i].second;

        if (price * (day + 1) <= k) {
            stocks += day + 1;
            k -= price * (day + 1);
        } else {
            stocks += k / price;
            k %= price;
        }
    }

    return stocks;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends