//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(int row, int col, string s, vector<vector<int>> &arr, vector<vector<bool>> &visited,vector<string> &ans, int n)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(s);
            return;
        }
        
        visited[row][col] = true;
        // down
        if(row+1 < n && !visited[row+1][col] && arr[row+1][col] == 1)
        helper(row+1, col, s+"D", arr, visited, ans, n);
        
        // left
        if(col-1 >= 0 && !visited[row][col-1] && arr[row][col-1] == 1)
        helper(row, col-1, s+"L", arr, visited, ans, n);
            
        // right    
        if(col+1 < n && !visited[row][col+1] && arr[row][col+1] == 1)
        helper(row, col+1, s+"R", arr, visited, ans, n);
        
        // up
        if(row-1 >= 0 && !visited[row-1][col] && arr[row-1][col] == 1)
        helper(row-1, col, s+"U", arr, visited, ans, n);
        
        visited[row][col] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s = "";
        if(m[0][0] == 0) return {"-1"};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        helper(0, 0, s, m, visited, ans, n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends