//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int helper(int n, vector<int> &dp)
	    {
	        if(n == 0) return 1;
	        if(n < 0) return 0;
	        if(dp[n] != -1) return dp[n];
	        int r = helper(n-2, dp);
	        dp[n] = 1 + r;
	        return dp[n];
	    }
		int nthStair(int n){
            vector<int> dp(n+1, -1);
            return helper(n, dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends