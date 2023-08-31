//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void helper(vector<int>& arr, vector<int>& ans, int ind, int N, int sum)
    {
        if(ind == N){
            ans.push_back(sum);
            return;
        }
        
        helper(arr, ans, ind+1, N, sum);
        helper(arr, ans, ind+1, N, sum + arr[ind]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(arr, ans,0, N, 0);
        sort(ans.begin(), ans.end());
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends