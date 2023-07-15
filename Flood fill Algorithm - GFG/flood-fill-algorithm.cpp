//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // {{row,col}, color}
        queue<pair<pair<int,int>, int>> q;
        int color = image[sr][sc];
        q.push({{sr, sc}, color});
        visited[sr][sc] = true;
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int color = q.front().second;
            q.pop();
            image[row][col] = newColor;
            
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, -1, 0, 1};
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && image[nrow][ncol] == color)
                {
                    visited[nrow][col] = true;
                    q.push({{nrow, ncol}, color});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends