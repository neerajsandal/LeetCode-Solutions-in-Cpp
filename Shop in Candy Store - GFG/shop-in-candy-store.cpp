//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        sort(candies, candies+N);
        
        int last = N-1;
        int i = 0;
        int mini = 0;
        while(i <= last)
        {
            mini += candies[i];
            last -= k;
            i++;
        }
        
        int maxi = 0;
        int start = 0;
        i = N-1;
        while(i >= start)
        {
            maxi += candies[i];
            start += k;
            i--;
        }
        
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends