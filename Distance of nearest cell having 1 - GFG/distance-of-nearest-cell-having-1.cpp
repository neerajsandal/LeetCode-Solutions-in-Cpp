//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> distance(n, vector<int>(m, 0));
	    vector<vector<bool>> visited(n, vector<bool>(m, false));
	    
	    // ((row, col), dis);
	    queue<pair<pair<int, int>, int>> q;
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j}, 0}); // Initially 
	                visited[i][j] = true;
	            }
	        }
	    }
	    
	    // bfs traversal
	    while(!q.empty())
	    {
	        auto temp = q.front();
	        int row = temp.first.first;
	        int col = temp.first.second;
	        int dist = temp.second;
	        q.pop();
	        
	        // this is for the four directions {left, right, top, bottom}
	        int delrow[] = {-1,0,1,0};
	        int delcol[] = {0,-1,0,1};
	        
	        for(int i = 0; i < 4; i++)
	        {
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
	            {
	                q.push({{nrow, ncol}, dist+1});
	                distance[nrow][ncol] = dist+1;
	                visited[nrow][ncol] = true;
	            }
	        }
	    }
	    return distance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends