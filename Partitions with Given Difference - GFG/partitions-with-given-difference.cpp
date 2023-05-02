//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
  int findWays(vector<int> &num, int k){
     int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    if(num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(num[0] != 0 && num[0]<=k) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken) % mod;
        }
    }
    
    return dp[n-1][k];
    
}
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += arr[i];
        }
        
        // base cases
        if(totalSum-d < 0 || (totalSum-d) % 2 == 1) return false;
        return findWays(arr, (totalSum-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends