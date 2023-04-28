//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= +1; dj1++){
        for(int dj2 = -1; dj2 <= +1; dj2++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1]+grid[i][j2];
            value += helper(i+1, dj1+j1, dj2+j2, r, c, grid,dp);
            maxi = max(value, maxi);
        }
    }
    dp[i][j1][j2] =  maxi;
    return maxi;
}
  public:
    int solve(int r, int c, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));
    return helper(0,0,c-1,r,c,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends