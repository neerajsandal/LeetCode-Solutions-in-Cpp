//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(string str1, string str2)
	{
	    int n = str1.size();
	    int m = str2.size();
	    
	    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= m; j++)
	        {
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    return dp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int k = lcs(str1, str2);
	    int deletions = str1.size()-k;
	    int insertions = str2.size()-k;
	    return insertions + deletions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends