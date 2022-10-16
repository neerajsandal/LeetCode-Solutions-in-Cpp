//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        long long int dp[h+1];
        dp[0] = 1;
        dp[1] = 1;
        
        /* for a given height 'h';
        three cases are possible 
        1. (h-1)*(h-1)
        2. (h-1)*(h-2)
        3. (h-2)*(h-1)
        
        so that the difference between left and right subtree is not greater than 1;
        */
        
        /* so three cases are like 
         (h-1) * (h-1)
         i.e. we are multiplying the no. of balanced left subtrees with 
         balanced right subtrees 
         
         the reason is same when we are throwing two dices simultaneously
         the value of one left-subtree with all right subtree
         so we are here multiplying it;
         */
         
         
        for(int i = 2; i <= h; i++){
            int x = (dp[i-1] * dp[i-1])%(1000000007);
            int y = (2 * dp[i-2] * dp[i-1])%(1000000007);
            
            dp[i] = (x + y)%(1000000007);
        }
        return dp[h];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends