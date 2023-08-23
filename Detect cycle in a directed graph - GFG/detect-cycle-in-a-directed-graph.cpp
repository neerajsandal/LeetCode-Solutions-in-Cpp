//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detect(int start, bool visited[], bool dfsvisit[],vector<int> adj[])
    {
        visited[start] = true;
        dfsvisit[start] = true;
        for(auto it : adj[start])
        {
            if(!visited[it])
            {
                if(detect(it, visited, dfsvisit, adj))
                    return true;
            }
            else if(dfsvisit[it])
            {
                return true;
            }
        }
        dfsvisit[start] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V] = {false};
        bool dfsvisit[V] = {false};
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(detect(i, visited, dfsvisit, adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends