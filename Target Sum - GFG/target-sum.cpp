//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

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
int countPartitions(int n, int d, vector<int> &arr) {
    int totaSum = 0;
    for(int i = 0; i < n; i++){
        totaSum += arr[i];
    }
    if(totaSum-d < 0 || (totaSum-d) % 2 == 1) return false;
        return findWays(arr,(totaSum-d)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends