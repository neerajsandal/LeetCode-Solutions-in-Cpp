//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int helper(int coins[], int i, int V, vector<vector<int>> &dp)
	{
	    if(i == 0){
	        if(V%coins[i] == 0) return V/coins[i];
	        else return 1e9;
	    }
	    if(dp[i][V] != -1) return dp[i][V];
	    int notake = helper(coins, i-1, V, dp);
	    int take = 1e9;
	    if(V - coins[i] >= 0){
	        take = 1 + helper(coins, i, V-coins[i], dp);
	    }
	    return dp[i][V] = min(take, notake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M, vector<int>(V+1, -1));
	    int ans = helper(coins, M-1, V, dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends