//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int start, vector<bool> &visited, vector<vector<int>>& adj, stack<int> &st)
    {
        visited[start] = true;
        for(auto it: adj[start])
        {
            if(!visited[it])
            {
                dfs(it, visited, adj, st);
            }
        }
        st.push(start);
    }
    
    void dfsTraversal(int start, vector<bool> &visited, vector<int> adjT[])
    {
        visited[start] = true;
        for(auto it : adjT[start])
        {
            if(!visited[it])
            {
                dfsTraversal(it, visited, adjT);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step-1 (Sort the vertices according to the finish time and stored them in a stack)
        stack<int> st;
        vector<bool> visited(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                dfs(i,visited, adj, st);
            }
        }
        
        // Step-2 (Revese the graph)
        vector<int> adjT[V];
        for(int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for(auto it: adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        // Step-3 (Do a DFS Traversal)
        int count = 0;
        while(!st.empty())
        {
            int start = st.top();
            st.pop();
            if(!visited[start])
            {
                dfsTraversal(start, visited, adjT);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends